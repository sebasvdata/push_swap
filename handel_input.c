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

t_stack	*ft_verfier(char *s[], int l,int skip)
{
	int		i;
	int		value;
	t_stack	*st;

	i = l - 1 - skip;
	if(i==0)
		return NULL;
	st = create_stack(l - 1 - skip);
	if (!st)
		return (NULL);
	while (i >=1+ skip)
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
	t_option op;
	int skip;

	if (ac < 2)
		return (0);
	ft_op(&op);
	skip=ft_option(av[1],&op);
	if(1+skip>=ac)
		return 0;
	skip+=ft_option(av[1+skip],&op);
	a = ft_verfier(av, ac,skip);
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
	destroy_stack(a);
	destroy_stack(b);
	return (0);
}
