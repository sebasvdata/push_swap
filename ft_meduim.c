#include "push_swap.h"
static int	ft_sqrt(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i);
}
static int rot_dir(t_stack *b,int min)
{
	int i;
	int r;
	int rr;
	r=0;
	rr=0;
	i=b->top;
	while(b->tab[i--]!=min)
		r++;
	i=0;
	while(b->tab[i++]!=min)
                rr++;
	return (r<=rr);
}
static void move_back(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int min;
	int rotation;
	min=b->top;
	while(b->top >-1)
	{
		rotation=rot_dir(b,min);
		while(b->tab[b->top]!=min)
		{
			if(rotation)
			{
                       		rotate_stack(b, 'b');
                        	(bench->rb)++;
			}
			else
                	{
                     		re_rotate_stack(b,'b');
                      		(bench->rrb)++;
                	}
		}
		push_in(b, a, 'a');
                (bench->pa)++;
		min=b->top;
	}
}
void	ft_medium(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int i;
	int sqt;

	i = 0;
	sqt=ft_sqrt(a->size);
	if(normlize_stack(a))
		ft_error(a,b);
	while (a->top > - 1)
	{
		if (a->tab[a->top]>=i * sqt  && a->tab[a->top]<(i +1)*sqt )
		{
			push_in(a, b, 'b');
			(bench->pb)++;
		}
		else
		{
			rotate_stack(a, 'a');
			(bench->ra)++;
		}
		if (bench->pb >= (i+1) * sqt )
			i++;
	}
	move_back(a,b,bench);
}
