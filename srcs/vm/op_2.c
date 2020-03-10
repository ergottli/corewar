#include "../../incs/corewar.h"

int	sub_op(t_process *proc)
{
	int	res;

	res = proc->regs[proc->args_value[0] - 1] -
			proc->regs[proc->args_value[1] - 1];
	proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = res;
	if (g_vm.log_level & OPERA)
		universal_op_log(proc, proc->args_value[0],
				proc->args_value[1], proc->args_value[2]);
	return (1);
}

int	and_op(t_process *proc)
{
	unsigned int	val1;
	unsigned int	val2;

	val1 = get_arg_op(proc, 0);
	val2 = get_arg_op(proc, 1);
	proc->regs[proc->args_value[2] - 1] = (int)(val1 & val2);
	proc->carry = (proc->regs[proc->args_value[2] - 1] == 0) ? 1 : 0;
	if (g_vm.log_level & OPERA)
	{
		proc->args[0] = T_DIR;
		proc->args[1] = T_DIR;
		universal_op_log(proc, (int)val1, (int)val2, proc->args_value[2]);
	}
	return (1);
}

int	or_op(t_process *proc)
{
	unsigned int	val1;
	unsigned int	val2;

	val1 = get_arg_op(proc, 0);
	val2 = get_arg_op(proc, 1);
	proc->regs[proc->args_value[2] - 1] = (int)(val1 | val2);
	proc->carry = (proc->regs[proc->args_value[2] - 1] == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] =
			(int)proc->regs[proc->args_value[2] - 1];
	if (g_vm.log_level & OPERA)
	{
		proc->args[0] = T_DIR;
		proc->args[1] = T_DIR;
		universal_op_log(proc, (int)val1, (int)val2, proc->args_value[2]);
	}
	return (1);
}

int	xor_op(t_process *proc)
{
	unsigned int	res;
	unsigned int	first;
	unsigned int	second;

	first = get_arg_op(proc, 0);
	second = get_arg_op(proc, 1);
	res = first ^ second;
	proc->carry = (res == 0) ? 1 : 0;
	proc->regs[proc->args_value[2] - 1] = (int)res;
	if (g_vm.log_level & OPERA)
	{
		proc->args[0] = 2;
		proc->args[1] = 2;
		universal_op_log(proc, (int)first, (int)second, proc->args_value[2]);
	}
	return (1);
}
