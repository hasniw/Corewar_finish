# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/18 22:57:27 by lutsiara          #+#    #+#              #
#    Updated: 2020/05/13 16:29:30 by wahasni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../asm

FLAGS = -Wall -Werror -Wextra
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
			 asm

C_FILENAME 	=	check_param \
				check_parsing \
				check_type \
				disp_hexlen \
				ft_error \
				ft_free \
				ft_free2 \
				ft_init \
				ft_list \
				ft_skip \
				ft_inst \
				get_op \
				get_param \
				main \
				output \
				parse_comment \
				parse_instruction \
				parse_name \
				parser \
				handle_end

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
	@$(CC) $(HEADER) $(OBJ) $(LIB) -o $@
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
