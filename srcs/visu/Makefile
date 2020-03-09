# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yquaro <yquaro@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/23 19:01:16 by yquaro            #+#    #+#              #
#    Updated: 2020/02/18 12:41:24 by vgerold-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ../../incs/corewar.mk

HEADER_H = -I ../../incs/

DIR_O = ../../.objs/vm
SOURCES = init_visu.c draw.c draw_arena.c color.c draw_info.c handle_buttons.c \
			draw_help.c init_wins.c

OBJECTS = $(addprefix $(DIR_O)/,$(patsubst %.c,%.o,$(SOURCES)))

all: print $(OBJECTS)

print:
	@echo \*\*\* Compiling Visualizer files

$(DIR_O)/%.o: %.c
	$(COMPILING) $< -o $@
