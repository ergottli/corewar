#include "dis_asm.h"
#include "corewar.h"

void					error_dis(const char *error_msg)
{
	ft_putendl(error_msg);
	exit(-1);
}

static void				usage(void)
{
	ft_putendl("./diasm 'filename'");
	exit(0);
}

int						main(int argc, char **argv)
{
	int					fd_cor;
	t_parser			*parser;

	if (argc == 1)
		usage();
	if ((fd_cor = open(argv[1], O_RDONLY)) == -1)
		exit(-1);
	parser = init_parser(fd_cor);
	parse_bytecode(parser);
	parser->fd_asm = 1;
	parser->fd_asm = create_asm_file(argv[1]);
	dprintf(parser->fd_asm, "%s \"%s\"\n%s \"%s\"\n\n", \
		NAME_CMD_STRING, parser->name, COMMENT_CMD_STRING, parser->comment);
	convert_player_code(parser);
	close(parser->fd_asm);
	close(fd_cor);
	delete_parser(&parser);
}
