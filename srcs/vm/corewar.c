#include "corewar.h"
#include "visu.h"

int		init_players_struct(void)
{
	int i;

	i = -1;
	while (++i < MAX_PLAYERS)
	{
		g_vm.players_temp[i].id = 0;
		g_vm.players_temp[i].name[PROG_NAME_LENGTH] = '\0';
		g_vm.players_temp[i].comment[COMMENT_LENGTH] = '\0';
		g_vm.players_temp[i].code_size = 0;
		g_vm.players_temp[i].is_alive = 0;
		g_vm.players_temp[i].lives_all = 0;
		g_vm.players_temp[i].lives_last = 0;
		g_vm.players_temp[i].lives_current = 0;
	}
	return (1);
}

int		init_corewar(void)
{
	init_op_one();
	init_op_two();
	g_vm.process_count = 0;
	g_vm.proc_id_count = 0;
	g_vm.processes = NULL;
	g_vm.last_alive = NULL;
	g_vm.cycles_all = 0;
	g_vm.cycle_current = 0;
	g_vm.cycles_to_die = CYCLE_TO_DIE;
	g_vm.cycles_to_die_last = CYCLE_TO_DIE;
	g_vm.players_sum = 0;
	g_vm.log_level = 0;
	g_vm.dump = 0;
	g_vm.dump_cycle = -1;
	g_vm.dump_step = -1;
	g_vm.viz = 0;
	g_vm.s = 0;
	g_vm.af = 0;
	g_vm.checks = 0;
	ft_bzero(g_vm.arena, MEM_SIZE);
	ft_bzero(g_vm.arena_id, MEM_SIZE * sizeof(int));
	init_players_struct();
	return (1);
}

int		main(int argc, char **argv)
{
	if (argc <= 1)
		return (print_usage(0, 1));
	if (!init_corewar() || !check_args(argc, argv))
		return (0);
	if (!create_players(argv))
		return (0);
	if (!init_game())
		return (0);
	if (g_vm.viz & 1u)
		g_vm.visu = init_visu();
	else
		intro();
	if (!battle())
	{
		kill_all_procs();
		if (g_vm.viz & 1u)
			delete_visu(&(g_vm.visu));
		ft_putstr_fd("Malloc error\n", 2);
	}
	if (g_vm.viz & 1u)
		delete_visu(&(g_vm.visu));
	return (0);
}
