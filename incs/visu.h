#ifndef VISU_H
# define VISU_H

# include <ncurses.h>

# define _GIVE_NUMOF_LIVE_ 1

# define RUNNING "RUNNING"
# define STOPPED "STOPPED"

# define IS_PAUSED		1
# define IS_RUNNING		-1
# define MAX_SPEED_POINT 10
# define MAX_DELAY 100000

/*
** Color
*/

# define COLOR_GRAY				8

/*
** Color pairs
*/

# define GRAY					5
# define GREEN					6
# define YELLOW					7
# define RED					8
# define CYAN					9
# define GRAY_CARRY				10
# define GREEN_CARRY			11
# define YELLOW_CARRY			12
# define RED_CARRY				13
# define CYAN_CARRY				14

/*
** Buttons
*/

# define ESC_BUTTON				27
# define SPACE_BUTTON			' '

# define WIN_ARENA_LINES 68
# define WIN_ARENA_COLS 201
# define WIN_INFO_LINES 68
# define WIN_INFO_COLS 50
# define WIN_HELP_LINES 17
# define WIN_HELP_COLS 201

typedef struct			s_visu
{
	WINDOW				*win_arena;
	WINDOW				*win_info;
	WINDOW				*win_help;
	WINDOW				*win_winner;
	int					is_stopped;
	size_t				speed;
	float				delay;
	int					is_next_cycle;
}						t_visu;

t_visu					*init_visu(void);
void					init_win_help(t_visu *visu);
void					init_win_info(t_visu *visu);
void					init_win_arena(t_visu *visu);
void					init_colors(void);
void					delete_visu(t_visu **visu);

void					draw(void);
void					draw_player(WINDOW *win, size_t *line, \
							size_t players_counter);
void					draw_arena(void);
void					draw_info(void);
void					draw_game_status(int flag);
void					handle_buttons(void);
void					draw_help(t_visu *visu);
void					draw_winner(int flag, size_t line);

#endif
