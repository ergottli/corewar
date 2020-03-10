#include "asm.h"

t_operation	*ft_return_last_oper(void)
{
	t_operation *oper;

	oper = g_operation;
	while (oper->next != NULL)
	{
		oper = oper->next;
	}
	return (oper);
}

int			ft_col_arg_permitted(char **mas, t_operation *oper,
		t_list_instruction *list)
{
	int i;
	int col;
	int	j;

	i = 0;
	while (mas[i])
		i++;
	col = i;
	if (list->index != oper->index)
		return (-1);
	i = -1;
	j = 0;
	while (++i < 3)
		if (list->params[i] != 0)
			j++;
	if (j == col)
		return (1);
	return (-1);
}
