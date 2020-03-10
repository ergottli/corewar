#include "corewar.h"

int	check_magic(int fd)
{
	unsigned char	buf[4];

	if (read(fd, &buf[3], 1) < 1)
		return (0);
	if (read(fd, &buf[2], 1) < 1)
		return (0);
	if (read(fd, &buf[1], 1) < 1)
		return (0);
	if (read(fd, &buf[0], 1) < 1)
		return (0);
	if (*(unsigned int*)buf != COREWAR_EXEC_MAGIC)
		return (0);
	return (1);
}

int	check_exec_size(int fd, int player_k)
{
	char	buf[4];

	if (read(fd, &buf[3], 1) < 1)
		return (0);
	if (read(fd, &buf[2], 1) < 1)
		return (0);
	if (read(fd, &buf[1], 1) < 1)
		return (0);
	if (read(fd, &buf[0], 1) < 1)
		return (0);
	g_vm.players_temp[player_k].code_size = *(int*)buf;
	if (g_vm.players_temp[player_k].code_size < 1 ||
		g_vm.players_temp[player_k].code_size > CHAMP_MAX_SIZE)
		return (0);
	return (1);
}

int	check_code(int fd, int player_k)
{
	int		ret;
	char	buf[CHAMP_MAX_SIZE + 1];

	if ((ret = read(fd, &buf, CHAMP_MAX_SIZE + 1)) < 1)
		return (0);
	if (ret != g_vm.players_temp[player_k].code_size)
		return (0);
	ft_memcpy(g_vm.players_temp[player_k].code, buf,
			g_vm.players_temp[player_k].code_size);
	return (1);
}

int	check_name(int fd, int player_k)
{
	int			ret;
	int			buf;

	if ((ret = read(fd, &(g_vm.players_temp[player_k].name),
			PROG_NAME_LENGTH)) < PROG_NAME_LENGTH)
		return (0);
	g_vm.players_temp[player_k].name[ret] = '\0';
	if (!ft_strlen(g_vm.players_temp[player_k].name))
		return (0);
	if (read(fd, &buf, 4) < 4)
		return (0);
	if (buf != 0)
		return (0);
	return (1);
}

int	check_comment(int fd, int player_k)
{
	int			ret;
	int			buf;

	if ((ret = read(fd, &(g_vm.players_temp[player_k].comment),
			COMMENT_LENGTH)) < COMMENT_LENGTH)
		return (0);
	g_vm.players_temp[player_k].comment[ret] = '\0';
	if (!ft_strlen(g_vm.players_temp[player_k].comment))
		return (0);
	if (read(fd, &buf, 4) < 4)
		return (0);
	if (buf != 0)
		return (0);
	return (1);
}
