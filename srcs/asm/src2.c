#include "asm.h"

char	*ft_find_normal_str(char *str)
{
	int		i;
	int		col;
	char	*new;

	i = 0;
	col = 0;
	while (str[i] != '\0' && str[i] != COMMENT_CHAR &&
	str[i] != ALT_COMMENT_CHAR)
	{
		if (str[i] == SEPARATOR_CHAR)
			col++;
		i++;
	}
	if (col > 2)
	{
		ft_put_error("Invalid parameter\n", 0);
		return (NULL);
	}
	new = ft_strsub(str, 0, i);
	return (new);
}

int		ft_helper_check_metky(char *line, int *flag, int i, t_operation *list)
{
	if (line[i] == '\0' || line[i] == COMMENT_CHAR
		|| line[i] == ALT_COMMENT_CHAR)
	{
		*flag = -2;
		return (1);
	}
	if (ft_check_on_instruction(line, i, flag, 0) == -1)
	{
		ft_strdel_t_oper(list);
		return (-1);
	}
	return (1);
}

void	ft_put_error(char *str, int flag)
{
	int i;

	if (g_error[0] != '\0' && flag != 1)
		return ;
	i = -1;
	while (str[++i] != '\0')
		g_error[i] = str[i];
	g_error[i] = '\0';
}

void	ft_finish_present(int fd, char *str)
{
	ft_record_null(fd);
	ft_record_champion_exec_code(fd);
	ft_putstr("Writing output program to ");
	ft_putstr(str);
	ft_putchar('\n');
}

int		ft_return_end(char *str)
{
	if (ft_byte_counting() == -1)
	{
		ft_free_oper_instr();
		return (-1);
	}
	if (ft_write_bytes_file(str) == -1)
	{
		ft_free_oper_instr();
		return (-1);
	}
	return (1);
}
