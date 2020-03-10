#include "corewar.h"

t_op	g_op_tab[17];

void	init_op_one(void)
{
	g_op_tab[0] = (t_op){"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, live_op, 0};
	g_op_tab[1] = (t_op){"ld", 2, {T_DIR, T_IND, 0, T_REG},
			2, 5, "load", 1, 0, ld_op, 1};
	g_op_tab[2] = (t_op){"st", 2, {T_REG, 0, 0, T_IND, T_REG}, 3,
			5, "store", 1, 0, st_op, 1};
	g_op_tab[3] = (t_op){"add", 3, {T_REG, 0, 0, T_REG, 0, 0, T_REG, 0,
			0}, 4, 10, "addition", 1, 0, add_op, 1};
	g_op_tab[4] = (t_op){"sub", 3, {T_REG, 0, 0, T_REG, 0, 0, T_REG, 0,
			0}, 5, 10, "substraction", 1, 0, sub_op, 1};
	g_op_tab[5] = (t_op){"and", 3, {T_REG, T_DIR, T_IND,
			T_REG, T_IND, T_DIR, T_REG}, 6, 6, "and", 1, 0, and_op, 1};
	g_op_tab[6] = (t_op){"or", 3, {T_REG, T_IND, T_DIR,
			T_REG, T_IND, T_DIR, T_REG}, 7, 6, "or", 1, 0, or_op, 1};
	g_op_tab[7] = (t_op){"xor", 3, {T_REG, T_IND, T_DIR,
			T_REG, T_IND, T_DIR, T_REG}, 8, 6, "xor", 1, 0, xor_op, 1};
	g_op_tab[8] = (t_op){"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0,
			1, zjmp_op, 0};
	g_op_tab[9] = (t_op){"ldi", 3, {T_REG, T_DIR, T_IND,
			T_DIR, T_REG, 0, T_REG}, 10, 25, "load", 1, 1, ldi_op, 1};
	g_op_tab[10] = (t_op){"sti", 3, {T_REG, 0, 0, T_REG,
			T_DIR, T_IND, T_DIR, T_REG, 0}, 11, 25, "store", 1, 1, sti_op, 1};
	g_op_tab[11] = (t_op){"fork", 1, {T_DIR}, 12, 800,
			"fork", 0, 1, fork_op, 0};
}

void	init_op_two(void)
{
	g_op_tab[12] = (t_op){"lld", 2, {T_DIR, T_IND, 0, T_REG}, 13, 10,
			"load", 1, 0, lld_op, 1};
	g_op_tab[13] = (t_op){"lldi", 3, {T_REG, T_DIR, T_IND,
			T_DIR, T_REG, 0, T_REG}, 14, 50, "load", 1, 1, lldi_op, 1};
	g_op_tab[14] = (t_op){"lfork", 1, {T_DIR}, 15, 1000,
			"long fork", 0, 1, lfork_op, 0};
	g_op_tab[15] = (t_op){"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, aff_op, 1};
	g_op_tab[16] = (t_op){"null", 0, {0}, 17, 0, "null", 0, 0, NULL, 0};
}
