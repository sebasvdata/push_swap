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
int		push_stack(t_stack *s, int value);
int		pop(t_stack *s);
void	swap_stack(t_stack *a);
void	push_in(t_stack *src, t_stack *dest);
void	re_rotate_stack(t_stack *a);
void	rotate_stack(t_stack *a);
int		ft_strlen(char *s);
int		ft_parse(char *s, int *out);
t_stack	*ft_verfier(char *s[], int l);

#endif
