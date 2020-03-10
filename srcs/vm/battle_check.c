#include "corewar.h"

void	update_cycle_to_die(void)
{
	g_vm.cycle_current = 0;
	++g_vm.cycles_to_die_not_updated;
	g_vm.cycles_to_die_last = g_vm.cycles_to_die;
	if (g_vm.lives_in_round >= NBR_LIVE ||
		g_vm.cycles_to_die_not_updated == MAX_CHECKS)
	{
		g_vm.cycles_to_die -= CYCLE_DELTA;
		g_vm.cycles_to_die_not_updated = 0;
	}
}

int		kill_all_procs(void)
{
	t_process *procs;
	t_process *next;

	procs = g_vm.processes;
	while (procs)
	{
		next = procs->next;
		del_process(procs);
		procs = next;
	}
	return (1);
}

void	check_procs(void)
{
	t_process *temp;
	t_process *next;

	temp = g_vm.processes;
	while (temp)
	{
		if (!temp->live_incycle)
		{
			next = temp->next;
			del_process(temp);
			temp = next;
		}
		else
		{
			temp->live_incycle = 0;
			temp = temp->next;
		}
	}
}

void	battle_check(void)
{
	++g_vm.checks;
	if (g_vm.cycles_to_die <= 0)
		kill_all_procs();
	update_cycle_to_die();
	check_procs();
	g_vm.lives_in_round = 0;
	if (g_vm.log_level & CYCLE && g_vm.cycles_to_die != g_vm.cycles_to_die_last)
		ft_printf("Cycle to die is now %d\n", g_vm.cycles_to_die);
}
