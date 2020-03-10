#include "asm.h"

char			*ft_get_name_file(char *name)
{
	char *str;
	char *new_file_name;

	str = ft_strsub(name, 0, ft_strlen(name) - 2);
	new_file_name = ft_strjoin(str, ".cor");
	ft_strdel(&str);
	return (new_file_name);
}

static	void	ft_reverse(char *str)
{
	char	*str1;
	int		i;
	int		l;

	l = ft_strlen(str);
	if (l == 0 || l == 1)
		return ;
	str1 = ft_strdup(str);
	i = 0;
	while (i < l / 2)
	{
		str1[i] = str[l - i - 1];
		i++;
	}
	while (i < l)
	{
		str1[i] = str1[l - i - 1];
		i++;
	}
	ft_strdel(&str1);
}

void			ft_record_magic_file(int fd, size_t size, int l)
{
	int8_t	i;
	char	c;
	char	*str;
	size_t	size1;

	size1 = size;
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	str[size] = '\0';
	while (size > 0)
	{
		c = (char)((l >> i) & 0xFF);
		i += 8;
		str[size - 1] = c;
		size = size - 1;
	}
	ft_reverse(str);
	write(fd, str, size1);
	ft_strdel(&str);
}

int				ft_record_champion_name(int fd, char *str)
{
	int l;
	int len;

	l = ft_strlen(str);
	if (l > PROG_NAME_LENGTH)
		return (-1);
	len = PROG_NAME_LENGTH - l;
	write(fd, str, l);
	while (len-- != 0)
		write(fd, "\0", 1);
	return (1);
}
