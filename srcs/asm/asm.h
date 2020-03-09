#ifndef ASM_H
# define ASM_H

# include "../../libft/libft.h"
# include "op.h"
# include <fcntl.h>
# include <stdlib.h>

typedef struct					s_operation
{
	int							index;
	int							label_flag;
	int							size_instruction;
	int							size_arg[3];
	char						**label_names;
	int							code_operation;
	int							is_code_arg;
	long long					value1;
	long long					value2;
	long long					value3;
	char						*mas_label_arg1;
	char						*mas_label_arg2;
	char						*mas_label_arg3;
	int							code_type_arg;
	int							col_arg;
	struct s_operation			*next;
}								t_operation;

typedef struct					s_list_instruction
{
	int							index;
	char						*name_operat;
	int							params[3];
	int							size_tdir;
	int							carry;
	int							code_operat;
	int							is_code_arg;
	struct s_list_instruction	*next;
}								t_list_instruction;

char							*g_name;
char							*g_comment;
t_list_instruction				*g_list_instruction;
t_operation						*g_operation;
int								g_num_arg;
char							g_code_type_arg[9];
char							g_error[100];

void							ft_put_error(char *str, int flag);
int								ft_return_end(char *str);
int								main(int argc, char **argv);
void							ft_record_null(int fd);
void							ft_record_champion_exec_code(int fd);
void							ft_finish_present(int fd, char *str);
void							ft_free_oper_instr(void);
long long						ft_llatoi(const char *str);
void							ft_friend_add_name(char *str, int i,
		int j, int flag);
void							ft_friend_add_com(char *str, int i,
		int j, int flag);
int								ft_check_exist_arg(char **mas_arg,
		int j, int i);
char							*ft_find_normal_str(char *str);
int								ft_work_with_arg(char **mas);
int								ft_del_return(char **line,
		int(foo)(char *str, int *flag), int *flag, int *a);
void							ft_counting_size_instruction(void);
char							*ft_get_str_label(t_operation *oper, int i);
void							ft_insert_value(t_operation *oper,
		int i, int value);
int								ft_read_asembler(char *line, int *flag);
int								ft_skip_space(char *str, int index);
int								ft_mystrcmp(char *str1, char *str2);
char							*ft_strcopy_name_comment(char *str,
		int i, int a);
int								ft_check_com_value(char *str, int i,
		int *flag, int a);
t_operation						*ft_add_new_operation(int code_oper,
		int is_code_arg, int index, int flag);
t_list_instruction				*ft_create_list_operation(char *name,
		int par[3], int size, int carry);
void							ft_list_instruction_one(void);
int								ft_string_command_name(char *str, int *flag);
int								ft_string_command_comment(char *str, int *flag);
int								ft_sting_empty_comment(char *str,
		int flag);
int								ft_check_chars_label(char c);
int								ft_check_on_metky(char *line,
		int index, int *flag);
t_operation						*ft_return_last_oper(void);
int								ft_col_arg_permitted(char **mas,
		t_operation *oper, t_list_instruction *list);
int								ft_check_on_instruction(char *line, int i,
		int *flag, int new_list);
int								ft_true_arg(char **mas_arg, t_operation *oper,
		t_list_instruction *list);
void							ft_strdel_t_oper(t_operation *oper);
int								ft_helper_check_metky(char *line, int *flag,
		int i, t_operation *list);
int								ft_add_mas_label_arg(t_operation *oper, int i,
		char	**mas_arg, int j);
char							*ft_get_name_label_arg(char *str, int i);
int								ft_col_number(long long a,
		char **mas_arg, int j, int i);
int								ft_check_cooment(t_list_instruction *list,
		char	**mas_arg, int i, int j);
int								ft_record_value(t_operation *oper,
		char **mas_arg, int j, int i);
int								ft_record_value_reg(t_operation *oper,
		char **mas_arg, int j, int i);
int								ft_reg(t_list_instruction *list,
		t_operation *oper, int i, char	**mas_arg);
int								ft_dir(t_list_instruction *list,
		t_operation *oper, int i, char	**mas_arg);
int								ft_ind(t_list_instruction *list,
		t_operation *oper, int i, char	**mas_arg);
int								ft_reg_ind(t_list_instruction *list,
		t_operation *oper, int i, char	**mas_arg);
int								ft_dir_ind(t_list_instruction *list,
		t_operation *oper, int i, char	**mas_arg);
int								ft_reg_dir_ind(t_list_instruction *list,
		t_operation *oper, int i, char	**mas_arg);
int								ft_reg_dir(t_list_instruction *list,
		t_operation *oper, int i, char	**mas_arg);
char							**ft_add_one_elem_mas(char **mas,
		char *value);
int								ft_eqals_label_left(t_operation *new,
		t_operation *oper, int i);
int								ft_eqals_label_right(t_operation *new,
		t_operation *oper, int i);
int								ft_check_noneexist_label(t_operation *oper);
int								ft_byte_counting(void);
char							*ft_get_name_file(char *name);
void							ft_record_magic_file(int fd, size_t size,
		int l);
int								ft_record_champion_name(int fd, char *str);
int								ft_write_bytes_file(char *name_file);

#endif
