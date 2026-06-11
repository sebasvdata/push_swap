/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:37:24 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/10 23:37:24 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	radix_base(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}

int	radix_digit(int n, int base)
{
	return (n / base);
}

int	radix_smart_rotate(t_stack *a, t_stack *b, t_benchmark *bench, int rr)
{
	if (rr && b->top >= 1)
	{
		rotate_stack(b, 0);
		rotate_stack(a, 'r');
		(bench->rr)++;
	}
	else
	{
		rotate_stack(a, 'a');
		(bench->ra)++;
	}
	return (0);
}

int	radix_next_digits(t_stack *a, int *upper, int *bottom)
{
	int	j;
	int	digit;
	int	base;

	j = 0;
	base = radix_base(a->size);
	while (j <= a->top)
	{
		digit = radix_digit(a->tab[j], base);
		if (digit == *upper || digit == *bottom)
			return (0);
		j++;
	}
	(*upper)++;
	(*bottom)--;
	return (1);
}

void	radix_push_digit(t_stack *a, t_stack *b, t_benchmark *bench, int *rr)
{
	if (*rr && b->top >= 1)
	{
		rotate_stack(b, 'b');
		(bench->rb)++;
	}
	push_in(a, b, 'b');
	(bench->pb)++;
	*rr = 0;
}
