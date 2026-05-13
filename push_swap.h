/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by youssef           #+#    #+#             */
/*   Updated: 2026/05/13 00:00:00 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*tab;
	int	size;
	int	top;
}		t_stack;
t_stack	*create_stack(int size);
int		search_stack(t_stack *a, int value);
t_stack	*destroy_stack(t_stack *a);
t_stack	*ft_copy_stack(t_stack *a);
int		push_stack(t_stack *s, int value);
int		pop(t_stack *s);
void	swap_stack(t_stack *a, char c);
void	push_in(t_stack *src, t_stack *dest, char c);
void	re_rotate_stack(t_stack *a, char c);
void	rotate_stack(t_stack *a, char c);
int		ft_strlen(char *s);
int		ft_error(t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *a);
int		ft_parse(char *s, int *out);
t_stack	*ft_verfier(char *s[], int l);
void	recursive_merge(int *tab, int start, int end);
t_stack	*merge_sort(t_stack *a);
int		coordinate_stack(t_stack *a);
int		bits_represtntion(int n);
void	divied_by2(t_stack *a);
void	min_moves(t_stack *a, t_stack *b, int value);
int		first_to_push(t_stack *a);
void	sort_2(t_stack *a);
void	sort_3(t_stack *a);
void	sort_4(t_stack *a, t_stack *b);
void	sort_5(t_stack *a, t_stack *b);
void	basic_case(t_stack *a, t_stack *b, int size);

#endif
