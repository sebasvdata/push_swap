#include "../push_swap.h"

static int	better_base(int nb)
{
	int	i;

	i = 1;
	while (i * i < nb)
		i++;
	return (i );
}

static int	mosts_digit(int n, int base)
{
	return (n / base);
}

static int	better_cost(t_stack *b, int min)
{
	int	i;

	i = b->top;
	while (i >= 0 && b->tab[i] != min)
		i--;
	if (i < 0)
		return (1);
	return ((b->top - i) <= i);
}

static void	move_back(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	min;
	int	rotation;

	min = b->top;
	while (b->top > -1)
	{
		rotation = better_cost(b, min);
		while (b->tab[b->top] != min && b->tab[b->top] != min - 1)
		{
			if (rotation)
			{
				rotate_stack(b, 'b');
				(bench->rb)++;
			}
			else
			{
				re_rotate_stack(b, 'b');
				(bench->rrb)++;
			}
		}
		push_in(b, a, 'a');
		(bench->pa)++;
		if (a->top >= 1 && a->tab[a->top] > a->tab[a->top - 1])
		{
			swap_stack(a, 'a');
			(bench->sa)++;
		}
		while (b->top > -1 && !search_stack(b, min))
			min--;
	}
}
static int smart_rotation(t_stack *a,t_stack *b ,t_benchmark * bench ,int rr)
{
			if(rr && b->top >=1)
			{
				rotate_stack(b,0);
				rotate_stack(a,'r');
				(bench->rr)++;
			}
			else
			{
				rotate_stack(a, 'a');
				(bench->ra)++;
			}
			return 0;
}

static int next_digits(t_stack *a,int *upper,int *bottom)
{
	int j;
	int digit;
	int base;
	
	j=0;
	base = better_base(a->size);
	while(j <= a->top)
	{
		digit = mosts_digit(a->tab[j], base);
		if(digit == *upper || digit == *bottom)
			return 0;
		j++;
	}
	(*upper)++;
	(*bottom)--;
	return 1;
}

void	radix_sort(t_stack *a, t_stack *b, t_benchmark *bench)
{
	int	base;
	int	upper;
	int	bottom;
	int	digit;
	int rr;


	base = better_base(a->size);
	upper = base / 2;
	bottom = upper - 1;
	rr=0;
	while (a->top > -1)
	{
		digit = mosts_digit(a->tab[a->top], base);
		if (digit == upper || digit ==bottom)
		{
			if(rr && b->top >=1)
			{
				rotate_stack(b,'b');
				(bench->rb)++;
			}
			push_in(a, b, 'b');
			(bench->pb)++;
			rr=0;
			if(digit== bottom)
				rr=1;
		}
		else
			rr=smart_rotation(a,b,bench,rr);
		next_digits(a,&upper,&bottom);
	}
	move_back(a, b, bench);
}

