/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:37:31 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/11 02:42:02 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	t_option	op;

	if (ac < 2)
		return (0);
	if (init_stack(&av, &ac) || ft_skip(&op, av, ac) == -1)
		return (ft_error(NULL, NULL, av));
	a = ft_verifier(av, ac, ft_skip(&op, av, ac));
	if (!a || normalize_stack(a))
		return (ft_error(a, NULL, av));
	b = create_stack(ac - 1);
	if (!b)
		return (ft_error(a, NULL, av));
	decide_algorithm(a, b, &op);
	liberty(a, b, av);
	return (0);
}
