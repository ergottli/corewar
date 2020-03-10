#include "dis_asm.h"
#include "corewar.h"

static int					is_treg(uint8_t arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0xc0) == 0x40)
			return (1);
	}
	else if (position == 2)
	{
		if ((arg_byte & 0x30) == 0x10)
			return (1);
	}
	else if (position == 3)
	{
		if ((arg_byte & 0xC) == 0x4)
			return (1);
	}
	return (0);
}

static int					is_tdir(uint8_t arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0xc0) == 0x80)
			return (1);
	}
	else if (position == 2)
	{
		if ((arg_byte & 0x30) == 0x20)
			return (1);
	}
	else if (position == 3)
	{
		if ((arg_byte & 0xC) == 0x8)
			return (1);
	}
	return (0);
}

static int					is_tind(uint8_t arg_byte, int position)
{
	if (position == 1)
	{
		if ((arg_byte & 0xC0) == 0xC0)
			return (1);
	}
	else if (position == 2)
	{
		if ((arg_byte & 0x30) == 0x30)
			return (1);
	}
	else if (position == 3)
	{
		if ((arg_byte & 0xC) == 0xC)
			return (1);
	}
	return (0);
}

int							get_arg_type(uint8_t num, size_t position)
{
	if (is_treg(num, position + 1))
		return (T_REG);
	else if (is_tdir(num, position + 1))
		return (T_DIR);
	else if (is_tind(num, position + 1))
		return (T_IND);
	error_dis(ERR_INVALID_CODE);
	return (0);
}
