/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_genral.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:37:31 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/12 01:16:45 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_disorder(t_stack *a)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	if (a->top < 1)
		return (0);
	mistakes = 0;
	total_pairs = 0;
	i = a->top;
	while (i >= 0)
	{
		j = i - 1;
		while (j >= 0)
		{
			total_pairs += 1;
			if (a->tab[i] > a->tab[j])
				mistakes += 1;
			j--;
		}
		i--;
	}
	return ((mistakes / total_pairs) * 10000);
}

void	ft_bzero(void *p, size_t size)
{
	char	*s;

	s = (char *)p;
	while (size--)
		*(s++) = '\0';
}

static char	*strategy_bench(int n)
{
	if (n < 2000)
		return ("Adaptive / O(n^2)");
	else if (n >= 2000 && n < 5000)
		return ("Adaptive / O(n sqrt(n))");
	return ("Adaptive / O(n log(n))");
}

static t_benchmark	*init_bench(t_stack *a, t_option *op)
{
	t_benchmark	*bench;

	bench = malloc(sizeof(t_benchmark));
	if (!bench)
		return (NULL);
	ft_bzero(bench, sizeof(t_benchmark));
	bench->disorder = ft_disorder(a);
	if (op->simple)
		bench->strategy = "Simple / O(n^2)";
	else if (op->medium)
		bench->strategy = "Medium / O(n sqrt(n))";
	else if (op->complex)
		bench->strategy = "Complex / O(n log(n))";
	else
		bench->strategy = strategy_bench(ft_disorder(a));
	return (bench);
}

int	decide_algorithm(t_stack *a, t_stack *b, t_option *op)
{
	t_benchmark	*bench;

	bench = init_bench(a, op);
	if (!bench)
		return (1);
	if (ft_is_sorted(a) || a->top < 1)
	{
		if (op->bench)
			display_bench(bench);
		return (free(bench), 0);
	}
	if (op->simple)
		ft_simple(a, b, bench);
	else if (op->medium)
		ft_medium(a, b, bench);
	else if (op->complex)
		radix_sort(a, b, bench);
	else
		ft_adaptive(a, b, bench);
	if (op->bench)
		display_bench(bench);
	free(bench);
	return (0);
}
