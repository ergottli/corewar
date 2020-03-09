#include "dis_asm.h"
#include "corewar.h"

static int32_t			parse_int32(int fd)
{
	int					ret;
	int32_t				magic;
	unsigned char		buffer[SIZE_OF_MAGIC + 1];
	size_t				i;

	if ((ret = read(fd, &buffer, SIZE_OF_MAGIC)) == -1)
		error_dis(ERR_READ_FILE);
	if (ret < SIZE_OF_MAGIC)
		error_dis(ERR_INVALID_FILE);
	magic = 0x0;
	i = 0;
	while (i < SIZE_OF_MAGIC)
	{
		magic <<= 8;
		magic |= buffer[i];
		i++;
	}
	return (magic);
}

static char				*parse_str(int fd, size_t size)
{
	int					ret;
	unsigned char		buffer[size + 1];

	if ((ret = read(fd, &buffer, size)) == -1)
		error_dis(ERR_READ_FILE);
	if (ret < (int)size)
		error_dis(ERR_INVALID_FILE);
	return (ft_strdup((const char *)buffer));
}

static uint8_t			*parse_code(int fd, int32_t size)
{
	int					ret;
	uint8_t				*buffer;
	uint8_t				last_byte;

	if (!(buffer = (uint8_t *)ft_memalloc(size)))
		error_dis(ERR_ALLOCATE);
	if ((ret = read(fd, buffer, size)) == -1)
		error_dis(ERR_READ_FILE);
	if (ret < (int)size || read(fd, &last_byte, 1) != 0)
		error_dis(ERR_INVALID_FILE);
	return (buffer);
}

void					parse_bytecode(t_parser *parser)
{
	if ((parse_int32(parser->fd_cor)) != COREWAR_EXEC_MAGIC)
		error_dis(ERR_INVALID_FILE);
	parser->name = parse_str(parser->fd_cor, PROG_NAME_LENGTH);
	if ((parse_int32(parser->fd_cor)) != 0)
		error_dis(ERR_NO_NULL);
	if ((parser->code_size = parse_int32(parser->fd_cor)) < 0)
		error_dis(ERR_INVALID_CODE_SIZE);
	parser->comment = parse_str(parser->fd_cor, COMMENT_LENGTH);
	if ((parse_int32(parser->fd_cor)) != 0)
		error_dis(ERR_NO_NULL);
	parser->code = parse_code(parser->fd_cor, parser->code_size);
}
