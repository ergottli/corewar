# Base variables for corewar

CC = @gcc
CFLAGS = -g -c -Wall -Wextra -Werror
HEADER_H = -I ../incs/
HEADER_H_ASM = -I ../srcs/asm/
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)
COREWAR = corewar
DISASSEMBLER = dis_asm
ASSEMBLER = asm
LIBNAME = libft.a