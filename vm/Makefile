# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lutsiara <lutsiara@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 16:35:34 by lutsiara          #+#    #+#              #
#    Updated: 2020/02/28 00:35:16 by lutsiara         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

FLAGS = -Wall -Werror -Wextra
LDFLAGS = -lncurses
CC = gcc $(FLAGS)
SRC_PATH = srcs/
OBJ_PATH = srcs/
INC_PATH = includes/
INC = -I
INCLUDES = $(INC_PATH) ../$(INC_LIB_PATH)
LIB = ../$(LIBFT)
SRC_SUFFIX = .c
H_SUFFIX = .h

H_FILENAME = op \
			 vm

C_FILENAME = main \
			 debug \
			 core/code_check \
			 core/error \
			 core/exec_virtual_machine \
			 core/init \
			 core/life_check \
			 core/load_process \
			 core/params \
			 core/parse_option \
			 core/parse_player \
			 core/print_machine \
			 core/print_pannel \
			 core/process_review \
			 op/op \
			 op/operations1 \
			 op/operations2 \
			 op/operations3 \
			 op/operations4 \
			 utils/ft_copy_registers \
			 utils/ft_idx_mod \
			 utils/ft_init_registers \
			 utils/ft_is_valid_op \
			 utils/ft_is_valid_reg \
			 utils/ft_long_rel_address \
			 utils/ft_modulo_mem_size \
			 utils/ft_read_address \
			 utils/ft_read_octet \
			 utils/ft_write_to_address \
			 visual/create_windows \
			 visual/init \
			 visual/key_event \
			 visual/print \
			 visual/print_panel \
			 visual/visual

INC_FILES = $(addsuffix $(H_SUFFIX),$(H_FILENAME))
SRC_FILES = $(addsuffix $(SRC_SUFFIX),$(C_FILENAME))
OBJ_FILES = $(SRC_FILES:.c=.o)
SRC = $(addprefix $(SRC_PATH),$(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_FILES))
HEADER = $(addprefix $(INC), $(INCLUDES))
H_FILES = $(addprefix $(INC_PATH), $(INC_FILES))

BLUE = "\\033[36m"
RED = "\\033[31m"
WHITE = "\\033[0m"
GREEN = "\\033[32m"

EOLCLR = "\\033[0K"
CHECK = "\\xE2\\x9C\\x94"
OK = "$(CHECK)$(WHITE)"

$(NAME): $(OBJ) $(H_FILES) $(SRC) $(LIB)
	@$(CC) $(HEADER) $(OBJ) $(LIB) -o $@ $(LDFLAGS)
	@printf "\r$(EOLCLR)$(NAME): $(GREEN)$(OK)\n"

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\r$(EOLCLR)$(NAME): $< $(BLUE)$(OK)"
	@$(CC) $(HEADER) -o $@ -c $<

clean:
	@printf "$(NAME): rm *.o"
	@/bin/rm -rf $(OBJ)
	@printf " $(RED)$(OK)\n"

fclean: clean
	@printf "$(NAME): rm $(NAME)"
	@/bin/rm -f $(NAME)
	@printf " $(RED)$(OK)\n"

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: re
