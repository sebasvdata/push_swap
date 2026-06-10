#include "../push_swap.h"
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
	int	i;

	i = b->top;
	while (i >= 0 && b->tab[i] != min)
		i--;
	if (i < 0)
		return (1);
	return ((b->top - i) <= i);
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

static int next_partition(t_stack *a,int i,int sqt)
{
	int j;
	
	j=0;
	while(j <= a->top)
	{
		if(a->tab[j]>=i * sqt  && a->tab[j]<(i +1)*sqt )
			return 0;
		j++;
	}
	return 1;
}

void	ft_medium(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int i;
	int sqt;

	i = 0;
	sqt=ft_sqrt(a->size);
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
		i += next_partition(a,i,sqt);
	}
	move_back(a,b,bench);
}
