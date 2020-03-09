#include "corewar.h"

int				get_int32_from_mem(int position, int correction)
{
	unsigned char buf[4];

	if (correction)
	{
		buf[3] = *(g_vm.arena + position_correction(position));
		buf[2] = *(g_vm.arena + position_correction(position + 1));
		buf[1] = *(g_vm.arena + position_correction(position + 2));
		buf[0] = *(g_vm.arena + position_correction(position + 3));
	}
	else
	{
		buf[3] = *(g_vm.arena + position);
		buf[2] = *(g_vm.arena + position + 1);
		buf[1] = *(g_vm.arena + position + 2);
		buf[0] = *(g_vm.arena + position + 3);
	}
	return (*((int*)buf));
}

int16_t			get_int16_from_mem(int position, int correction)
{
	unsigned char buf[2];

	if (correction)
	{
		buf[1] = *(g_vm.arena + position_correction(position));
		buf[0] = *(g_vm.arena + position_correction(position + 1));
	}
	else
	{
		buf[1] = *(g_vm.arena + position);
		buf[0] = *(g_vm.arena + position + 1);
	}
	return (*((int16_t*)buf));
}

unsigned int	get_arg_op(t_process *proc, int i)
{
	if (proc->args[i] == T_REG)
		return (proc->regs[proc->args_value[i] - 1]);
	else if (proc->args[i] == T_DIR)
		return (proc->args_value[i]);
	else if (proc->args[i] == T_IND)
		return (get_int32_from_mem(position_correction(proc->pos +
		proc->args_value[i] % IDX_MOD), 1));
	else
		return (-1);
}

int				position_correction(int position)
{
	position %= MEM_SIZE;
	position += (position < 0) ? MEM_SIZE : 0;
	return (position);
}
