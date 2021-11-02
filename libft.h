/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuelbeeler <manuelbeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:16:26 by manuelbeele       #+#    #+#             */
/*   Updated: 2021/11/02 20:08:57 by manuelbeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

void		btree_apply_infix(t_btree *root, void (*applyf) (void *));
void		btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void		btree_apply_suffix(t_btree *root, void (*applyf) (void *));
t_btree		*btree_create_node(void *item);
void		btree_insert_data(t_btree **root, void *item, \
			int (*cmpf) (void *, void *));
int			ft_any(char **tab, int (*f) (char*));
int			ft_atoi(char *str);
int			ft_count_if(char **tab, int (*f)(char*));
t_list		*ft_create_elem(void *data);
int			ft_fibonacci(int index);
int			ft_find_next_prime(int nb);
void		ft_foreach(int *tab, int length, void (*f)(int));
int			ft_is_prime(int nb);
int			ft_is_sort(int *tab, int length, int (*f) (int, int));
t_list		*ft_list_at(t_list *begin_list, unsigned int nbr);
void		ft_list_clear(t_list **begin_list);
t_list		*ft_list_last(t_list *begin_list);
void		ft_list_push_back(t_list **begin_list, void *data);
void		ft_list_push_front(t_list **begin_list, void *data);
t_list		*ft_list_push_params(int ac, char **av);
int			ft_list_size(t_list *begin_list);
int			*ft_map(int *tab, int length, int (*f) (int));
void		ft_print_words_tables(char **table);
void		ft_putchar(char c);
void		ft_putnbr(int nb);
void		ft_putstr(char *str);
int			*ft_range(int min, int max);
int			ft_sqrt(int nb);
int			ft_strcmp(char *s1, char *s2);
char		*ft_strcpy(char *dest, char *src);
char		*ft_strdup(char *src);
int			ft_strlen(char *str);
char		*ft_strlowcase(char *str);
int			ft_strncmp(char *s1, char *s2, unsigned int n);
char		*ft_strncpy(char *dest, char *src, unsigned int n);
char		*ft_strstr(char *str, char *to_find);
char		*ft_strupcase(char *str);
void		ft_swap(int *a, int *b);
int			ft_ultimate_range(int **range, int min, int max);
char		**ft_split_whitespaces(char *str);

#endif
