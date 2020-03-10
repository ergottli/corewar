#include "asm.h"

int				ft_eqals_label_left(t_operation *new, t_operation *oper, int i)
{
	char	*str;
	int		j;
	int		sum;

	j = -1;
	str = ft_get_str_label(oper, i);
	while (new->label_names[++j])
	{
		if (ft_strcmp(str, new->label_names[j]) == 0)
			break ;
	}
	if (!new->label_names[j])
		return (-1);
	sum = 0;
	while (new != oper)
	{
		sum += new->size_instruction;
		new = new->next;
	}
	ft_insert_value(oper, i, sum * (-1));
	return (1);
}

int				ft_eqals_label_right(t_operation *new, t_operation *oper, int i)
{
	char		*str;
	int			j;
	int			sum;
	t_operation	*copy;

	j = -1;
	str = ft_get_str_label(oper, i);
	while (new->label_names[++j])
	{
		if (ft_strcmp(str, new->label_names[j]) == 0)
			break ;
	}
	if (new->label_names[j] == NULL)
		return (-1);
	copy = oper;
	sum = 0;
	while (new != copy)
	{
		sum += copy->size_instruction;
		copy = copy->next;
	}
	ft_insert_value(oper, i, sum);
	return (1);
}

int				ft_check_noneexist_label(t_operation *oper)
{
	if (oper->mas_label_arg1 != NULL && oper->value1 == -1)
	{
		ft_putstr("No such label while attempting to dereference token\n");
		return (-1);
	}
	if (oper->mas_label_arg2 != NULL && oper->value2 == -1)
	{
		ft_putstr("No such label while attempting to dereference token\n");
		return (-1);
	}
	if (oper->mas_label_arg3 != NULL && oper->value3 == -1)
	{
		ft_putstr("No such label while attempting to dereference token\n");
		return (-1);
	}
	return (1);
}

static	void	ft_free_instruction(void)
{
	t_list_instruction	*instr;
	t_list_instruction	*copy;

	instr = g_list_instruction;
	while (instr != NULL)
	{
		copy = instr;
		instr = instr->next;
		ft_strdel(&copy->name_operat);
		copy->next = NULL;
		free(copy);
	}
}

void			ft_free_oper_instr(void)
{
	t_operation *oper;
	t_operation	*copy;
	int			j;

	oper = g_operation;
	while (oper != NULL)
	{
		j = -1;
		copy = oper;
		oper = oper->next;
		if (copy->mas_label_arg1 != NULL)
			ft_strdel(&copy->mas_label_arg1);
		if (copy->mas_label_arg2 != NULL)
			ft_strdel(&copy->mas_label_arg2);
		if (copy->mas_label_arg3 != NULL)
			ft_strdel(&copy->mas_label_arg3);
		while (copy->label_names && copy->label_names[++j])
			ft_strdel(&copy->label_names[j]);
		free(copy->label_names);
		copy->next = NULL;
		free(copy);
	}
	ft_free_instruction();
	ft_strdel(&g_name);
	ft_strdel(&g_comment);
}
