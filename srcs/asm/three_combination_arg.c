#include "asm.h"

static	int	ft_helper_dir_ind(t_operation *oper, int i, int j, char **mas_arg)
{
	g_code_type_arg[(g_num_arg - 1) * 2] = '1';
	g_code_type_arg[(g_num_arg - 1) * 2 + 1] = '1';
	oper->size_arg[i] += 2;
	if (mas_arg[i][j] == LABEL_CHAR)
		return (ft_add_mas_label_arg(oper, i, mas_arg, j + 1));
	return (ft_record_value(oper, mas_arg, j, i));
}

int			ft_dir_ind(t_list_instruction *list, t_operation *oper,
		int i, char **mas_arg)
{
	int j;

	if (list->params[i] != 5)
		return (0);
	j = ft_skip_space(mas_arg[i], 0);
	g_num_arg++;
	if ((mas_arg[i][j] >= '0' && mas_arg[i][j] <= '9') || (mas_arg[i][j] == '-'
	&& mas_arg[i][j + 1] >= '0' && mas_arg[i][j + 1] <= '9')
		|| (mas_arg[i][j] == LABEL_CHAR))
		return (ft_helper_dir_ind(oper, i, j, mas_arg));
	else
	{
		g_code_type_arg[(g_num_arg - 1) * 2] = '1';
		g_code_type_arg[(g_num_arg - 1) * 2 + 1] = '0';
		if (mas_arg[i][j] != DIRECT_CHAR)
			return (-1);
		oper->size_arg[i] += list->size_tdir;
		if (mas_arg[i][j + 1] == LABEL_CHAR)
			return (ft_add_mas_label_arg(oper, i, mas_arg, j + 2));
		return (ft_record_value(oper, mas_arg, j + 1, i));
	}
}
