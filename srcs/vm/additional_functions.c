#include "corewar.h"

int		is_set(int number, int max)
{
	int i;

	i = -1;
	while (++i < max)
		if (g_vm.players_temp[i].id == number)
			return (1);
	return (0);
}

void	set_id(int player_k)
{
	int i;

	i = 1;
	while (is_set(i, g_vm.players_sum))
		++i;
	g_vm.players_temp[player_k].id = i;
}

int		get_bit(void)
{
	if (g_vm.dump)
		return ((g_vm.dump) ? g_vm.dump * 32 : 32);
	else if (g_vm.s)
		return ((g_vm.s) ? g_vm.s * 32 : 32);
	else
		return (32);
}

void	wait_function(void)
{
	while (1)
		if (getchar() == '\n')
			break ;
	g_vm.dump_cycle += 1;
}

void	print_arena(void)
{
	int		i;
	int		j;
	int		row;
	int		bit;

	i = 0;
	row = 0;
	bit = get_bit();
	ft_printf("0x");
	while (i < MEM_SIZE)
	{
		j = -1;
		ft_printf("%#.4x : ", row * bit);
		while (++j < bit)
		{
			ft_printf("%02x ", g_vm.arena[i]);
			++i;
		}
		ft_printf("\n");
		++row;
	}
	if (g_vm.dump_cycle == g_vm.cycles_all && g_vm.dump)
		exit(0);
	else if (g_vm.s)
		wait_function();
}
