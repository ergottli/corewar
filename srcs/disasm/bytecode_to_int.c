#include "dis_asm.h"
#include "corewar.h"

#define SIGN_BIT_INT 15

static int			convert_with_negative_sign(int num)
{
	num--;
	num = ~num;
	num <<= 16;
	num >>= 16;
	return (num);
}

static int			num_compose(t_parser *parser, size_t *pos, \
						size_t numof_byte)
{
	int				num;

	if (numof_byte == 1)
		return (parser->code[*pos]);
	num = 0x0;
	while (numof_byte--)
	{
		num <<= 8;
		num |= parser->code[*pos];
		(*pos)++;
	}
	(*pos)--;
	return (num);
}

int					bytecode_to_int(t_parser *parser, size_t *pos, \
						t_optab tab, int arg_type)
{
	size_t			numof_byte;
	int				num;

	numof_byte = 1;
	if (arg_type == T_DIR)
		numof_byte = tab.dir_size;
	else if (arg_type == T_IND)
		numof_byte = 2;
	num = num_compose(parser, pos, numof_byte);
	if (((num & (1 << SIGN_BIT_INT)) ? 1 : 0))
		num = (-1) * convert_with_negative_sign(num);
	return (num);
}
