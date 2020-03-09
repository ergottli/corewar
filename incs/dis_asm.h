#ifndef DIS_ASM_H
# define DIS_ASM_H

# include <stdint.h>
# include <stddef.h>

# define ERR_READ_FILE "error: read file"
# define ERR_INVALID_FILE "error: invalid file"
# define ERR_INVALID_MAGIC_HEADER "error: invalid magic header"
# define ERR_NO_NULL "error: no null"
# define ERR_INVALID_CODE_SIZE "error: invalid code size"
# define ERR_ALLOCATE "error: allocate"
# define ERR_INVALID_FILE_NAME "error: invalid file name"
# define ERR_CREATE_FILE "error: create file"
# define ERR_INVALID_CODE "error: invalid code"

# define SIZE_OF_MAGIC 4

# define FILE_EXTENSION ".s"

typedef struct			s_parser
{
	int					fd_cor;
	int					fd_asm;
	char				*name;
	char				*comment;
	int32_t				code_size;
	uint8_t				*code;
}						t_parser;

typedef struct			s_optab
{
	uint8_t				code;
	char				*name;
	size_t				numof_args;
	size_t				dir_size;
	int					args[3];
	int					type_code;
}						t_optab;

typedef struct			s_argtab
{
	int					type;
	char				ch;
	int					code;
}						t_argtab;

void					error_dis(const char *error_msg);

t_parser				*init_parser(int fd);
void					delete_parser(t_parser **parser);

void					parse_bytecode(t_parser *parser);
int						create_asm_file(const char *filename);
void					convert_player_code(t_parser *parser);
void					interpret_args(t_parser *parser, \
							size_t *pos, t_optab tab);
char					get_arg_char(int arg_type);
int						get_arg_type(uint8_t num, size_t position);
int						bytecode_to_int(t_parser *parser, size_t *pos, \
							t_optab tab, int arg_type);

#endif
