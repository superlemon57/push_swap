/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:37 by mledda            #+#    #+#             */
/*   Updated: 2026/02/16 20:09:35 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf/ft_printf.h"

typedef struct s_count_flags
{
		int bench;
		int simple;
		int medium;
		int complex;
		int adaptive;
	} t_count_flag;

	// type booleen
typedef enum
{
	false, //0
	true //1
}Bool;

// definition d une pile
typedef struct StackElement
{
	int index;
	int value;
	struct StackElement	*prev;
	struct StackElement *next;
}StackElement, *Stack;

typedef struct s_count_operations
{
		int     count_pa;
		int     count_pb;
		int     count_sa;
		int     count_sb;
		int     count_ss;
		int     count_ra;
		int     count_rb;
		int     count_rr;
		int     count_rra;
		int     count_rrb;
		int     count_rrr;
} t_count_operations;

int		isbench(char *s);
int		issimple(char *s);
int		ismedium(char *s);
int		iscomplex(char *s);
int		isadaptive(char *s);
Stack	new_stack(void);
Bool	is_empty_stack(Stack st);
Stack	push_stack(Stack st, int x);
char	*ft_strjoin_space(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char    *add_argv(int argc, char **argv);
int		check_s(char *s);
int 	check_flags(t_count_flag j);
t_count_flag ft_count_flags(int argc, char **argv);
void	free_split(char **arrays);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
void	print_stack(Stack st);
StackElement	*stack_a(char *s);
int	ft_atoi_mod( char *str);
void    ss(StackElement **a, StackElement **b);
void    sb(StackElement **b);
void    sa(StackElement **a);
void    swap(StackElement **s);
int	no_duplicate(StackElement *a);
StackElement	*new_node(int value);
void	free_stack(StackElement *lst);
void    pb(StackElement **a, StackElement **b);
void    pa(StackElement **a, StackElement **b);
void    push(StackElement **src, StackElement **dest);
void    reverse_rotate(StackElement **s);
void    rra(StackElement **a);
void    rrb(StackElement **b);
void    rrr(StackElement **a, StackElement **b);
void    rotate(StackElement **s);
void    ra(StackElement **a);
void    rb(StackElement **b);
void    rr(StackElement **a, StackElement **b);
void    swap(StackElement **s);
void    sa(StackElement **a);
void    sb(StackElement **b);
void    ss(StackElement **a, StackElement **b);
void	swaparr(int *a, int *b);
int		partition(int arr[], int low, int high);
void	quick_sort(int arr[], int low, int high);
//static void	fill_index(StackElement *a, int *arr, int n);
int		indexation(StackElement **a);
int		find_min(StackElement *a);
int		find_max(StackElement *a);
int		is_sorted(StackElement *a);
int		stack_size(StackElement *s);
int		get_bucket_size(int n);
void	transfert_a_to_b(StackElement **a, StackElement **b);
int		find_max_index(StackElement *b);
void	push_b_to_a(StackElement **b, StackElement **a);
void	bucket_sort(StackElement **a);
int		get_pos(StackElement *stack, int target_index);
int		stack_size(StackElement *s);
void	radix_sort(StackElement **a, StackElement **b);
void	simple_sort(StackElement **a, StackElement **b);

#endif
