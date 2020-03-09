#include "corewar.h"

int		print_usage(int code, int usage)
{
	if (code == -1)
		ft_printf("%s\n", ANSI_B_RED"Only files with "
		"the extension .cor are accepted!"ANSI_RESET);
	if (code == -2)
		ft_printf("%s\n", ANSI_B_RED"The -n (1 - MAX_PLAYERS) flag "
"overrides the player's sequence number, "
"set before the player's file. "ANSI_RESET);
	if (code == -3)
		ft_printf("%s\n", ANSI_B_RED"The-d CYCLE flag prints "
"the state of the arena on the specified cycle.\n"
"The CYCLE value can only be a positive natural number\n"ANSI_RESET);
	if (code == -4)
		ft_printf("%s %d\n", ANSI_B_RED"Max number of players is:",
				MAX_PLAYERS, ANSI_RESET);
	if (code == -5)
		ft_printf("%s\n", ANSI_B_RED"Duplicates in flags"ANSI_RESET);
	if (code == -6)
		ft_printf("%s\n", ANSI_B_RED"You pass "
"FLAG as the LAST argument!"ANSI_RESET);
	if (code == -7)
		ft_printf("%s\n", ANSI_B_RED"Flag value is not a number!"ANSI_RESET);
	if (usage)
		standart_usage();
	return (0);
}

int		standart_usage(void)
{
	ft_putstr("Usage: ./corewar [-a (-dump|-d) <num> (-shed|-s) "
"<num> -l <num>] [-v] [-n <num>] <champion.cor> <...>\n");
	ft_putstr("    -a          : Print output from \"aff\" (Default is off)\n");
	ft_putstr("    -dump <num> : Dump memory "
"(32 octets per line) after <num> cycles and exit\n");
	ft_putstr("    -d    <num> : Dump memory "
"(64 octets per line) after <num> cycles and exit\n");
	ft_putstr("    -show <num> : Run <num> cycles, "
"dump memory (32 octets per line), pause and repeat\n");
	ft_putstr("    -s    <num> : Run <num> cycles, "
"dump memory (64 octets per line), pause and repeat\n");
	ft_putstr("    -l    <num> : Log levels\n");
	ft_putstr("                   1  : Show lives\n");
	ft_putstr("                   2  : Show cycles\n");
	ft_putstr("                   4  : Show operations\n");
	ft_putstr("                   16 : Show PC movements\n");
	ft_putstr("    -v          : Run visualizer\n");
	ft_putstr("    -n    <num> : Set <num> of the next player\n");
	return (0);
}

int		check_flags(int i, int ac, char **ag)
{
	int value;
	int offset;

	offset = 0;
	if (i + 1 == ac)
		return (print_usage(-6, 1));
	if (!ft_isnum(ag[i + 1]) && ag[i][1] != 'a' && ag[i][1] != 'v')
		return (print_usage(-7, 1));
	value = ft_atoi(ag[i + 1]);
	if (ag[i][1] == 'n')
		offset = (check_n(value)) ? 1 : offset;
	else if (ag[i][1] == 'd')
		offset = ((check_d(ag, value, i))) ? 1 : offset;
	else if (ag[i][1] == 's')
		offset = ((check_s(ag, value, i))) ? 1 : offset;
	else if (ag[i][1] == 'l')
		offset = ((check_l(value))) ? 1 : offset;
	else if (ag[i][1] == 'a')
		g_vm.af = 1u;
	else if (ag[i][1] == 'v')
		g_vm.viz |= 1u;
	return (offset);
}

int		check_extension(int i, char **file)
{
	int j;

	j = (int)ft_strlen(file[i]) - 1;
	while (file[i][--j] != '.')
		;
	if (file[i][j] != '.')
		return (print_usage(-1, 1));
	if (file[i][j] == '.' && ft_strequ(file[i] + j, ".cor"))
		++g_vm.players_sum;
	else
		return (standart_usage());
	return (1);
}

int		check_args(int ac, char **ag)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		if (ag[i][0] == '-')
		{
			if (!(i += check_flags(i, ac, ag)))
				return (0);
			else if (i > ac)
				return (print_usage(-2, 1));
		}
		else
		{
			if (!check_extension(i, ag))
				return (0);
		}
		if (g_vm.players_sum > MAX_PLAYERS)
			return (print_usage(-4, 1));
	}
	return (1);
}
