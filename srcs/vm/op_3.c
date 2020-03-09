#include "../../incs/corewar.h"

int	ldi_op(t_process *proc)
{
	int	addr1;
	int	addr2;

	addr1 = (int)get_arg_op(proc, 0);
	addr2 = (int)get_arg_op(proc, 1);
	proc->regs[proc->args_value[2] - 1] = get_int32_from_mem(proc->pos +
			(addr1 + addr2) % IDX_MOD, 1);
	if (g_vm.log_level & OPERA)
	{
		proc->args[0] = T_DIR;
		proc->args[1] = T_DIR;
		universal_op_log(proc, addr1, addr2, proc->args_value[2]);
	}
	return (1);
}

int	sti_op(t_process *proc)
{
	int				addr;
	int				i;
	unsigned char	*temp;
	int				addr1;
	int				addr2;

	i = -1;
	addr1 = (int)get_arg_op(proc, 1);
	addr2 = (int)get_arg_op(proc, 2);
	temp = (unsigned char*)&proc->regs[proc->args_value[0] - 1];
	addr = position_correction(proc->pos + (addr1 + addr2) % IDX_MOD);
	while (++i < REG_SIZE)
	{
		g_vm.arena[position_correction(addr + i)] = temp[3 - i];
		g_vm.arena_id[position_correction(addr + i)] = proc->player_id;
	}
	if (g_vm.log_level & OPERA)
	{
		proc->args[1] = T_DIR;
		proc->args[2] = T_DIR;
		universal_op_log(proc, (int)proc->args_value[0], addr1, addr2);
	}
	return (1);
}

int	fork_op(t_process *proc)
{
	t_process	*new;
	int			addr;
	int			addr_correction;
	int			i;

	i = -1;
	addr = proc->pos + proc->args_value[0] % IDX_MOD;
	addr_correction = position_correction(addr);
	if (!(new = create_process(proc->player_id, addr_correction)))
		return (0);
	while (++i < REG_NUMBER)
		new->regs[i] = proc->regs[i];
	new->carry = proc->carry;
	new->live_incycle = proc->live_incycle;
	if (g_vm.log_level & OPERA)
		ft_printf("P%5d | fork %d (%d)\n", proc->proc_id,
				proc->args_value[0], addr);
	return (1);
}

int	lld_op(t_process *proc)
{
	if (proc->args[0] == T_DIR)
		proc->regs[proc->args_value[1] - 1] = proc->args_value[0];
	else
		proc->regs[proc->args_value[1] - 1] =
				get_int32_from_mem(proc->pos + proc->args_value[0], 1);
	if (!proc->regs[proc->args_value[1] - 1])
		proc->carry = 1;
	else
		proc->carry = 0;
	if (g_vm.log_level & OPERA)
		universal_op_log(proc, (int)get_arg_op(proc, 0),
				proc->args_value[1], 0);
	return (1);
}

int	lldi_op(t_process *proc)
{
	int	addr1;
	int	addr2;

	addr1 = (int)get_arg_op(proc, 0);
	addr2 = (int)get_arg_op(proc, 1);
	proc->regs[proc->args_value[2] - 1] =
			get_int32_from_mem(proc->pos + addr1 + addr2, 1);
	if (g_vm.log_level & OPERA)
	{
		proc->args[0] = T_DIR;
		proc->args[1] = T_DIR;
		universal_op_log(proc, addr1, addr2, proc->args_value[2]);
	}
	return (1);
}
