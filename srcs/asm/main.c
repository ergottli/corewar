#include "asm.h"

static	int	ft_body_read_file(char **line, int *flag, int *a)
{
	if (*flag == 1 && *a == 2)
		*flag = 2;
	if (ft_sting_empty_comment(*line, *flag) == 1)
		ft_strdel(line);
	else if (*flag == 0 || *flag == 12)
	{
		if (ft_del_return(line, &ft_string_command_name, flag, a) == -1)
			return (-1);
	}
	else if (*flag == 1 || *flag == 10)
	{
		if (ft_del_return(line, &ft_string_command_comment, flag, a)
			== -1)
			return (-1);
	}
	else
	{
		if (ft_del_return(line, &ft_read_asembler, flag, a) == -1)
			return (-1);
	}
	return (1);
}

static	int	ft_read_with_file(int fd, int flag)
{
	char	*line;
	int		a;

	line = NULL;
	a = 0;
	while (get_next_line(fd, &line) != 0)
	{
		if (ft_body_read_file(&line, &flag, &a) == -1)
		{
			free(line);
			return (-1);
		}
		free(line);
		line = NULL;
	}
	return (1);
}

static	int	ft_work_with_file(char *str)
{
	int	fd;

	g_code_type_arg[8] = '\0';
	g_code_type_arg[7] = '0';
	g_code_type_arg[6] = '0';
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putstr("Can't read source file\n");
		return (-1);
	}
	g_operation = NULL;
	ft_list_instruction_one();
	return (ft_read_with_file(fd, 0));
}

static	int	ft_check_s(char *str)
{
	int i;
	int	a;

	i = -1;
	a = -1;
	if (str == NULL || str[0] == '\0')
		return (-1);
	while (str[++i] != '\0')
	{
		if (str[i] == '.')
			a = i;
	}
	if (a == -1)
		return (-1);
	if (ft_strcmp(str + i - 1, "s") == 0)
		return (1);
	return (-1);
}

int			main(int argc, char **argv)
{
	g_error[0] = '\0';
	if (argc != 2)
	{
		ft_putstr("Usage: ./asm <sourcefile.s>\n");
		return (-1);
	}
	if (ft_check_s(argv[1]) == -1)
	{
		ft_putstr("Can't read source file \n");
		return (-1);
	}
	if (ft_work_with_file(argv[1]) == -1)
	{
		ft_free_oper_instr();
		ft_putstr(g_error);
		return (-1);
	}
	return (ft_return_end(argv[1]));
}
