/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adaptive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 01:22:03 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/11 01:22:05 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_adaptive(t_stack *a, t_stack *b, t_benchmark *bench)
{
	if (bench->disorder < 2000)
		ft_simple(a, b, bench);
	else if (bench->disorder >= 2000 && bench->disorder < 5000)
		ft_medium(a, b, bench);
	else
		radix_sort(a, b, bench);
}
