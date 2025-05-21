/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoh <lkoh@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:43:16 by lkoh              #+#    #+#             */
/*   Updated: 2024/11/01 20:32:22 by lkoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_node
{
	long			value;
	int				rank;
	int				base3;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	int				fullsize;
	int				size;
	int				state;
	struct s_node	*head;
}					t_stack;

char				**ft_split(char const *s, char c);
int					ft_strlen(const char *str);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
void				ft_putstr_fd(char *s, int fd);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *s);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
long				ft_atol(const char *str);
int					ft_isdigit(int c);

// swap
void				swap(t_stack *stack);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);

// push
t_node				*getsrcnode(t_stack *src);
void				push(t_stack *src, t_stack *dest);
void				pa(t_stack *stack_b, t_stack *stack_a);
void				pb(t_stack *stack_a, t_stack *stack_b);

// rotate
void				rotate(t_stack *stack);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);

// rev rotate
void				reverse_rotate(t_stack *stack);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);

// sort small
void				sort_3(t_stack *stack);
void				movehelper(t_stack *stack_a, t_stack *stack_b, int i);
t_node				*move_to_a(t_stack *stack_a, t_stack *stack_b, int b_top,
						int j);
t_node				*move_0_top(t_stack *stack_a, int i);
void				sort_n(t_stack *stack_a, t_stack *stack_b);

// checks
int					valid_integer(const char *str);
int					check_sorted(t_stack *stack);

// helper
void				print2stack(t_stack *sa, t_stack *sb);
void				printstack(t_stack *stack);
int					count_base3_digits(unsigned long n);
long				to_base_3(unsigned long n);
int					base_3(unsigned long n, int pos);

// init
void				initstk(t_stack *stk_a, t_stack *stk_b);
int					poocess_arg(char **argv, t_stack *stk_a);
int					poocess_in(char **temp, t_stack *stk_a);
void				ranking(t_stack *stack);
int					add_node(t_node *new_node, t_stack *stk);

// free
void				ft_free_split(char **split);
void				free_stack(t_stack *stk);

// radix sort
void				radix_nlr(t_stack *stack_a, t_stack *stack_b, int sf);
void				radix_nlr2(t_stack *stack_a, t_stack *stack_b, int sf);
void				radix_nrl(t_stack *stack_a, t_stack *stack_b, int sf);
void				radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif