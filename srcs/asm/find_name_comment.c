#include "asm.h"

static	int		ft_add_str_name(char *str, int i, int *flag)
{
	int		j;
	char	*str1;

	i = i + 1;
	j = i;
	while (str[j] != '\0' && str[j] != '"')
		j++;
	if (str[j] == '"')
	{
		if (str[j + 1] != '\0')
		{
			ft_put_error("Syntax error\n", 1);
			return (-1);
		}
		*flag = 1;
		ft_friend_add_name(str, i, j, *flag);
		return (1);
	}
	ft_friend_add_name(str, i, j, *flag);
	if (i == j)
		return (1);
	str1 = g_name;
	g_name = ft_strjoin(g_name, "\n");
	ft_strdel(&str1);
	return (1);
}

int				ft_string_command_name(char *str, int *flag)
{
	int i;

	if (*flag == 12)
		return (ft_add_str_name(str, -1, flag));
	i = ft_skip_space(str, 0);
	if (ft_mystrcmp(str + i, NAME_CMD_STRING) != 1)
	{
		ft_put_error("Syntax error\n", 0);
		return (-1);
	}
	*flag += 1;
	i += ft_strlen(NAME_CMD_STRING);
	i = ft_skip_space(str, i);
	if (ft_check_com_value(str, i, flag, 0) == -1)
	{
		ft_put_error("Syntax error\n", 0);
		return (-1);
	}
	if (*flag == 12)
		return (ft_add_str_name(str, i, flag));
	else if ((g_name = ft_strcopy_name_comment(str, i, 0)) != NULL)
		return (1);
	ft_put_error("Syntax error\n", 0);
	return (-1);
}

static	int		ft_add_str_comment(char *str, int i, int *flag)
{
	int		j;
	char	*str1;

	i = i + 1;
	j = i;
	while (str[j] != '\0' && str[j] != '"')
		j++;
	if (str[j] == '"')
	{
		if (str[j + 1] != '\0')
		{
			ft_put_error("Syntax error\n", 1);
			return (-1);
		}
		*flag = 2;
		ft_friend_add_com(str, i, j, *flag);
		return (1);
	}
	ft_friend_add_com(str, i, j, *flag);
	if (i == j)
		return (1);
	str1 = g_comment;
	g_comment = ft_strjoin(g_comment, "\n");
	ft_strdel(&str1);
	return (1);
}

int				ft_string_command_comment(char *str, int *flag)
{
	int i;

	if (*flag == 10)
		return (ft_add_str_comment(str, -1, flag));
	i = ft_skip_space(str, 0);
	if (ft_mystrcmp(str + i, COMMENT_CMD_STRING) != 1)
	{
		ft_put_error("Syntax error\n", 0);
		return (-1);
	}
	*flag += 1;
	i += ft_strlen(COMMENT_CMD_STRING);
	i = ft_skip_space(str, i);
	if (ft_check_com_value(str, i, flag, 1) == -1)
	{
		ft_put_error("Syntax error\n", 0);
		return (-1);
	}
	if (*flag == 10)
		return (ft_add_str_comment(str, i, flag));
	else if ((g_comment = ft_strcopy_name_comment(str, i, 1)) != NULL)
		return (1);
	ft_put_error("Syntax error\n", 0);
	return (-1);
}

int				ft_sting_empty_comment(char *str, int flag)
{
	int i;

	i = 0;
	if (flag == 10 || flag == 12)
		return (-1);
	if (str == NULL || str[0] == '\0')
		return (1);
	while ((str[i] != '\0') && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == COMMENT_CHAR || str[i] == ALT_COMMENT_CHAR)
		return (1);
	i = ft_skip_space(str, i);
	if (str[i] == '\0')
		return (1);
	return (-1);
}
