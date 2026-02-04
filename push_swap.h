/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:47:37 by mledda            #+#    #+#             */
/*   Updated: 2026/02/04 12:38:06 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
//int check_flags(int argc, char **argv);
char    *add_argv(int argc, char **argv);
int		check_s(char *s);
int 	check_flags(t_count_flag j);
t_count_flag ft_count_flags(int argc, char **argv);


#endif
