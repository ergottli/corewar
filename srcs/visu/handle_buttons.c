#include "corewar.h"

static void		speed_up(void)
{
	if (g_vm.visu->delay != 0.0 && g_vm.visu->speed != MAX_SPEED_POINT)
	{
		g_vm.visu->speed++;
		g_vm.visu->delay -= 0.1;
	}
}

static void		speed_down(void)
{
	if (g_vm.visu->delay != 1.0 && g_vm.visu->speed != 1)
	{
		g_vm.visu->speed--;
		g_vm.visu->delay += 0.1;
	}
}

static void		default_speed(void)
{
	g_vm.visu->delay = 0.0;
	g_vm.visu->speed = MAX_SPEED_POINT;
}

void			handle_buttons(void)
{
	int			key;

	g_vm.visu->is_next_cycle = 0;
	if ((key = getch()) == SPACE_BUTTON)
	{
		nodelay(stdscr, ((g_vm.visu->is_stopped == 1) ? TRUE : FALSE));
		g_vm.visu->is_stopped *= (-1);
		draw_game_status(g_vm.visu->is_stopped);
	}
	else if (key == ESC_BUTTON)
	{
		delete_visu(&(g_vm.visu));
		exit(1);
	}
	else if (key == KEY_DOWN)
		speed_down();
	else if (key == KEY_UP)
		speed_up();
	else if (key == KEY_LEFT)
		default_speed();
	else if (key == KEY_RIGHT && g_vm.visu->is_stopped != -1)
		g_vm.visu->is_next_cycle = 1;
	usleep(g_vm.visu->delay * MAX_DELAY);
}
