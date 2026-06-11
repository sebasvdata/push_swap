/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:37:31 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/11 02:33:55 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	verfier_before_joining(char **s, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac)
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] != ' ')
				break ;
			j++;
		}
		if (!(s[i][j]))
			return (1);
		i++;
	}
	return (0);
}

int	liberty(t_stack *a, t_stack *b, char **splited)
{
	if (a)
		destroy_stack(a);
	if (b)
		destroy_stack(b);
	if (splited)
		free_split(splited);
	return (1);
}

int	init_stack(char ***av, int *ac)
{
	char	*joined;

	if (verfier_before_joining(*av, *ac))
	{
		*av = NULL;
		return (1);
	}
	joined = join_args(*av, *ac);
	if (!joined)
		return (1);
	*av = ft_split(joined, ' ');
	if (!(*av))
		return (1);
	*ac = ft_count_words(joined, ' ');
	free(joined);
	return (0);
}

int	ft_error(t_stack *a, t_stack *b, char **av)
{
	liberty(a, b, av);
	write(2, "Error\n", 6);
	return (1);
}

int	ft_is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->tab[i] < a->tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
