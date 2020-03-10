#include "asm.h"

static	int		*freplace(int *mas, int a, int b, int c)
{
	mas[0] = a;
	mas[1] = b;
	mas[2] = c;
	return (mas);
}

static	void	ft_add_atribut_list(t_list_instruction *list, int code_inst,
		int is_code_arg, int index)
{
	list->code_operat = code_inst;
	list->is_code_arg = is_code_arg;
	list->index = index;
}

static	void	ft_list_operation_three(t_list_instruction *new)
{
	int *mas;

	mas = (int *)malloc(sizeof(int) * 3);
	new->next = ft_create_list_operation("ldi", freplace(mas, 6, 7, 1), 2, 0);
	ft_add_atribut_list(new->next, 10, 1, 10);
	new = new->next;
	new->next = ft_create_list_operation("sti", freplace(mas, 1, 6, 7), 2, 0);
	ft_add_atribut_list(new->next, 11, 1, 11);
	new = new->next;
	new->next = ft_create_list_operation("fork", freplace(mas, 2, 0, 0), 2, 0);
	ft_add_atribut_list(new->next, 12, 0, 12);
	new = new->next;
	new->next = ft_create_list_operation("lld", freplace(mas, 5, 1, 0), 4, 1);
	ft_add_atribut_list(new->next, 13, 1, 13);
	new = new->next;
	new->next = ft_create_list_operation("lldi", freplace(mas, 6, 7, 1), 2, 1);
	ft_add_atribut_list(new->next, 14, 1, 14);
	new = new->next;
	new->next = ft_create_list_operation("lfork", freplace(mas, 2, 0, 0), 2, 0);
	ft_add_atribut_list(new->next, 15, 0, 15);
	new = new->next;
	new->next = ft_create_list_operation("aff", freplace(mas, 1, 0, 0), 4, 0);
	ft_add_atribut_list(new->next, 16, 1, 16);
	free(mas);
}

static	void	ft_list_operation_two(t_list_instruction *new)
{
	int	*mas;

	mas = (int *)malloc(sizeof(int) * 3);
	new->next = ft_create_list_operation("and", freplace(mas, 6, 6, 1), 4, 1);
	ft_add_atribut_list(new->next, 6, 1, 6);
	new = new->next;
	new->next = ft_create_list_operation("or", freplace(mas, 6, 6, 1), 4, 1);
	ft_add_atribut_list(new->next, 7, 1, 7);
	new = new->next;
	new->next = ft_create_list_operation("xor", freplace(mas, 6, 6, 1), 4, 1);
	ft_add_atribut_list(new->next, 8, 1, 8);
	new = new->next;
	new->next = ft_create_list_operation("zjmp", freplace(mas, 2, 0, 0), 2, 0);
	ft_add_atribut_list(new->next, 9, 0, 9);
	new = new->next;
	ft_list_operation_three(new);
	free(mas);
}

void			ft_list_instruction_one(void)
{
	t_list_instruction	*list;
	t_list_instruction	*new;
	int					*mas;

	mas = (int *)malloc(sizeof(int) * 3);
	list = ft_create_list_operation("live", freplace(mas, 2, 0, 0), 4, 0);
	new = list;
	g_list_instruction = new;
	ft_add_atribut_list(new, 1, 0, 1);
	new->next = ft_create_list_operation("ld", freplace(mas, 5, 1, 0), 4, 1);
	ft_add_atribut_list(new->next, 2, 1, 2);
	new = new->next;
	new->next = ft_create_list_operation("st", freplace(mas, 1, 4, 0), 4, 0);
	ft_add_atribut_list(new->next, 3, 1, 3);
	new = new->next;
	new->next = ft_create_list_operation("add", freplace(mas, 1, 1, 1), 4, 1);
	ft_add_atribut_list(new->next, 4, 1, 4);
	new = new->next;
	new->next = ft_create_list_operation("sub", freplace(mas, 1, 1, 1), 4, 1);
	ft_add_atribut_list(new->next, 5, 1, 5);
	new = new->next;
	free(mas);
	ft_list_operation_two(new);
}
