# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 20:12:34 by manuelbeele       #+#    #+#              #
#    Updated: 2021/11/02 20:24:28 by manuelbeele      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./btree_apply_infix.c
SRCS += ./btree_apply_prefix.c
SRCS += ./btree_apply_suffix.c
SRCS += ./btree_create_node.c
SRCS += ./btree_insert_data.c
SRCS = ./ft_any.c
SRCS += ./ft_atoi.c
SRCS += ./ft_count_if.c
SRCS += ./ft_create_elem.c
SRCS += ./ft_fibonacci.c
SRCS = ./ft_find_next_prime.c
SRCS += ./ft_foreach.c
SRCS += ./ft_is_prime.c
SRCS += ./ft_is_sort.c
SRCS += ./ft_list_at.c
SRCS = ./ft_list_clear.c
SRCS += ./ft_list_last.c
SRCS += ./ft_list_push_back.c
SRCS += ./ft_list_push_front.c
SRCS += ./ft_list_push_params.c
SRCS = ./ft_list_size.c
SRCS += ./ft_map.c
SRCS += ./ft_print_words_tables.c
SRCS += ./ft_putchar.c
SRCS += ./ft_putnbr.c
SRCS = ./ft_putstr.c
SRCS += ./ft_range.c
SRCS += ./ft_split_whitespaces.c
SRCS += ./ft_sqrt.c
SRCS += ./ft_strcmp.c
SRCS = ./ft_strcpy.c
SRCS += ./ft_strdup.c
SRCS += ./ft_strlen.c
SRCS += ./ft_strlowcase.c
SRCS += ./ft_strncmp.c
SRCS = ./ft_strncpy.c
SRCS += ./ft_strstr.c
SRCS += ./ft_strupcase.c
SRCS += ./ft_swap.c
SRCS += ./ft_ultimate_range.c

FLAGS = -Wall -Wextra -Werror -c -I ./libft.h

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS)
	ar rc $(NAME) *.o

.PHONY: clean fclean re

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
