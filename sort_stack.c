#include "push_swap.h"

t_stack	*ft_copy_stack(t_stack *a)
{
	t_stack	*copy;
	int		i;

	copy = create_stack(a->size);
	if (!copy)
		return (NULL);
	i = 0;
	while (i <= a->top)
		push_stack(copy, a->tab[i++]);
	return (copy);
}

static void	copy_tmp(int *tab, int *tmp, int start, int end)
{
	int	i;
	int	c;

	i = start;
	c = 0;
	while (i <= end)
		tab[i++] = tmp[c++];
}

static void	merge_tabs(int *tab, int start, int mid, int end)
{
	int	i;
	int	j;
	int	*tmp;
	int	c;

	i = start;
	j = mid + 1;
	c = 0;
	tmp = malloc((end - start + 1) * sizeof(int));
	if (!tmp)
		return ;
	while (i <= mid && j <= end)
	{
		if (tab[i] < tab[j])
			tmp[c++] = tab[i++];
		else
			tmp[c++] = tab[j++];
	}
	while (i <= mid)
		tmp[c++] = tab[i++];
	while (j <= end)
		tmp[c++] = tab[j++];
	copy_tmp(tab, tmp, start, end);
	free(tmp);
}

void	recursive_merge(int *tab, int start, int end)
{
	int	mid;

	if (start >= end)
		return ;
	mid = (start + end) / 2;
	recursive_merge(tab, start, mid);
	recursive_merge(tab, mid + 1, end);
	merge_tabs(tab, start, mid, end);
}

t_stack	*merge_sort(t_stack *a)
{
	t_stack	*copy;

	if (!a || a->top <= 0)
		return (NULL);
	copy = ft_copy_stack(a);
	if (!copy)
		return (NULL);
	recursive_merge(copy->tab, 0, copy->top);
	return (copy);
}
