/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:37 by mledda            #+#    #+#             */
/*   Updated: 2026/02/11 14:08:53 by mledda           ###   ########.fr       */
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

	int place;
	int value;
	struct StackElement	*prev;
	struct StackElement *next;
}StackElement, *Stack;

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




#endif
