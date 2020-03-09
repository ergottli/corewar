#ifndef COREWAR_H
# define COREWAR_H

# include <inttypes.h>
# include "op.h"
# include "../libft/libft.h"
# include "visu.h"

# define LIVE 1u
# define CYCLE 2u
# define OPERA 4u
# define DEATH 8u
# define PC 16u

typedef struct			s_player
{
	int					id;
	int					color;
	char				name[PROG_NAME_LENGTH + 1];
	char				comment[COMMENT_LENGTH + 1];
	char				code[CHAMP_MAX_SIZE];
	int					code_size;
	short				is_alive;
	ssize_t				lives_all;
	ssize_t				lives_last;
	ssize_t				lives_current;
}						t_player;

typedef struct			s_process
{
	int					proc_id;
	int					player_id;
	int					pos;
	int					pc;
	int					op;
	int					op_error;
	int					args_value[3];
	unsigned int		args[4];
	int					carry;
	int					delay;
	int					live_incycle;
	int					regs[REG_NUMBER];
	struct s_process	*next;
}						t_process;

typedef struct			s_op
{
	char				*op_code;
	int					argc;
	int					args_types[12];
	int					op_id;
	int					op_delay;
	char				*op_name;
	int					has_carry;
	int					dir_size;
	int					(*operations)(t_process *proc);
	int					has_args_code;
}						t_op;

/*
** -------------------------- Parse args -------------------------------
*/

int						check_args(int ac, char **ag);
int						print_usage(int code, int usage);
int						standart_usage(void);
int						create_players(char **argv);
int						is_set(int number, int max);
void					set_id(int player_k);
int						check_n(int value);
int						check_d(char **av, int value, int i);
int						check_s(char **av, int value, int i);
int						check_l(int value);

/*
** -------------------------- Parse players -------------------------------
*/

int						check_magic(int fd);
int						check_name(int fd, int player_k);
int						check_comment(int fd, int player_k);
int						check_exec_size(int fd, int player_k);
int						check_code(int fd, int player_k);

/*
** -------------------------- Initialization -------------------------------
*/

int						init_game(void);
void					print_arena(void);
t_process				*create_process(int n_player, int position);
void					del_process(t_process *proc);
void					init_op_one(void);
void					init_op_two(void);

/*
** -------------------------- Battle -------------------------------
*/

void					intro(void);
int						battle(void);
void					battle_check(void);
void					process_args_code(t_process *proc);
int						calc_args_size(int i, t_process *proc);
int						parse_args_values(t_process *proc);
int						check_regs(t_process *proc);
int						kill_all_procs(void);

/*
** -------------------------- Logs print -------------------------------
*/

void					print_proc_movement(int position, int offset);

/*
** -------------------------- Operations -------------------------------
*/

int						live_op(t_process *proc);
int						ld_op(t_process *proc);
int						st_op(t_process *proc);
int						add_op(t_process *proc);
int						sub_op(t_process *proc);
int						and_op(t_process *proc);
int						or_op(t_process *proc);
int						xor_op(t_process *proc);
int						zjmp_op(t_process *proc);
int						ldi_op(t_process *proc);
int						sti_op(t_process *proc);
int						fork_op(t_process *proc);
int						lld_op(t_process *proc);
int						lldi_op(t_process *proc);
int						lfork_op(t_process *proc);
int						aff_op(t_process *proc);
unsigned int			get_arg_op(t_process *proc, int i);
int						position_correction(int position);
void					universal_op_log(t_process *proc,
		int arg0, int arg1, int arg2);
unsigned int			check_args_type(unsigned int arg_code,
		const int *arg_types, t_process *proc, int j);
int						get_int32_from_mem(int position, int correction);
int16_t					get_int16_from_mem(int position, int correction);

typedef struct			s_game
{
	t_visu				*visu;
	int					process_count;
	int					proc_id_count;
	t_process			*processes;
	t_player			*last_alive;
	t_player			players_temp[MAX_PLAYERS];
	t_player			players[MAX_PLAYERS + 1];
	int					players_sum;
	unsigned char		arena[MEM_SIZE];
	int					arena_id[MEM_SIZE];
	int					cycles_all;
	ssize_t				cycle_current;
	size_t				lives_in_round;
	int					cycles_to_die;
	int					cycles_to_die_last;
	int					cycles_to_die_not_updated;
	int					dump_cycle;
	int					dump_step;
	int					checks;
	unsigned char		log_level;
	unsigned char		dump:2;
	unsigned char		viz:1;
	unsigned char		s:2;
	unsigned char		af:1;
}						t_game;

t_game					g_vm;
extern t_op				g_op_tab[17];
#endif
