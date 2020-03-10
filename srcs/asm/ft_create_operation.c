#include "asm.h"

t_list_instruction	*ft_create_list_operation(char *name, int par[3],
		int size, int carry)
{
	t_list_instruction	*list;

	list = (t_list_instruction *)malloc(sizeof(t_list_instruction));
	list->name_operat = ft_strdup(name);
	list->params[0] = par[0];
	list->params[1] = par[1];
	list->params[2] = par[2];
	list->size_tdir = size;
	list->carry = carry;
	list->is_code_arg = 0;
	list->code_operat = 0;
	list->next = NULL;
	return (list);
}

static	void		ft_helper_oper(t_operation *list)
{
	list->label_flag = 0;
	list->value1 = -1;
	list->value2 = -1;
	list->value3 = -1;
}

static	t_operation	*ft_create_operation(int code_oper, int is_code_arg,
		int index, int flag)
{
	t_operation	*list;

	list = (t_operation *)ft_memalloc(sizeof(t_operation));
	ft_helper_oper(list);
	if (flag == 1)
	{
		list->is_code_arg = is_code_arg;
		list->code_operation = code_oper;
		list->index = index;
	}
	else
	{
		list->is_code_arg = 0;
		list->code_operation = 0;
		list->index = 0;
	}
	list->code_type_arg = 0;
	list->label_names = NULL;
	list->size_instruction = 0;
	list->mas_label_arg1 = NULL;
	list->mas_label_arg2 = NULL;
	list->mas_label_arg3 = NULL;
	list->next = NULL;
	return (list);
}

t_operation			*ft_add_new_operation(int code_oper, int is_code_arg,
		int index, int flag)
{
	t_operation	*new;
	t_operation	*copy;

	new = ft_create_operation(code_oper, is_code_arg, index, flag);
	new->size_arg[0] = 0;
	new->size_arg[1] = 0;
	new->size_arg[2] = 0;
	if (g_operation == NULL)
	{
		g_operation = new;
		return (new);
	}
	copy = g_operation;
	while (copy->next != NULL)
		copy = copy->next;
	copy->next = new;
	return (new);
}
