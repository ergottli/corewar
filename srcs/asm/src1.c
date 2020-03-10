#include "asm.h"

void		ft_friend_add_name(char *str, int i, int j, int flag)
{
	char	*new;
	char	*str1;

	if (i == j && flag == 2)
		return ;
	if (i == j)
		new = ft_strdup("\n");
	else
		new = ft_strsub(str, i, j - i);
	if (g_name == NULL)
		g_name = new;
	else
	{
		str1 = g_name;
		g_name = ft_strjoin(g_name, new);
		ft_strdel(&str1);
		ft_strdel(&new);
	}
}

void		ft_friend_add_com(char *str, int i, int j, int flag)
{
	char	*new;
	char	*str1;

	if (i == j && flag == 2)
		return ;
	if (i == j)
		new = ft_strdup("\n");
	else
		new = ft_strsub(str, i, j - i);
	if (g_comment == NULL)
		g_comment = new;
	else
	{
		str1 = g_comment;
		g_comment = ft_strjoin(g_comment, new);
		ft_strdel(&str1);
		ft_strdel(&new);
	}
}

long long	ft_llatoi(const char *str)
{
	int					i;
	unsigned long long	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 1;
	if (*str == '\0')
		return (0);
	while (str[i] == ' ' || str[i] == '\v' || str[i] == '\n' || \
		str[i] == '\f' || str[i] == '\t' || str[i] == '\r')
		++i;
	(str[i] == '-') ? sign *= -1 : sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		++i;
	}
	if (res > 9223372036854775807)
		return (sign < 0) ? 0 : -1;
	return (res * sign);
}

int			ft_check_exist_arg(char **mas_arg, int j, int i)
{
	if (mas_arg[i][j] == ' ' || mas_arg[i][j] == '\t' || mas_arg[i][j] == '\0')
	{
		ft_put_error("Lexical error\n", 0);
		return (-1);
	}
	return (1);
}

int			ft_work_with_arg(char **mas)
{
	t_operation			*oper;
	t_list_instruction	*list;

	oper = ft_return_last_oper();
	list = g_list_instruction;
	while (list != NULL)
	{
		if (list->index == oper->index)
			break ;
		list = list->next;
	}
	if (ft_col_arg_permitted(mas, oper, list) == -1)
		return (-1);
	if (ft_true_arg(mas, oper, list) == -1)
		return (-1);
	return (1);
}
