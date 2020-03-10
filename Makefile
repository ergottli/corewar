include incs/corewar.mk

all: $(ASSEMBLER) corewar disasm

prep:
	echo prep
	@mkdir -p .objs/vm .objs/disasm .objs/asm_obj
	@make -C libft/ all

$(ASSEMBLER): prep
	echo asm
	@make -C srcs/asm/ all
	@make -C .objs/ asm

corewar: prep
	echo corewar
	@make -C srcs/vm/ all
	@make -C srcs/visu/ all
	@make -C .objs/ corewar

disasm: prep
	echo disasm
	@make -C srcs/disasm/ all
	@make -C .objs/ disasm

clean:
	@make -C libft/ clean
	@make -C .objs/ clean

fclean: clean
	@make -C libft/ fclean
	@make -C .objs/ fclean
	@rm -rf corewar
	@rm -rf dis_asm
	@rm -rf asm

re: fclean all
