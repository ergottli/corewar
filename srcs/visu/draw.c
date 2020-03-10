#include "corewar.h"

#define NUMOF_LINES_FOR_PLAYER 4
#define WINNER "WINNER!"

static void			pause_before_termination(void)
{
	nodelay(stdscr, FALSE);
	getch();
}

void				draw_winner(int flag, size_t line)
{
	static size_t	start_line;

	if (flag == _GIVE_NUMOF_LIVE_)
	{
		start_line = line;
		return ;
	}
	g_vm.visu->win_winner = newwin(NUMOF_LINES_FOR_PLAYER + 3, \
		WIN_INFO_COLS, start_line - 1, WIN_ARENA_COLS);
	start_line = 1;
	draw_player(g_vm.visu->win_winner, &start_line, g_vm.last_alive->id);
	wattron(g_vm.visu->win_winner, A_BLINK | A_BOLD);
	wcolor_set(g_vm.visu->win_winner, CYAN, NULL);
	mvwprintw(g_vm.visu->win_winner, 1, \
		(WIN_INFO_COLS - ft_strlen(WINNER)) / 2, WINNER);
	box(g_vm.visu->win_winner, 0, 0);
	wcolor_set(g_vm.visu->win_winner, 0, NULL);
	wattroff(g_vm.visu->win_winner, A_BLINK | A_BOLD);
	wrefresh(g_vm.visu->win_winner);
	pause_before_termination();
}

void				draw(void)
{
	if (g_vm.viz & 1u)
	{
		draw_arena();
		draw_info();
		handle_buttons();
	}
}
