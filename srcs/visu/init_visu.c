#include "corewar.h"

#define MIN_COLS_TO_VISU 70
#define MIN_LINES_TO_VISU 70

static void				check_size_of_terminal(void)
{
	size_t				tty_lines;
	size_t				tty_cols;

	getmaxyx(stdscr, tty_lines, tty_cols);
	if (tty_lines < MIN_LINES_TO_VISU || tty_cols < MIN_COLS_TO_VISU)
	{
		ft_putendl("Enlarge the terminal window, please");
		exit(0);
	}
}

static void				init_button_fields(t_visu *visu)
{
	visu->is_stopped = 1;
	visu->speed = MAX_SPEED_POINT;
	visu->delay = 0.0;
	visu->is_next_cycle = 0;
}

static void				configure(void)
{
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	noecho();
	refresh();
}

t_visu					*init_visu(void)
{
	t_visu				*visu;

	if (!(visu = (t_visu *)malloc(sizeof(t_visu))))
		exit(-1);
	if (!initscr())
	{
		ft_putendl("Error initialising ncurses.");
		exit(-1);
	}
	configure();
	check_size_of_terminal();
	init_win_arena(visu);
	init_win_info(visu);
	init_win_help(visu);
	init_colors();
	init_button_fields(visu);
	return (visu);
}

void					delete_visu(t_visu **visu)
{
	delwin((*visu)->win_arena);
	delwin((*visu)->win_info);
	delwin((*visu)->win_help);
	delwin((*visu)->win_winner);
	free(*visu);
	*visu = NULL;
	endwin();
}
