#include "corewar.h"

void	redistribution(void)
{
	int	i;

	i = -1;
	while (++i < g_vm.players_sum)
		g_vm.players[g_vm.players_temp[i].id] = g_vm.players_temp[i];
}

int		print_errors_players(char *str)
{
	ft_putstr_fd("ERROR: ", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	return (0);
}

int		load_player(char *player_filename, int player_k)
{
	int fd;

	fd = 0;
	if (g_vm.players_temp[player_k].id == 0)
		set_id(player_k);
	if ((fd = open(player_filename, O_RDONLY)) < 1)
		return (print_errors_players("Invalid file with champion"));
	if (!check_magic(fd))
		return (print_errors_players("Invalid file with champion"));
	if (!check_name(fd, player_k))
		return (print_errors_players("Invalid file with champion"));
	if (!check_exec_size(fd, player_k))
		return (print_errors_players("Invalid code size"));
	if (!check_comment(fd, player_k))
		return (print_errors_players("Invalid file with champion"));
	if (!check_code(fd, player_k))
		return (print_errors_players("Invalid code size"));
	close(fd);
	return (1);
}

int		create_players(char **argv)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (argv[++i])
	{
		if (ft_strstr(argv[i], ".cor"))
		{
			if (!load_player(argv[i], k))
				return (0);
			++k;
		}
	}
	redistribution();
	return (1);
}
