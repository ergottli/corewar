#include "corewar.h"

int		init_game(void)
{
	int i;
	int j;
	int k;
	int step;

	i = 0;
	j = 0;
	step = MEM_SIZE / g_vm.players_sum;
	while (++i <= MAX_PLAYERS)
	{
		if (g_vm.players[i].id)
		{
			k = -1;
			ft_memcpy(g_vm.arena + (j * step),
					g_vm.players[i].code, g_vm.players[i].code_size);
			while (++k < g_vm.players[i].code_size)
				g_vm.arena_id[j * step + k] = g_vm.players[i].id;
			if (!create_process(i, j * step))
				return (0);
			++j;
		}
	}
	g_vm.last_alive = &g_vm.players[g_vm.processes->player_id];
	return (1);
}
