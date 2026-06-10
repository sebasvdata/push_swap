#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_option op;

	if (ac < 2 )
		return (0);
	if(init_stack(&av,&ac) || ft_skip(&op,av,ac)==-1)
		return ft_error(NULL,NULL);
	a = ft_verfier(av, ac,ft_skip(&op,av,ac));
	if (!a || normlize_stack(a))
		return (ft_error(a, NULL));
	if (a->top < 1 || ft_is_sorted(a))
		return (destroy_stack(a),0);
	b = create_stack(ac - 1);
	if (!b)
		return (ft_error(a, NULL));
	decide_algorithm(a,b,&op);
	liberty(a, b, av);
	return (0);
}
