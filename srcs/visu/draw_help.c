#include "corewar.h"

#define MARGIN_TOP		3

#define BUTTON_NAME_EXIT "Exit - "
#define BUTTON_EXIT "\'Esc\'"

#define BUTTON_NAME_PAUSE "Pause / Unpause - "
#define BUTTON_PAUSE "\'Space\'"

#define BUTTON_NAME_NEXT_CYCLE "Next cycle - "
#define BUTTON_NEXT_CYCLE "\'Right arrow\'"

#define BUTTON_NAME_DEFAULT_SPEED "Default speed - "
#define BUTTON_DEFAULT_SPEED "\'Left arrow\'"

#define BUTTON_NAME_SPEED_UP "Speed UP - "
#define BUTTON_SPEED_UP "\'Top arrow\'"

#define BUTTON_NAME_SPEED_DOWN "Speed DOWN - "
#define BUTTON_SPEED_DOWN "\'Down arrow\'"

static void				draw_first_column(t_visu *visu, size_t *margin_left)
{
	mvwprintw(visu->win_help, MARGIN_TOP, *margin_left, BUTTON_NAME_EXIT);
	mvwprintw(visu->win_help, MARGIN_TOP + 1, *margin_left, BUTTON_NAME_PAUSE);
	wcolor_set(visu->win_help, CYAN, NULL);
	mvwprintw(visu->win_help, MARGIN_TOP, \
				*margin_left + ft_strlen(BUTTON_NAME_EXIT), BUTTON_EXIT);
	*margin_left += ft_strlen(BUTTON_NAME_PAUSE);
	mvwprintw(visu->win_help, MARGIN_TOP + 1, *margin_left, BUTTON_PAUSE);
	wcolor_set(visu->win_help, 0, NULL);
	*margin_left += ft_strlen(BUTTON_PAUSE) + 3;
}

static void				draw_second_column(t_visu *visu, size_t *margin_left)
{
	mvwprintw(visu->win_help, MARGIN_TOP, *margin_left, BUTTON_NAME_NEXT_CYCLE);
	mvwprintw(visu->win_help, MARGIN_TOP + 1, *margin_left, \
		BUTTON_NAME_DEFAULT_SPEED);
	wcolor_set(visu->win_help, CYAN, NULL);
	mvwprintw(visu->win_help, MARGIN_TOP, \
		*margin_left + ft_strlen(BUTTON_NAME_NEXT_CYCLE), BUTTON_NEXT_CYCLE);
	*margin_left += ft_strlen(BUTTON_NAME_DEFAULT_SPEED);
	mvwprintw(visu->win_help, MARGIN_TOP + 1, *margin_left, \
		BUTTON_DEFAULT_SPEED);
	wcolor_set(visu->win_help, 0, NULL);
	*margin_left += ft_strlen(BUTTON_DEFAULT_SPEED) + 3;
}

static void				draw_third_column(t_visu *visu, size_t *margin_left)
{
	mvwprintw(visu->win_help, MARGIN_TOP, *margin_left, BUTTON_NAME_SPEED_UP);
	mvwprintw(visu->win_help, MARGIN_TOP + 1, *margin_left, \
		BUTTON_NAME_SPEED_DOWN);
	wcolor_set(visu->win_help, CYAN, NULL);
	mvwprintw(visu->win_help, MARGIN_TOP, \
		*margin_left + ft_strlen(BUTTON_NAME_SPEED_UP), BUTTON_SPEED_UP);
	*margin_left += ft_strlen(BUTTON_NAME_SPEED_DOWN);
	mvwprintw(visu->win_help, MARGIN_TOP + 1, *margin_left, BUTTON_SPEED_DOWN);
	wcolor_set(visu->win_help, 0, NULL);
}

void					draw_help(t_visu *visu)
{
	size_t				margin_left;

	margin_left = (WIN_HELP_COLS - \
		((ft_strlen(BUTTON_NAME_PAUSE) + ft_strlen(BUTTON_PAUSE)) + \
		(ft_strlen(BUTTON_NAME_DEFAULT_SPEED) + \
			ft_strlen(BUTTON_DEFAULT_SPEED)) + \
		(ft_strlen(BUTTON_NAME_SPEED_DOWN) + ft_strlen(BUTTON_SPEED_DOWN)) + \
			(3 * 3))) / 2;
	draw_first_column(visu, &margin_left);
	draw_second_column(visu, &margin_left);
	draw_third_column(visu, &margin_left);
}
