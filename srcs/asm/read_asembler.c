#include "asm.h"

static	void	ft_initialization_value(int *a, int *flag)
{
	*a = 2;
	*flag = 0;
}

int				ft_del_return(char **line, int (foo)(char *str, int *flag),
		int *flag, int *a)
{
	if (foo(*line, flag) == -1)
	{
		if (*flag == 0 && *a == 0)
		{
			*flag = 1;
			if (ft_del_return(line, &ft_string_command_comment, flag, a) == -1)
				return (-1);
			*a = 1;
			if (*flag != 10)
				ft_initialization_value(a, flag);
			ft_strdel(line);
			return (1);
		}
		ft_strdel(line);
		return (-1);
	}
	if (*a == 1 && *flag == 2)
		ft_initialization_value(a, flag);
	ft_strdel(line);
	return (1);
}

int				ft_check_cooment(t_list_instruction *list,
		char **mas_arg, int i, int j)
{
	if (i == 0)
	{
		if (list->params[1] != 0 || list->params[2] != 0)
			return (-1);
	}
	else if (i == 1)
	{
		if (list->params[2] != 0)
			return (-1);
	}
	if (mas_arg[i][j] == COMMENT_CHAR || mas_arg[i][j] == '\0')
		return (1);
	return (-1);
}

int				ft_read_asembler(char *line, int *flag)
{
	int	i;

	i = 0;
	i = ft_skip_space(line, i);
	if (ft_check_on_metky(line, i, flag) == -1)
		if (ft_check_on_instruction(line, i, flag, 1) == -1)
			return (-1);
	return (1);
}
