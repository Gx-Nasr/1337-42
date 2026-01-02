# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-adao <nel-adao@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/20 15:45:45 by nel-adao          #+#    #+#              #
#    Updated: 2025/12/31 11:33:34 by nel-adao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker

CFLAGS = -Wall -Wextra -Werror

SRC = hard_sort.c push_swap_rules1.c push_swap_rules2.c \
      push_swap_rules3.c push_swap_utils.c sorting.c \
      sorting_utils.c push_swap.c

BONUS_SRC = bonus/checker.c bonus/checker_rules1.c \
            bonus/checker_rules2.c bonus/checker_rules3.c \
            bonus/checker_utils.c bonus/get_rules.c \
            bonus/sorting.c bonus/sorting_utils.c

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	cc $(CFLAGS) -o $(NAME) $(OBJ)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	cc $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ)

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

.SECONDARY: $(OBJ) $(BONUS_OBJ)
