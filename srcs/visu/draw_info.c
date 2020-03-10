#include "corewar.h"

void				draw_game_status(int flag)
{
	if (flag == IS_PAUSED)
	{
		wcolor_set(g_vm.visu->win_info, RED, NULL);
		mvwprintw(g_vm.visu->win_info, 1, 5, STOPPED);
		wcolor_set(g_vm.visu->win_info, 0, NULL);
	}
	else if (flag == IS_RUNNING)
	{
		wcolor_set(g_vm.visu->win_info, GREEN, NULL);
		mvwprintw(g_vm.visu->win_info, 1, 5, RUNNING);
		wcolor_set(g_vm.visu->win_info, 0, NULL);
	}
	wrefresh(g_vm.visu->win_info);
}

void				draw_player(WINDOW *win, size_t *line, \
						size_t players_counter)
{
	mvwprintw(win, ++(*line), 5, "Player %d : ", players_counter);
	wcolor_set(win, g_vm.players[players_counter].color, NULL);
	mvwprintw(win, (*line)++, 5 + ft_strlen("Player %d : "), \
			"%s        ", g_vm.players[players_counter].name);
	wcolor_set(win, 0, NULL);
	mvwprintw(win, (*line)++, 7, "slogan: %s ", \
		g_vm.players[players_counter].comment);
	mvwprintw(win, (*line)++, 7, "last live: %zu ", \
		g_vm.players[players_counter].lives_last);
	mvwprintw(win, (*line)++, 7, "current live: %zu ", \
		g_vm.players[players_counter].lives_current);
}

void				draw_info(void)
{
	size_t			line;
	size_t			i;

	draw_game_status(g_vm.visu->is_stopped);
	line = 3;
	mvwprintw(g_vm.visu->win_info, line += 2, 5, "Cycles : %zu", \
		g_vm.cycles_all);
	mvwprintw(g_vm.visu->win_info, line += 2, 5, "Cycle to die : %zu      ", \
		g_vm.cycles_to_die);
	mvwprintw(g_vm.visu->win_info, line += 2, 5, "Checks : %zu", \
		g_vm.checks);
	mvwprintw(g_vm.visu->win_info, line += 2, 5, "Lives in round : %zu", \
		g_vm.lives_in_round);
	mvwprintw(g_vm.visu->win_info, line += 2, 5, "Number of cariages : %zu", \
		g_vm.process_count);
	line += 3;
	draw_winner(_GIVE_NUMOF_LIVE_, line);
	i = 0;
	while (++i <= (size_t)g_vm.players_sum)
	{
		draw_player(g_vm.visu->win_info, &line, i);
		line++;
	}
	wrefresh(g_vm.visu->win_info);
}
