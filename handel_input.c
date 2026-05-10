#include "push_swap.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_parse(char *s, int *out)
{
	int		i;
	long	re;
	long	sg;

	sg = 1;
	i = 0;
	re = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sg = -1;
		i++;
	}
	if (!s[i])
		return (1);
	while (s[i] <= '9' && s[i] >= '0')
	{
		re = re * 10 + (s[i++] - '0');
		if ((sg * re) > INT_MAX || (sg * re) < INT_MIN)
			return (1);
	}
	if (i != ft_strlen(s))
		return (1);
	*out = (int)(sg * re);
	return (0);
}

t_stack	*ft_verfier(char *s[], int l)
{
	int		i;
	int		value;
	t_stack	*st;

	i = l - 1;
	st = create_stack(l - 1);
	if (!st)
		return (NULL);
	while (i >= 1)
	{
		if (ft_parse(s[i], &value))
			return (destroy_stack(st));
		if (search_stack(st, value))
			return (destroy_stack(st));
		push_stack(st, value);
		i--;
	}
	return (st);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = ft_verfier(av, ac);
	if (!a)
		return (ft_error(NULL, NULL));
	if (a->top < 1 || ft_is_sorted(a))
	{
		destroy_stack(a);
		return (0);
	}
	b = create_stack(ac - 1);
	if (!b)
		return (ft_error(a, NULL));
	if (!Coordinate_stack(a))
		return (ft_error(a, b));
	my_algorithm(a, b);
	destroy_stack(a);
	destroy_stack(b);
	return (0);
}
