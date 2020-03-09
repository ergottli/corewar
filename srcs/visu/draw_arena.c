#include "corewar.h"

#define SPEED "SPEED "

static int			get_color(size_t i, size_t j)
{
	return (g_vm.players[g_vm.arena_id[i * 64 + j]].color);
}

static int			get_color_carry(size_t i, size_t j)
{
	return (g_vm.players[g_vm.arena_id[i * 64 + j]].color + 5);
}

void				draw_speed_bar(void)
{
	size_t			i;

	wcolor_set(g_vm.visu->win_arena, CYAN, NULL);
	mvwprintw(g_vm.visu->win_arena, 1, (WIN_ARENA_COLS - 31), SPEED);
	wcolor_set(g_vm.visu->win_arena, 0, NULL);
	i = 0;
	while (i < g_vm.visu->speed * 2)
	{
		wmove(g_vm.visu->win_arena, 1, \
			(WIN_ARENA_COLS - 31) + ft_strlen(SPEED) + i);
		waddch(g_vm.visu->win_arena, (' ' | A_STANDOUT | COLOR_PAIR(CYAN)));
		waddch(g_vm.visu->win_arena, (' ' | A_STANDOUT | COLOR_PAIR(CYAN)));
		i += 2;
	}
	while (i < MAX_SPEED_POINT * 2)
	{
		wmove(g_vm.visu->win_arena, 1, \
			(WIN_ARENA_COLS - 31) + ft_strlen(SPEED) + i);
		waddch(g_vm.visu->win_arena, ('_' | COLOR_PAIR(CYAN)));
		waddch(g_vm.visu->win_arena, ('_' | COLOR_PAIR(CYAN)));
		i += 2;
	}
}

static int			one_of_carriages_pos(t_process *carry, size_t pos)
{
	while (carry != NULL)
	{
		if ((int)pos == carry->pos)
			return (1);
		carry = carry->next;
	}
	return (0);
}

void				draw_arena(void)
{
	int				i;
	int				j;
	t_process		*carry;

	carry = g_vm.processes;
	i = -1;
	while (++i < 64)
	{
		j = -1;
		wmove(g_vm.visu->win_arena, i + 2, 5);
		while (++j < 64)
		{
			if (one_of_carriages_pos(carry, i * 64 + j))
				wcolor_set(g_vm.visu->win_arena, get_color_carry(i, j), NULL);
			else
				wcolor_set(g_vm.visu->win_arena, get_color(i, j), NULL);
			wprintw(g_vm.visu->win_arena, "%.2x", g_vm.arena[i * 64 + j]);
			wcolor_set(g_vm.visu->win_arena, 0, NULL);
			waddch(g_vm.visu->win_arena, ' ');
		}
		wprintw(g_vm.visu->win_arena, "\n");
	}
	draw_speed_bar();
	box(g_vm.visu->win_arena, 0, 0);
	wrefresh(g_vm.visu->win_arena);
}
