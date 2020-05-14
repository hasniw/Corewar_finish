# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wahasni <wahasni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 17:06:41 by lutsiara          #+#    #+#              #
#    Updated: 2020/05/10 10:55:49 by wahasni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra
CC = gcc $(FLAGS)
SRC_PATH = srcs/
OBJ_PATH = srcs/
INC_PATH = includes/
INC = -I
INCLUDES = $(INC_PATH)
SRC_SUFFIX = .c
H_SUFFIX = .h

H_FILENAME = libft \
			 get_next_line \
			 ft_ieee \
			 ft_glo_print \
			 ft_printf

C_FILENAME = ft_atoi \
			 ft_atoui \
			 ft_count_word \
			 ft_atol \
			 ft_bzero \
			 ft_djb2a \
			 ft_countword \
			 ft_delcontent \
			 ft_digitlen \
			 ft_isalnum \
			 ft_isalpha \
			 ft_isascii \
			 ft_isdigit \
			 ft_islower \
			 ft_isprint \
			 ft_isspace \
			 ft_isupper \
			 ft_iswhitespace \
			 ft_itoa \
			 ft_lstadd \
			 ft_lstdel \
			 ft_lstdelone \
			 ft_lstdup \
			 ft_lstdupone \
			 ft_lstenqueue \
			 ft_lstdequeue_del \
			 ft_lstiter \
			 ft_lstmap \
			 ft_lstnew \
			 ft_memalloc \
			 ft_memccpy \
			 ft_memchr \
			 ft_memcmp \
			 ft_memcpy \
			 ft_memdel \
			 ft_memmove \
			 ft_memset \
			 ft_putchar \
			 ft_putchar_fd \
			 ft_putendl \
			 ft_putendl_fd \
			 ft_putnbr \
			 ft_putunbr \
			 ft_putnbr_fd \
			 ft_putstr \
			 ft_putstr_fd \
			 ft_strcat \
			 ft_strchr \
			 ft_strclr \
			 ft_strcmp \
			 ft_strcpy \
			 ft_strdel \
			 ft_strdup \
			 ft_strequ \
			 ft_striter \
			 ft_striteri \
			 ft_strjoin \
			 ft_strlcat \
			 ft_strlen \
			 ft_strmap \
			 ft_strmapi \
			 ft_strncat \
			 ft_strncmp \
			 ft_strrevncmp \
			 ft_strncpy \
			 ft_strnequ \
			 ft_strnew \
			 ft_strnstr \
			 ft_strrchr \
			 ft_strsplit \
			 ft_strstr \
			 ft_chunkcmp \
			 ft_strsub \
			 ft_strtabdel \
			 ft_strtabnew \
			 ft_strtrim \
			 ft_tolower \
			 ft_toupper \
			 ft_inttabmax \
			 gnl \
			 get_next_line \
			 ft_iputchar \
			 ft_iputxchar \
			 ft_iputnbr_base \
			 ft_iputunbr_base \
			 ft_iputstr \
			 ft_iputnstr \
			 ft_dmod \
			 ft_ldmod \
			 ft_dabs \
			 ft_ldabs \
			 ft_ldfrexp \
			 ft_dfrexp \
			 ft_ldexp \
			 ft_dexp \
			 ft_isnan \
			 ft_isinf \
			 ft_isdigit \
			 ft_isspace \
			 ft_dclassify \
			 ft_signbit \
			 ft_iputwchar \
			 ft_iputwstr \
			 ft_iputnwstr \
			 ft_atoui \
			 ft_wstrlen \
			 ft_wcharlen \
			 ft_ld_ldiglen \
			 ft_ull \
			 ft_udigitlen \
			 ft_printf \
			 ft_parse \
			 ft_converter \
			 ft_dorounding \
			 ft_idisnull \
			 ft_isid \
			 ft_isfm \
			 ft_iputldnbr \
			 ft_simuldnbr \
			 ft_pprocess0 \
			 ft_pprocess1 \
			 ft_pprocess2 \
			 ft_pprocess3 \
			 ft_pprocess4 \
			 ft_print0 \
			 ft_print1 \
			 ft_print2 \
			 ft_print3 \
			 ft_printcolor \
			 ft_wcalc \
			 ft_wprocess0 \
			 ft_wprocess1 \
			 ft_wprocess2 \
			 ft_wprocess3 \
			 ft_wprocess4 \
			 ft_strchrindex \
			 ft_charinset \
			 ft_strcspn \
			 ft_strspn \
			 ft_power \
			 ft_strisnum \
			 ft_sqrt

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

$(NAME): $(OBJ) $(H_FILES) $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\r$(EOLCLR)$(NAME): $(GREEN)$(OK)\n"

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\r$(EOLCLR)$(NAME): $< $(BLUE)$(OK)"
	@$(CC) -o $@ -c $< $(HEADER) $(FLAGS)

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
