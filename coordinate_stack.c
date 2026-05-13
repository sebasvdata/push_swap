#include "push_swap.h"

int	coordinate_stack(t_stack *a)
{
	t_stack	*sorted;
	int		i;
	int		j;

	sorted = merge_sort(a);
	if (!sorted)
		return (0);
	i = 0;
	while (i <= (a->top))
	{
		j = 0;
		while (j <= (sorted->top))
		{
			if (a->tab[i] == sorted->tab[j])
			{
				a->tab[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	destroy_stack(sorted);
	return (1);
}
