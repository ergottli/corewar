#include "dis_asm.h"
#include "corewar.h"

#define MAX_NUMOF_ARGS 3

static void			fill_args_from_code(int *arg_type, uint8_t num, t_optab tab)
{
	size_t			i;

	i = 0;
	while (i < tab.numof_args)
	{
		arg_type[i] = get_arg_type(num, i);
		i++;
	}
}

void				interpret_args(t_parser *parser, size_t *pos, t_optab tab)
{
	size_t			i;
	int				arg_type[MAX_NUMOF_ARGS];

	if (!tab.type_code)
		arg_type[0] = tab.args[0];
	else
		fill_args_from_code((int *)arg_type, parser->code[(*pos)++], tab);
	i = 0;
	while (i < tab.numof_args)
	{
		dprintf(parser->fd_asm, "%c%d", get_arg_char(arg_type[i]), \
			bytecode_to_int(parser, pos, tab, arg_type[i]));
		(*pos)++;
		i++;
		if (i != tab.numof_args)
			dprintf(parser->fd_asm, "%c ", SEPARATOR_CHAR);
	}
	dprintf(parser->fd_asm, "\n");
}
