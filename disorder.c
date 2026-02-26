/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mledda <mledda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:49:02 by mledda            #+#    #+#             */
/*   Updated: 2026/02/26 16:09:38 by mledda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	compute_disorder_indexed(StackElement *a)
{
	long			mistakes;
	long			total;
	StackElement	*outer;
	StackElement	*inner;

	if (!a || !a->next)
		return (0.0);
	mistakes = 0;
	total = 0;
	outer = a;
	while (outer->next)
	{
		inner = outer->next;
		while (inner)
		{
			total++;
			if (outer->index > inner->index)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return ((float)mistakes / total);
}
void	choose_
float disorder = compute_disorder_indexed(stack_a);

if (isbench(argv[i]))
	ft_fprintf_fd(2, "Disorder: %.2f%%\n", disorder * 100);
if (disorder < 0.2)
	simple_sort(&a, &ops);
else if (disorder < 0.5)
	bucket_sort(&a, &ops));
else
	radix_sort(&a, &ops));

