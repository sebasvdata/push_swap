/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by youssef           #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack *a)
{
	if (a->top != 1)
		return ;
	if (a->tab[1] > a->tab[0])
		swap_stack(a, 'a');
}

void	sort_3(t_stack *a)
{
	if (a->tab[2] == 0 && a->tab[0] == 1)
	{
		swap_stack(a, 'a');
		rotate_stack(a, 'a');
	}
	else if (a->tab[2] == 1 && a->tab[0] == 0)
		re_rotate_stack(a, 'a');
	else if (a->tab[2] == 1 && a->tab[0] == 2)
		swap_stack(a, 'a');
	else if (a->tab[2] == 2 && a->tab[0] == 1)
		rotate_stack(a, 'a');
	else if (a->tab[2] == 2 && a->tab[0] == 0)
	{
		rotate_stack(a, 'a');
		swap_stack(a, 'a');
	}
}

void	sort_4(t_stack *a, t_stack *b)
{
	if (a->top != 3)
		return ;
	min_moves(a, b, 0);
	coordinate_stack(a);
	sort_3(a);
	push_in(b, a, 'a');
}

void	sort_5(t_stack *a, t_stack *b)
{
	int	first;

	if (a->top != 4)
		return ;
	first = first_to_push(a);
	min_moves(a, b, first);
	min_moves(a, b, !first);
	coordinate_stack(a);
	sort_3(a);
	push_in(b, a, 'a');
	push_in(b, a, 'a');
	if (a->tab[4] > a->tab[3])
		swap_stack(a, 'a');
}

void	basic_case(t_stack *a, t_stack *b, int size)
{
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
