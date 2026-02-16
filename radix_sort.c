/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlopez <tlopez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 18:07:27 by tlopez            #+#    #+#             */
/*   Updated: 2026/02/16 18:34:53 by tlopez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * get_max_bits - Calcule le nombre de bits nécessaires pour représenter
 * l'index le plus élevé de la pile.
 * * @stack: Pointeur vers le premier élément de la pile.
 * Retourne: Le nombre de bits (ex: si max_index est 7 (111 en binaire), 
 * retourne 3).
 */
static int	get_max_bits(StackElement *stack)
{
	int	max_index;
	int	max_bits;

	max_index = 0;
	max_bits = 0;
	// On cherche l'index maximum dans la pile
	while (stack)
	{
		if (stack->index > max_index)
			max_index = stack->index;
		stack = stack->next;
	}
	// On décale les bits vers la droite jusqu'à atteindre 0 pour compter
	// la taille binaire du nombre.
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

/**
 * radix_sort - Algorithme de tri par base (Radix) utilisant les bits.
 * Le tri s'effectue bit par bit, du moins significatif (LSB) au plus
 * significatif (MSB).
 * * @a: Double pointeur vers la pile A.
 * @b: Double pointeur vers la pile B.
 */
void	radix_sort(StackElement **a, StackElement **b)
{
	int				i;      // Bit actuel que l'on examine
	int				j;      // Compteur pour parcourir la pile
	int				size;   // Taille initiale de la pile A
	int				max_bits;
	StackElement	*current;

	i = 0;
	size = stack_size(*a);
	max_bits = get_max_bits(*a);
	
	// On boucle sur chaque bit (de 0 jusqu'au bit maximum nécessaire)
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current = *a;
			// On vérifie si le i-ème bit de l'index est un 1 ou un 0
			// Si c'est un 1, on laisse le nombre dans la pile A (rotation)
			if (((current->index >> i) & 1) == 1)
				ra(a);
			// Si c'est un 0, on "isole" le nombre en l'envoyant dans la pile B
			else
				pb(a, b);
			j++;
		}
		// Une fois la pile A traitée pour ce bit, on rapatrie tous les
		// éléments de B vers A pour préparer le passage au bit suivant (i + 1)
		while (*b)
			pa(a, b);
		i++;
	}
}