/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:37:11 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/11 01:14:47 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	do_push_rotate(char *s, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(s, "pa\n"))
		return (push_in(b, a, 0));
	else if (!ft_strcmp(s, "pb\n"))
		return (push_in(a, b, 0));
	else if (!ft_strcmp(s, "ra\n"))
		return (rotate_stack(a, 0));
	else if (!ft_strcmp(s, "rb\n"))
		return (rotate_stack(b, 0));
	else if (!ft_strcmp(s, "rr\n"))
		return (rotate_stack(a, 0) && rotate_stack(b, 0));
	return (0);
}

static int	do_reverse_swap(char *s, t_stack *a, t_stack *b)
{
	if (!ft_strcmp(s, "rra\n"))
		return (re_rotate_stack(a, 0));
	else if (!ft_strcmp(s, "rrb\n"))
		return (re_rotate_stack(b, 0));
	else if (!ft_strcmp(s, "rrr\n"))
		return (re_rotate_stack(a, 0) && re_rotate_stack(b, 0));
	else if (!ft_strcmp(s, "sa\n"))
		return (swap_stack(a, 0));
	else if (!ft_strcmp(s, "sb\n"))
		return (swap_stack(b, 0));
	else if (!ft_strcmp(s, "ss\n"))
		return (swap_stack(a, 0) && swap_stack(b, 0));
	return (0);
}

static int	ft_operation(char *s, t_stack *a, t_stack *b)
{
	if (do_push_rotate(s, a, b))
		return (1);
	if (do_reverse_swap(s, a, b))
		return (1);
	return (0);
}

static int	check_operation(t_stack *a, t_stack *b)
{
	char	*s;

	s = get_next_line(0);
	while (s)
	{
		if (ft_operation(s, a, b))
		{
			free(s);
			s = get_next_line(0);
		}
		else
		{
			free(s);
			return (0);
		}
	}
	if (ft_is_sorted(a) && b->top == -1)
		return (write(1, "OK\n", 3));
	return (write(1, "KO\n", 3));
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	if (init_stack(&av, &ac))
		return (ft_error(NULL, NULL, av));
	a = ft_verifier(av, ac, 0);
	if (!a)
		return (ft_error(NULL, NULL, av));
	if (a->top < 1 || ft_is_sorted(a))
		return (liberty(a, NULL, av), write(1, "OK\n", 3));
	b = create_stack(ac - 1);
	if (!b)
		return (ft_error(a, NULL, av));
	if (!check_operation(a, b))
		return (ft_error(a, b, av));
	liberty(a, b, av);
	return (0);
}
