#include "asm.h"

static	int		ft_counting_size_label(t_operation *oper, int a)
{
	t_operation	*new;
	int			i;
	int			flag;

	i = -1;
	while (++i < a)
	{
		flag = 0;
		new = g_operation;
		while (new != NULL)
		{
			if (new == oper)
				flag = 1;
			if (flag == 0 && new->label_flag == 1 &&
			ft_eqals_label_left(new, oper, i) == 1)
				break ;
			if (flag == 1 && new->label_flag == 1 &&
			ft_eqals_label_right(new, oper, i) == 1)
				break ;
			new = new->next;
		}
	}
	if (ft_check_noneexist_label(oper) == -1)
		return (-1);
	return (1);
}

static	int		ft_check_oper_on_label(t_operation *oper)
{
	int i;

	i = 0;
	if (oper->mas_label_arg1 != NULL)
		i++;
	if (oper->mas_label_arg2 != NULL)
		i++;
	if (oper->mas_label_arg3 != NULL)
		i++;
	return (i);
}

static	void	ft_del_one_oper(t_operation *oper)
{
	int i;

	oper->next = NULL;
	i = 0;
	if (oper->label_names != NULL)
	{
		while (oper->label_names[i])
			ft_strdel(&oper->label_names[i++]);
		free(oper->label_names);
	}
	free(oper->mas_label_arg1);
	free(oper->mas_label_arg2);
	free(oper->mas_label_arg3);
	free(oper);
}

static	void	ft_delit_none_oper(void)
{
	t_operation	*oper;
	t_operation	*friend;
	int			a;

	a = 1;
	while (a == 1)
	{
		a = 0;
		oper = g_operation;
		friend = NULL;
		while (oper && oper->next != NULL)
		{
			friend = oper;
			oper = oper->next;
		}
		if (oper && oper->code_operation == 0 && oper->col_arg == 0)
		{
			a = 1;
			if (friend == NULL)
				g_operation = NULL;
			else
				friend->next = NULL;
			ft_del_one_oper(oper);
		}
	}
}

int				ft_byte_counting(void)
{
	t_operation	*oper;
	int			a;

	if (g_operation == NULL)
	{
		ft_putstr("Syntax error at token\n");
		return (-1);
	}
	oper = g_operation;
	ft_counting_size_instruction();
	while (oper != NULL)
	{
		if ((a = ft_check_oper_on_label(oper)) == 0)
		{
			oper = oper->next;
			continue;
		}
		if (ft_counting_size_label(oper, a) == -1)
			return (-1);
		oper = oper->next;
	}
	ft_delit_none_oper();
	return (1);
}
