include ../../incs/corewar.mk

HEADER_H = -I ./

DIR_O = ../../.objs/asm_obj
SOURCES = ./main.c ./byte_counting.c ./check_true_arg.c ./find_name_comment.c ./friend_find_instruction.c ./ft_create_operation.c \
          		./helper_work_oper.c ./instrument_check_arg.c ./instrument.c ./list_instruction.c ./one_combination_arg.c \
          		./read_asembler.c ./two_combination_arg.c ./work_with_metky.c ./work_with_operations.c ./write_bytes_file.c \
          		./writes_byte_file_two.c ./src1.c ./src2.c ./src3.c ./three_combination_arg.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: $(ASSEMBLER)

$(ASSEMBLER): print $(OBJECTS)

print:
	@echo \*\*\* Compiling Assembler files

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
