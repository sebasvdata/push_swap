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
void	swap_stack(t_stack *a);
void	push_in(t_stack *src, t_stack *dest);
void	re_rotate_stack(t_stack *a);
void	rotate_stack(t_stack *a);
int		ft_strlen(char *s);
int		ft_error(t_stack *a, t_stack *b);
int		ft_is_sorted(t_stack *a);
int		ft_parse(char *s, int *out);
t_stack	*ft_verfier(char *s[], int l);
void	recursive_merge(int *tab, int start, int end);
t_stack	*merge_sort(t_stack *a);
int		Coordinate_stack(t_stack *a);
int		bits_represtntion(int n);
void	divied_by2(t_stack *a);
void	split_stack(t_stack *a, t_stack *b);
void	radix_bit_ab(t_stack *a, t_stack *b);
void	radix_bit_ba(t_stack *a, t_stack *b);
void	merge_stack(t_stack *a, t_stack *b);
void	my_algorithm(t_stack *a, t_stack *b);
void	my_algorith_10ab(t_stack *a, t_stack *b);
void	my_algorith_10ba(t_stack *b, t_stack *a);
void	divide_tine(t_stack *a);
void	my_genral_idea(t_stack *a, t_stack *b);

#endif
