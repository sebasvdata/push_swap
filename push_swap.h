/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 00:00:00 by youssef           #+#    #+#             */
/*   Updated: 2026/06/11 01:20:18 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_stack
{
	int	*tab;
	int	size;
	int	top;
}	t_stack;

typedef struct s_option
{
	int	bench;
	int	simple;
	int	medium;
	int	complex;
	int	adaptive;
}	t_option;

typedef struct s_benchmark
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		disorder;
	char	*strategy;
}	t_benchmark;

char	*get_next_line(int fd);
int		ft_disorder(t_stack *a);
int		decide_algorithm(t_stack *a, t_stack *b, t_option *op);
int		normalize_stack(t_stack *a);
t_stack	*create_stack(int size);
int		push_stack(t_stack *s, int value);
int		pop(t_stack *s);
int		search_stack(t_stack *a, int value);
t_stack	*destroy_stack(t_stack *a);
void	display_bench(t_benchmark *bench);
int		ft_count_words(char *s, char c);
char	**ft_split(char *s, char c);
int		ft_strlen(char *s);
t_stack	*ft_verifier(char *s[], int l, int skip);
int		ft_skip(t_option *op, char **av, int ac);
char	*join_args(char **av, int ac);
char	*ft_strdup(char *s);
void	free_split(char **split);
int		liberty(t_stack *a, t_stack *b, char **splited);
int		init_stack(char ***av, int *ac);
int		ft_error(t_stack *a, t_stack *b, char **av);
int		ft_is_sorted(t_stack *a);
int		ft_printf(const char *s, ...);
int		ft_strcmp(char *s1, char *s2);
int		swap_stack(t_stack *a, char c);
int		push_in(t_stack *src, t_stack *dest, char c);
int		re_rotate_stack(t_stack *a, char c);
int		rotate_stack(t_stack *a, char c);
void	ft_simple(t_stack *a, t_stack *b, t_benchmark *bench);
void	ft_medium(t_stack *a, t_stack *b, t_benchmark *bench);
void	radix_sort(t_stack *a, t_stack *b, t_benchmark *bench);
void	ft_bzero(void *p, size_t size);
int		radix_base(int nb);
int		radix_digit(int n, int base);
int		radix_next_digits(t_stack *a, int *upper, int *bottom);
int		radix_smart_rotate(t_stack *a, t_stack *b, t_benchmark *bench, int rr);
void	radix_push_digit(t_stack *a, t_stack *b, t_benchmark *bench, int *rr);
void	ft_adaptive(t_stack *a, t_stack *b, t_benchmark *bench);

#endif
