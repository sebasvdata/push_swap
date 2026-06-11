/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 01:22:03 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/12 00:59:25 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	low_n_sort(t_stack *a, t_stack *b, t_benchmark *bench)
{
	if (a->top == 1)
	{
		swap_stack(a, 'a');
		(bench->sa)++;
	}
	if (a->top == 2)
	{
		order_three(a, bench);
	}
	else if (a->top < 5)
		order_five(a, b, bench);
}

void	ft_adaptive(t_stack *a, t_stack *b, t_benchmark *bench)
{
	if (a->top < 5)
		return (low_n_sort(a, b, bench));
	if (bench->disorder < 2000)
		ft_simple(a, b, bench);
	else if (bench->disorder >= 2000 && bench->disorder < 5000)
		ft_medium(a, b, bench);
	else
		radix_sort(a, b, bench);
}
