#include "asm.h"

int					ft_check_chars_label(char c)
{
	int		i;
	char	*str;

	i = -1;
	str = LABEL_CHARS;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			return (1);
	}
	ft_put_error("Syntax error\n", 0);
	return (-1);
}

static	void		ft_del_label(t_operation *oper)
{
	int i;

	if (oper->mas_label_arg1)
		ft_strdel(&oper->mas_label_arg1);
	oper->mas_label_arg1 = NULL;
	while (oper->mas_label_arg2)
		ft_strdel(&oper->mas_label_arg2);
	oper->mas_label_arg2 = NULL;
	while (oper->mas_label_arg3)
		ft_strdel(&oper->mas_label_arg3);
	oper->mas_label_arg1 = NULL;
	i = -1;
	while (oper->label_names && oper->label_names[++i])
		ft_strdel(&oper->label_names[i]);
	free(oper->label_names);
	free(oper);
}

void				ft_strdel_t_oper(t_operation *oper)
{
	t_operation	*copy;

	copy = g_operation;
	if (copy->next == NULL)
	{
		ft_del_label(oper);
		g_operation = NULL;
		return ;
	}
	while (copy != NULL && copy->next != oper)
		copy = copy->next;
	if (copy == NULL)
		return ;
	copy->next = NULL;
	ft_del_label(oper);
}

static	t_operation	*ft_get_oper(void)
{
	t_operation	*oper;

	oper = g_operation;
	while (oper->next != NULL)
		oper = oper->next;
	return (oper);
}

int					ft_check_on_metky(char *line, int index, int *flag)
{
	int			i;
	t_operation	*list;
	char		**mas;

	i = index;
	while (line[i] != '\0' && line[i] != LABEL_CHAR)
	{
		if (ft_check_chars_label(line[i]) == -1)
			return (-1);
		i++;
	}
	if (line[i] != LABEL_CHAR)
		return (-1);
	if (*flag == 2)
		list = ft_add_new_operation(0, 0, 0, 0);
	else
		list = ft_get_oper();
	list->label_flag = 1;
	mas = ft_add_one_elem_mas(list->label_names,
			ft_strsub(line, index, i - index));
	free(list->label_names);
	list->label_names = mas;
	i = ft_skip_space(line, i + 1);
	return (ft_helper_check_metky(line, flag, i, list));
}
