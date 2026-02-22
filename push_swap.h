/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:37 by mledda            #+#    #+#             */
/*   Updated: 2026/02/22 16:51:49 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf_fd/ft_printf_fd.h"

typedef struct s_count_flags
{
	int bench;
	int simple;
	int medium;
	int complex;
	int adaptive;
}	t_count_flag;

typedef enum
{
	false,
	true
}	Bool;

typedef struct StackElement
{
	int					index;
	int					value;
	struct StackElement	*prev;
	struct StackElement	*next;
}	StackElement, *Stack;

typedef struct s_count_operations
{
	int	count_pa;
	int	count_pb;
	int	count_sa;
	int	count_sb;
	int	count_ss;
	int	count_ra;
	int	count_rb;
	int	count_rr;
	int	count_rra;
	int	count_rrb;
	int	count_rrr;
}	t_count_operations;

/* flags */
int					isbench(char *s);
int					issimple(char *s);
int					ismedium(char *s);
int					iscomplex(char *s);
int					isadaptive(char *s);
int					check_flags(t_count_flag j);
t_count_flag		ft_count_flags(int argc, char **argv);

/* stack basics */
Stack				new_stack(void);
Bool				is_empty_stack(Stack st);
StackElement		*new_node(int value);
void				free_stack(StackElement *lst);
int					stack_size(StackElement *s);
void				print_stack(Stack st);

/* stack creation */
StackElement		*stack_a(char *s);
int					no_duplicate(StackElement *a);
void				free_split(char **arrays);

/* utils */
char				*ft_strjoin_space(char const *s1, char const *s2);
char				*ft_strdup(const char *s);
size_t				ft_strlen(const char *str);
char				*add_argv(int argc, char **argv);
int					check_s(char *s);
char				**ft_split(char const *s, char c);
int					ft_atoi(const char *str);
int					ft_atoi_mod(char *str);

/* indexation */
void				swaparr(int *a, int *b);
int					partition(int arr[], int low, int high);
void				quick_sort(int arr[], int low, int high);
int					indexation(StackElement **a);

/* sort helpers */
int					find_min(StackElement *a);
int					find_max(StackElement *a);
int					is_sorted(StackElement *a);
int					get_bucket_size(int n);
int					find_max_index(StackElement *b);
int					get_pos(StackElement *stack, int target_index);

/* operations - swap */
void				swap(StackElement **s);
void				sa(StackElement **a, t_count_operations *ops);
void				sb(StackElement **b, t_count_operations *ops);
void				ss(StackElement **a, StackElement **b, t_count_operations *ops);

/* operations - push */
void				push(StackElement **src, StackElement **dest);
void				pa(StackElement **a, StackElement **b, t_count_operations *ops);
void				pb(StackElement **a, StackElement **b, t_count_operations *ops);

/* operations - rotate */
void				rotate(StackElement **s);
void				ra(StackElement **a, t_count_operations *ops);
void				rb(StackElement **b, t_count_operations *ops);
void				rr(StackElement **a, StackElement **b, t_count_operations *ops);

/* operations - reverse rotate */
void				reverse_rotate(StackElement **s);
void				rra(StackElement **a, t_count_operations *ops);
void				rrb(StackElement **b, t_count_operations *ops);
void				rrr(StackElement **a, StackElement **b, t_count_operations *ops);

/* sorts */
void				transfert_a_to_b(StackElement **a, StackElement **b, t_count_operations *ops);
void				push_b_to_a(StackElement **b, StackElement **a, t_count_operations *ops);
void				bucket_sort(StackElement **a, t_count_operations *ops);
void				radix_sort(StackElement **a, StackElement **b, t_count_operations *ops);
void				bring_to_top(StackElement **a, int pos, t_count_operations *ops);
void				sort_three(StackElement **a, t_count_operations *ops);
void				simple_sort(StackElement **a, t_count_operations *ops);

/* operations counter */
void				init_operations(t_count_operations *ops);
void				print_operations(t_count_operations *ops);

#endif
