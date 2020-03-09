#include "corewar.h"

int		get_op_code(t_process *proc)
{
	proc->op = (int)(g_vm.arena[proc->pos]);
	if (proc->op < 1 || proc->op > 16)
	{
		proc->op = 17;
		proc->pc = 1;
	}
	else
		proc->delay = g_op_tab[proc->op - 1].op_delay;
	return (1);
}

void	intro(void)
{
	int		i;

	i = 0;
	ft_printf("%s\n", "Introducing contestants...");
	while (++i <= MAX_PLAYERS)
	{
		if (g_vm.players[i].id)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
					g_vm.players[i].id, g_vm.players[i].code_size,
					g_vm.players[i].name, g_vm.players[i].comment);
	}
}

int		ft_exec_op(t_process *proc)
{
	if (!g_op_tab[proc->op - 1].has_args_code)
	{
		proc->args[0] = g_op_tab[proc->op - 1].args_types[0];
		proc->pc += 1 + calc_args_size(0, proc);
	}
	else
		process_args_code(proc);
	parse_args_values(proc);
	if (!proc->op_error)
		if (check_regs(proc))
			if (!g_op_tab[proc->op - 1].operations(proc))
				return (0);
	return (1);
}

int		check_proc(void)
{
	t_process *proc;

	proc = g_vm.processes;
	while (proc)
	{
		if (!proc->delay)
			get_op_code(proc);
		proc->delay -= (proc->delay > 0) ? 1 : 0;
		if (!proc->delay)
		{
			if (proc->op > 0 && proc->op < 17)
				if (!ft_exec_op(proc))
					return (0);
			if (g_vm.log_level & PC && proc->pc > 1)
				if (proc->op != 9 || (proc->op == 9 && !proc->carry))
					print_proc_movement(proc->pos, proc->pc);
			proc->pos = position_correction(proc->pos + proc->pc);
			proc->pc = 0;
			proc->op_error = 0;
			ft_bzero((void*)proc->args, sizeof(int) * 4);
			ft_bzero((void*)proc->args_value, sizeof(int) * 3);
		}
		proc = proc->next;
	}
	return (1);
}

int		battle(void)
{
	while (g_vm.processes)
	{
		if (!g_vm.viz || (g_vm.viz && (g_vm.visu->is_next_cycle == 1
		|| g_vm.visu->is_stopped != 1)))
		{
			++g_vm.cycle_current;
			++g_vm.cycles_all;
			if (g_vm.log_level & CYCLE)
				ft_printf("It is now cycle %d\n", g_vm.cycles_all);
			if (!check_proc())
				return (0);
			if (g_vm.cycle_current == g_vm.cycles_to_die
			|| g_vm.cycles_to_die <= 0)
				battle_check();
			(g_vm.cycles_all == g_vm.dump_cycle) ? print_arena() : 0;
		}
		draw();
	}
	if (g_vm.viz & 1u)
		draw_winner(0, 0);
	else
		ft_printf("Contestant %d, \"%s\", has won !\n",
				g_vm.last_alive->id, g_vm.last_alive->name);
	return (1);
}
