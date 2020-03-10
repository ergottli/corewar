
include ../incs/corewar.mk

CFLAGS = -g -Wall -Wextra -Werror
COMPILING = $(CC) $(CFLAGS) $(HEADER_H)

all: asm corewar disasm

prep:
	@cp ../libft/$(LIBNAME) ./$(LIBNAME)

asm: prep
	@$(CC) $(CFLAGS) $(HEADER_H_ASM) ./asm_obj/*.o $(LIBNAME) -o $(ASSEMBLER)
	@cp -v ./$(ASSEMBLER) ../srcs/asm/
	@mv $(ASSEMBLER) ../$(ASSEMBLER)
	@echo \*\*\* ASSEMBLER COMPILED!

corewar: prep
	@$(COMPILING) -lncurses ./vm/*.o $(LIBNAME) -o $(COREWAR)
	@mv $(COREWAR) ../$(COREWAR)
	@echo \*\*\* COREWAR COMPILED!

disasm: prep
	@$(COMPILING) ./disasm/*.o $(LIBNAME) -o $(DISASSEMBLER)
	@mv $(DISASSEMBLER) ../$(DISASSEMBLER)
	@echo \*\*\* DISASSEMBLER COMPILED!

clean:
	@rm -f asm_obj/*.o
	@rm -f vm/*.o
	@rm -f disasm/*.o

fclean: clean
	@rm -rvf $(LIBNAME) $(ASSEMBLER) $(COREWAR) $(DISASSEMBLER)
