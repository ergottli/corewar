#include "../../incs/corewar.h"

int	check_n(int value)
{
	if (value > MAX_PLAYERS || value <= 0)
		return (print_usage(-2, 1));
	else
	{
		if (is_set(value, MAX_PLAYERS))
			return (print_usage(-5, 1));
		g_vm.players_temp[g_vm.players_sum].id =
				(!is_set(value, MAX_PLAYERS)) ? value : 0;
	}
	return (1);
}

int	check_d(char **av, int value, int i)
{
	g_vm.dump |= (ft_strequ(av[i], "-dump")) ? 2u : 1u;
	if (av[i + 1] <= 0)
		return (print_usage(-3, 0));
	else
		g_vm.dump_cycle = value;
	return (1);
}

int	check_s(char **av, int value, int i)
{
	g_vm.s |= (ft_strequ(av[i], "-show")) ? 2u : 1u;
	if (av[i + 1] <= 0)
	{
		ft_printf(ANSI_B_RED"Negative or zero flag "
			"-s value! See usage:\n"ANSI_RESET);
		ft_putstr("    -show <num> : Run <num> cycles, "
			"dump memory (32 octets per line), pause and repeat\n");
		ft_putstr("    -s    <num> : Run <num> cycles, "
			"dump memory (64 octets per line), pause and repeat\n");
		return (0);
	}
	else
	{
		g_vm.dump_cycle = value;
		g_vm.dump_step = g_vm.dump_cycle;
	}
	return (1);
}

int	check_l(int value)
{
	if (value == 1)
		g_vm.log_level |= LIVE;
	else if (value == 2)
		g_vm.log_level |= CYCLE;
	else if (value == 4)
		g_vm.log_level |= OPERA;
	else if (value == 8)
		g_vm.log_level |= DEATH;
	else if (value == 16)
		g_vm.log_level |= PC;
	else
	{
		ft_printf(ANSI_B_RED"Wrong flag -l value! See usage:\n"ANSI_RESET);
		ft_putstr("    -l    <num> : Log levels\n");
		ft_putstr("                   1  : Show lives\n");
		ft_putstr("                   2  : Show cycles\n");
		ft_putstr("                   4  : Show operations\n");
		ft_putstr("                   8  : Show deaths\n");
		ft_putstr("                   16 : "
			"Show PC movements\n");
		return (0);
	}
	return (1);
}
