#include "corewar.h"

unsigned int	check_args_type(unsigned int arg_code,
		const int *arg_types, t_process *proc, int j)
{
	int	i;

	i = -1;
	proc->args[j] = arg_code;
	while (++i < 3)
	{
		if (j < g_op_tab[proc->op - 1].argc &&
		(int)arg_code == arg_types[i] && arg_code != 0)
			return (1);
		else if (arg_code == 0 && j >= g_op_tab[proc->op - 1].argc)
			return (1);
	}
	return (0);
}

int				calc_args_size(int i, t_process *proc)
{
	int	size;

	size = 0;
	size = (proc->args[i] == T_REG) ? 1 : size;
	size = (proc->args[i] == T_IND) ? 2 : size;
	size = (proc->args[i] == T_DIR) ? 4 /
			(g_op_tab[proc->op - 1].dir_size + 1) : size;
	return (size);
}

void			process_args_code(t_process *proc)
{
	int	i;

	i = -1;
	proc->pc += 2;
	while (++i < 4)
	{
		if (!check_args_type((*(g_vm.arena +
								position_correction((int)(proc->pos + 1u)))
		& (192u >> (unsigned)(i * 2))) >> (6u - (unsigned)(i * 2)),
				g_op_tab[proc->op - 1].args_types + i * 3, proc, i))
			proc->op_error = 1;
		if (i < g_op_tab[proc->op - 1].argc)
			proc->pc += calc_args_size(i, proc);
	}
}

int				parse_args_values(t_process *proc)
{
	int				i;
	int				offset;
	unsigned int	size;
	unsigned int	index;

	i = -1;
	offset = (g_op_tab[proc->op - 1].has_args_code) ? 2 : 1;
	while (++i < g_op_tab[proc->op - 1].argc)
	{
		size = calc_args_size(i, proc);
		index = position_correction(proc->pos + offset);
		proc->args_value[i] = (proc->args[i] == T_REG) ?
				(int)g_vm.arena[index] : proc->args_value[i];
		proc->args_value[i] = (proc->args[i] == T_IND) ?
				get_int16_from_mem((int)index, 0) : proc->args_value[i];
		proc->args_value[i] = (proc->args[i] == T_DIR &&
				g_op_tab[proc->op - 1].dir_size == 0)
				? get_int32_from_mem((int)index, 1) : proc->args_value[i];
		proc->args_value[i] = (proc->args[i] == T_DIR &&
				g_op_tab[proc->op - 1].dir_size == 1)
				? get_int16_from_mem((int)index, 1) : proc->args_value[i];
		offset += (int)size;
	}
	return (offset);
}

int				check_regs(t_process *proc)
{
	int i;
	int ok;

	i = -1;
	ok = 1;
	while (++i < g_op_tab[proc->op - 1].argc)
		if (proc->args[i] == T_REG)
			if (proc->args_value[i] < 1 || proc->args_value[i] > 16)
				ok = 0;
	return (ok);
}
