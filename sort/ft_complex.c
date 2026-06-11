/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complix_utilts.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:37:24 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/10 23:37:24 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	better_cost(t_stack *b, int min)
{
	int	i;

	i = b->top;
	while (i >= 0 && b->tab[i] != min)
		i--;
	if (i < 0)
		return (1);
	return ((b->top - i) <= i);
}

static void	rotate_to_next(t_stack *b, int min, t_benchmark *bench)
{
	int	rotation;

	rotation = better_cost(b, min);
	while (b->tab[b->top] != min && b->tab[b->top] != min - 1)
	{
		if (rotation)
		{
			rotate_stack(b, 'b');
			(bench->rb)++;
		}
		else
		{
			re_rotate_stack(b, 'b');
			(bench->rrb)++;
		}
	}
}

static void	move_back(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	min;

	min = b->top;
	while (b->top > -1)
	{
		rotate_to_next(b, min, bench);
		push_in(b, a, 'a');
		(bench->pa)++;
		if (a->top >= 1 && a->tab[a->top] > a->tab[a->top - 1])
		{
			swap_stack(a, 'a');
			(bench->sa)++;
		}
		while (b->top > -1 && !search_stack(b, min))
			min--;
	}
}

void	radix_sort(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	base;
	int	upper;
	int	bottom;
	int	digit;
	int	rr;

	base = radix_base(a->size);
	upper = base / 2;
	bottom = upper - 1;
	rr = 0;
	while (a->top > -1)
	{
		digit = radix_digit(a->tab[a->top], base);
		if (digit == upper || digit == bottom)
		{
			radix_push_digit(a, b, bench, &rr);
			if (digit == bottom)
				rr = 1;
		}
		else
			rr = radix_smart_rotate(a, b, bench, rr);
		radix_next_digits(a, &upper, &bottom);
	}
	move_back(a, b, bench);
}
