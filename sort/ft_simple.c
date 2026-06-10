#include"../push_swap.h"
void ft_simple(t_stack *a ,t_stack *b,t_benchmark *bench)
{
	int min;
	min=0;
	while(a->top > -1)
	{
		if(a->tab[a->top]==min)
		{
			push_in(a,b,'b');
			(bench->pb)++;
			if(a->top > -1)
				min++;
		}
		else
		{
			rotate_stack(a,'a');
			(bench->ra)++;
		}
	}
	while(b->top > -1)
	{
		push_in(b,a,'a');
               	(bench->pa)++;
	}
}
