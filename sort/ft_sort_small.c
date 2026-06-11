/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stelescu <stelescu@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 12:19:32 by stelescu          #+#    #+#             */
/*   Updated: 2026/06/12 01:00:36 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	second_order_three(t_stack *a, t_benchmark *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = a->tab[a->top];
	mid = a->tab[a->top - 1];
	bot = a->tab[a->top - 2];
	if (top > mid && mid > bot && top > bot)
	{
		swap_stack(a, 'a');
		(bench->sa)++;
		re_rotate_stack(a, 'a');
		(bench->rra)++;
	}
	else if (top < mid && mid > bot && top < bot)
	{
		swap_stack(a, 'a');
		(bench->sa)++;
		rotate_stack(a, 'a');
		(bench->ra)++;
	}
}

void	order_three(t_stack *a, t_benchmark *bench)
{
	int	top;
	int	mid;
	int	bot;

	top = a->tab[a->top];
	mid = a->tab[a->top - 1];
	bot = a->tab[a->top - 2];
	if (top > mid && mid < bot && top < bot)
	{
		swap_stack(a, 'a');
		(bench->sa)++;
	}
	else if (top < mid && mid > bot && top > bot)
	{
		re_rotate_stack(a, 'a');
		(bench->rra)++;
	}
	else if (top > mid && mid < bot && top > bot)
	{
		rotate_stack(a, 'a');
		(bench->ra)++;
	}
	else
		second_order_three(a, bench);
}

static int	find_min(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (i <= a->top)
	{
		if (a->tab[i] < a->tab[min])
			min = i;
		i++;
	}
	return (a->top - min);
}

static void	push_smallest(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	min;

	min = find_min(a);
	if (min <= a->top / 2)
	{
		while (min--)
		{
			rotate_stack(a, 'a');
			(bench->ra)++;
		}
	}
	else
	{
		min = a->top - min + 1;
		while (min--)
		{
			re_rotate_stack(a, 'a');
			(bench->rra)++;
		}
	}
	push_in(a, b, 'b');
	(bench->pb)++;
}

void	order_five(t_stack *a, t_stack *b, t_benchmark *bench)
{
	while (a->top > 2)
	{
		push_smallest(a, b, bench);
	}
	order_three(a, bench);
	while (b->top > -1)
	{
		push_in(b, a, 'a');
		(bench->pa)++;
	}
}
