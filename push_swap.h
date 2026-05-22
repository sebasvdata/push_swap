/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by youssef           #+#    #+#             */
/*   Updated: 2026/05/22 19:51:36 by yoben-ch         ###   ########.fr       */
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

typedef struct s_option
{
        int   bench;
	int   simple;
	int   medium;
	int   complx;
        int   adaptive;	
}               t_option;

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
t_stack	*ft_verfier(char *s[], int l,int skip);
int ft_strcmp(char *s1,char *s2);
void ft_op(t_option *p);
int already_option(t_option *p);
int ft_option(char *s,t_option *p);

#endif
