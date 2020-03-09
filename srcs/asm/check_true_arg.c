#include "asm.h"

char			*ft_get_name_label_arg(char *str, int i)
{
	int j;

	j = i;
	while (str[j] != '\0' && str[j] != ' ' && str[j] != '\t')
		j++;
	return (ft_strsub(str, i, j - i));
}

int				ft_add_mas_label_arg(t_operation *oper, int i,
		char **mas_arg, int j)
{
	char	*mas;

	if (i == 0)
	{
		mas = ft_get_name_label_arg(mas_arg[i], j);
		if (oper->mas_label_arg1 != NULL)
			free(oper->mas_label_arg1);
		oper->mas_label_arg1 = mas;
	}
	else if (i == 1)
	{
		mas = ft_get_name_label_arg(mas_arg[i], j);
		if (oper->mas_label_arg2 != NULL)
			free(oper->mas_label_arg2);
		oper->mas_label_arg2 = mas;
	}
	else
	{
		mas = ft_get_name_label_arg(mas_arg[i], j);
		if (oper->mas_label_arg3 != NULL)
			free(oper->mas_label_arg3);
		oper->mas_label_arg3 = mas;
	}
	return (1);
}

static	int		ft_exp(int l)
{
	int i;
	int num;

	i = 1;
	num = 1;
	while (i <= l)
	{
		num = num * 2;
		i++;
	}
	return (num);
}

static	void	ft_record_type_arg(t_operation *oper)
{
	int i;
	int	sum;
	int l;

	i = 0;
	oper->col_arg = g_num_arg;
	while (g_num_arg < 3)
	{
		g_num_arg++;
		g_code_type_arg[(g_num_arg - 1) * 2] = '0';
		g_code_type_arg[(g_num_arg - 1) * 2 + 1] = '0';
	}
	sum = 0;
	while (i < 8)
	{
		l = 7 - i;
		if (g_code_type_arg[i] == '1')
			sum += ft_exp(l);
		i++;
	}
	oper->code_type_arg = sum;
}

int				ft_true_arg(char **mas_arg, t_operation *oper,
		t_list_instruction *list)
{
	int i;

	i = -1;
	g_num_arg = 0;
	while (mas_arg[++i])
	{
		if (ft_reg(list, oper, i, mas_arg) == -1)
			return (-1);
		else if (ft_dir(list, oper, i, mas_arg) == -1)
			return (-1);
		else if (ft_ind(list, oper, i, mas_arg) == -1)
			return (-1);
		else if (ft_reg_ind(list, oper, i, mas_arg) == -1)
			return (-1);
		else if (ft_dir_ind(list, oper, i, mas_arg) == -1)
			return (-1);
		else if (ft_reg_dir_ind(list, oper, i, mas_arg) == -1)
			return (-1);
		else if (ft_reg_dir(list, oper, i, mas_arg) == -1)
			return (-1);
	}
	ft_record_type_arg(oper);
	return (1);
}
