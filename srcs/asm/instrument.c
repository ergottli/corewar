#include "asm.h"

int				ft_skip_space(char *str, int index)
{
	while (str[index] != '\0' && (str[index] == ' ' || str[index] == '\t'))
		index++;
	return (index);
}

int				ft_mystrcmp(char *str1, char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i])
		i++;
	if (str1[i] == '\0' || str2[i] == '\0')
		return (1);
	else
		return (0);
}

static	char	*ft_output_error(int a)
{
	if (a == 0)
	{
		ft_put_error("Champion name too long (Max length 128)\n", 1);
		return (NULL);
	}
	else
	{
		ft_put_error("Champion comment too long (Max length 2048)\n", 1);
		return (NULL);
	}
}

char			*ft_strcopy_name_comment(char *str, int i, int a)
{
	int		len;
	int		j;
	char	*value;

	len = 0;
	j = i;
	while (str[++j] != '"')
	{
		len++;
		if (str[j] == '\0')
			return (NULL);
	}
	if (a == 0 && len > PROG_NAME_LENGTH)
		return (ft_output_error(0));
	else if (len > COMMENT_LENGTH)
		return (ft_output_error(1));
	value = (char *)malloc(sizeof(char) * (len + 1));
	value[len] = '\0';
	j = 0;
	while (str[++i] != '"')
		value[j++] = str[i];
	return (value);
}

int				ft_check_com_value(char *str, int i, int *flag, int a)
{
	if (str[i++] != '"')
		return (-1);
	while (str[i] != '\0' && str[i] != '"')
		i++;
	if (str[i++] == '\0' && (*flag == 2 || *flag == 1))
	{
		if (a == 0)
			*flag = 12;
		else
			*flag = 10;
		return (2);
	}
	while (str[i] != '\0' && str[i] != COMMENT_CHAR &&
	str[i] == ' ' && str[i] == '\t')
		i++;
	if (str[i] == '\0' || str[i] == COMMENT_CHAR)
		return (1);
	return (-1);
}
