#include "asm.h"

void	ft_counting_size_instruction(void)
{
	t_operation	*oper;
	int			i;
	int			sum;

	oper = g_operation;
	while (oper != NULL)
	{
		sum = 1;
		i = -1;
		while (++i < 3)
			sum += oper->size_arg[i];
		sum += oper->is_code_arg;
		if (sum == 1)
			sum = 0;
		oper->size_instruction += sum;
		oper = oper->next;
	}
}

char	*ft_get_str_label(t_operation *oper, int i)
{
	int a;

	a = 0;
	if (oper->mas_label_arg1 != NULL)
	{
		if (a == i)
			return (oper->mas_label_arg1);
		a++;
	}
	if (oper->mas_label_arg2 != NULL)
	{
		if (a == i)
			return (oper->mas_label_arg2);
		a++;
	}
	if (oper->mas_label_arg3 != NULL)
	{
		if (a == i)
			return (oper->mas_label_arg3);
	}
	return (NULL);
}

void	ft_insert_value(t_operation *oper, int i, int value)
{
	int a;

	a = 0;
	if (oper->mas_label_arg1 != NULL)
		if (a++ == i)
		{
			oper->value1 = value;
			return ;
		}
	if (oper->mas_label_arg2 != NULL)
		if (a++ == i)
		{
			oper->value2 = value;
			return ;
		}
	if (oper->mas_label_arg3 != NULL)
		if (a == i)
		{
			oper->value3 = value;
			return ;
		}
}
