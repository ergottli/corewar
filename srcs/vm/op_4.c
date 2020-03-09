#include "../../incs/corewar.h"

int	lfork_op(t_process *proc)
{
	t_process	*new;
	int			addr;
	int			i;

	addr = proc->pos + proc->args_value[0];
	i = -1;
	if (!(new = create_process(proc->player_id, position_correction(addr))))
		return (0);
	while (++i < REG_NUMBER)
		new->regs[i] = proc->regs[i];
	new->carry = proc->carry;
	new->live_incycle = proc->live_incycle;
	if (g_vm.log_level & OPERA)
		ft_printf("P%5d | lfork %d (%d)\n",
				proc->proc_id, proc->args_value[0], addr);
	return (1);
}

int	aff_op(t_process *proc)
{
	if (g_vm.af)
		ft_printf("Aff: %c\n", (char)proc->regs[proc->args_value[0] - 1]);
	return (1);
}
