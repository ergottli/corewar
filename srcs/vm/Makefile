include ../../incs/corewar.mk

HEADER_H = -I ../../incs/

DIR_O = ../../.objs/vm
SOURCES = battle.c battle_check.c check_args.c corewar.c create_players.c \
            init_game.c op.c op_1.c op_2.c op_3.c op_4.c op_utils.c parse_file.c \
			parse_operations.c process_func.c check_flags.c op_log.c \
			additional_functions.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling Virtual Machine files

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
