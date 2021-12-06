# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 20:12:34 by manuelbeele       #+#    #+#              #
#    Updated: 2021/11/26 20:22:20 by manuelbeele      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ./btree_apply_infix.c
SRCS += ./btree_apply_prefix.c
SRCS += ./btree_apply_suffix.c
SRCS += ./btree_create_node.c
SRCS += ./btree_insert_data.c
SRCS += ./ft_any.c
SRCS += ./ft_atoi.c
SRCS += ./ft_bzero.c
SRCS += ./ft_count_if.c
SRCS += ./ft_create_elem.c
SRCS += ./ft_fibonacci.c
SRCS += ./ft_find_next_prime.c
SRCS += ./ft_foreach.c
SRCS += ./ft_is_prime.c
SRCS += ./ft_is_sort.c
SRCS += ./ft_isalnum.c
SRCS += ./ft_isalpha.c
SRCS += ./ft_isascii.c
SRCS += ./ft_isdigit.c
SRCS += ./ft_isprint.c
SRCS += ./ft_itoa.c
SRCS += ./ft_list_at.c
SRCS += ./ft_list_last.c
SRCS += ./ft_list_push_back.c
SRCS += ./ft_list_push_front.c
SRCS += ./ft_list_push_params.c
SRCS += ./ft_list_size.c
SRCS += ./ft_lstadd.c
SRCS += ./ft_lstclearelem.c
SRCS += ./ft_lstdel.c
SRCS += ./ft_lstdelone.c
SRCS += ./ft_lstiter.c
SRCS += ./ft_lstmap.c
SRCS += ./ft_lstnew.c
SRCS += ./ft_map.c
SRCS += ./ft_memalloc.c
SRCS += ./ft_memccpy.c
SRCS += ./ft_memchr.c
SRCS += ./ft_memcmp.c
SRCS += ./ft_memcpy.c
SRCS += ./ft_memdel.c
SRCS += ./ft_memdelarray.c
SRCS += ./ft_memmove.c
SRCS += ./ft_memset.c
SRCS += ./ft_print_words_tables.c
SRCS += ./ft_putchar_fd.c
SRCS += ./ft_putchar.c
SRCS += ./ft_putendl_fd.c
SRCS += ./ft_putendl.c
SRCS += ./ft_putnbr_fd.c
SRCS += ./ft_putnbr.c
SRCS += ./ft_putstr_fd.c
SRCS += ./ft_putstr.c
SRCS += ./ft_range.c
SRCS += ./ft_split_whitespaces.c
SRCS += ./ft_sqrt.c
SRCS += ./ft_strcat.c
SRCS += ./ft_strchr.c
SRCS += ./ft_strclr.c
SRCS += ./ft_strcmp.c
SRCS += ./ft_strcpy.c
SRCS += ./ft_strdel.c
SRCS += ./ft_strdelarray.c
SRCS += ./ft_strdup.c
SRCS += ./ft_strequ.c
SRCS += ./ft_striter.c
SRCS += ./ft_striteri.c
SRCS += ./ft_strjoin.c
SRCS += ./ft_strlcat.c
SRCS += ./ft_strlen.c
SRCS += ./ft_strlowcase.c
SRCS += ./ft_strmap.c
SRCS += ./ft_strmapi.c
SRCS += ./ft_strncat.c
SRCS += ./ft_strncmp.c
SRCS += ./ft_strncpy.c
SRCS += ./ft_strnequ.c
SRCS += ./ft_strnew.c
SRCS += ./ft_strnstr.c
SRCS += ./ft_strrchr.c
SRCS += ./ft_strsplit.c
SRCS += ./ft_strstr.c
SRCS += ./ft_strsub.c
SRCS += ./ft_strtrim.c
SRCS += ./ft_strupcase.c
SRCS += ./ft_swap.c
SRCS += ./ft_tolower.c
SRCS += ./ft_toupper.c
SRCS += ./ft_ultimate_range.c
SRCS += ./ft_strchrloc.c
SRCS += ./ft_strmove.c
SRCS += ./ft_strndup.c
SRCS += ./ft_strnjoin.c

OBJECTS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror -c

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $<

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
