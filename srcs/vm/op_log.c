#include "corewar.h"

void	print_proc_movement(int position, int offset)
{
	int byte;
	int dest;

	byte = -1;
	dest = position + offset;
	ft_printf("ADV %d (", offset);
	ft_printf("0x%.4x -> 0x%.4x) ", position, dest);
	while (++byte < offset)
	{
		ft_printf("%.2x", g_vm.arena[position_correction(position + byte)]);
		ft_printf(" ");
	}
	ft_printf("\n");
}

void	print_args(t_process *proc, int *arg)
{
	int i;

	i = -1;
	while (++i < g_op_tab[proc->op - 1].argc)
	{
		if (proc->args[i] == T_REG && !(proc->op == 11 &&
										g_op_tab[proc->op - 1].argc - 1 == i))
			ft_printf("r%d", arg[i]);
		else
			ft_printf("%d", arg[i]);
		if (i != g_op_tab[proc->op - 1].argc - 1)
			ft_printf(" ");
		else
			ft_printf("\n");
	}
}

void	print_verbose(t_process *proc, int *args)
{
	if (proc->op == 10)
		ft_printf("       | -> %s from %d + %d = %d (with pc and mod %d)\n",
				g_op_tab[proc->op - 1].op_name, args[0], args[1],
				args[0] + args[1], proc->pos + (args[0] + args[1]) % IDX_MOD);
	if (proc->op == 11)
		ft_printf("       | -> %s to %d + %d = %d (with pc and mod %d)\n",
				g_op_tab[proc->op - 1].op_name, args[1], args[2],
				args[1] + args[2], proc->pos + (args[1] + args[2]) % IDX_MOD);
	if (proc->op == 14)
		ft_printf("       | -> %s from %d + %d = %d (with pc %d)\n",
				g_op_tab[proc->op - 1].op_name, args[0], args[1],
				args[0] + args[1], proc->pos + (args[0] + args[1]));
}

void	universal_op_log(t_process *proc, int arg0, int arg1, int arg2)
{
	int args[3];

	args[0] = arg0;
	args[1] = arg1;
	args[2] = arg2;
	ft_printf("P%5d | %s ", proc->proc_id, g_op_tab[proc->op - 1].op_code);
	print_args(proc, args);
	print_verbose(proc, args);
}
