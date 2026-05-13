/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_cases_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by youssef           #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_cost(t_stack *a, int value)
{
	int	i;

	i = 0;
	while (i <= a->top)
	{
		if (a->tab[i] == value)
			return (i >= (a->top / 2));
		i++;
	}
	return (0);
}

void	min_moves(t_stack *a, t_stack *b, int value)
{
	if (count_cost(a, value))
	{
		while (a->tab[a->top] != value)
			rotate_stack(a, 'a');
	}
	else
	{
		while (a->tab[a->top] != value)
			re_rotate_stack(a, 'a');
	}
	push_in(a, b, 'b');
}

int	first_to_push(t_stack *a)
{
	int	i;

	i = a->top;
	while (i >= (a->top / 2))
	{
		if (a->tab[i] == 1 || a->tab[i] == 0)
			return (a->tab[i]);
		i--;
	}
	while (i >= 0)
	{
		if (a->tab[i] == 1 || a->tab[i] == 0)
			return (!(a->tab[i]));
		i--;
	}
	return (0);
}
