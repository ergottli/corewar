#include "../../incs/corewar.h"

int	live_op(t_process *proc)
{
	int				number;
	int				player_index;

	number = get_int32_from_mem(proc->pos + 1, 1);
	player_index = number * -1;
	++g_vm.lives_in_round;
	++proc->live_incycle;
	if (g_vm.log_level & OPERA)
		universal_op_log(proc, number, 0, 0);
	if (player_index > 0 && player_index <= g_vm.players_sum)
	{
		++g_vm.players[player_index].is_alive;
		++g_vm.players[player_index].lives_all;
		g_vm.players[player_index].lives_last = g_vm.cycles_all;
		++g_vm.players[player_index].lives_current;
		g_vm.last_alive = &g_vm.players[player_index];
		if (g_vm.log_level & LIVE)
			ft_printf("Player %d (%s) is said to be alive\n",
					abs_num(number), g_vm.players[proc->player_id].name);
	}
	return (1);
}

int	zjmp_op(t_process *proc)
{
	int	addr;

	addr = get_int16_from_mem(proc->pos + 1, 1);
	if (proc->carry == 1)
		proc->pc = addr % IDX_MOD;
	if (g_vm.log_level & OPERA)
	{
		ft_printf("P %4d | zjmp %d %s\n",
				proc->proc_id,
				addr,
				(proc->carry) ? "OK" : "FAILED");
	}
	return (1);
}

int	ld_op(t_process *proc)
{
	proc->regs[proc->args_value[1] - 1] = (int)get_arg_op(proc, 0);
	proc->carry = proc->regs[proc->args_value[1] - 1] == 0 ? 1 : 0;
	if (g_vm.log_level & OPERA)
		universal_op_log(proc, proc->regs[proc->args_value[1] - 1],
				proc->args_value[1], proc->args_value[2]);
	return (1);
}

int	st_op(t_process *proc)
{
	int				i;
	unsigned char	*temp;

	i = -1;
	if (proc->args[1] == T_REG)
		proc->regs[proc->args_value[1] - 1] =
				proc->regs[proc->args_value[0] - 1];
	else if (proc->args[1] == T_IND)
	{
		temp = (unsigned char*)&proc->regs[proc->args_value[0] - 1];
		while (++i < REG_SIZE)
		{
			g_vm.arena[position_correction(position_correction(proc->pos +
			i + proc->args_value[1] % IDX_MOD))] = temp[3 - i];
			g_vm.arena_id[position_correction(position_correction(proc->pos +
			i + proc->args_value[1] % IDX_MOD))] = proc->player_id;
		}
	}
	if (g_vm.log_level & OPERA)
	{
		proc->args[1] = T_DIR;
		universal_op_log(proc, proc->args_value[0],
				proc->args_value[1], proc->args_value[2]);
	}
	return (1);
}

int	add_op(t_process *proc)
{
	proc->regs[proc->args_value[2] - 1] = proc->regs[proc->args_value[0] - 1] +
			proc->regs[proc->args_value[1] - 1];
	proc->carry = proc->regs[proc->args_value[2] - 1] == 0 ? 1 : 0;
	if (g_vm.log_level & OPERA)
		universal_op_log(proc, proc->args_value[0],
				proc->args_value[1], proc->args_value[2]);
	return (1);
}
