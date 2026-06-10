#include "../push_swap.h"

float ft_disorder(t_stack *a)
{
	float mistakes;
	float total_pairs;
	int i;
    int j;
	mistakes = 0;
	total_pairs = 0;
	i=-1;
	while(i<(a->top))
	{
		j=i+1;
		while(j<(a->top))
		{
			total_pairs += 1;
			if (a->tab[i] > a->tab[j])
				mistakes += 1;
			j++;
		}
		i++;
	}
	return ((mistakes / total_pairs));
}

 void ft_bzero(void *p,size_t size)
{
	char *s;

	s=(char *)p;
	while(size--)
		*(s++)='\0';
}

static char *strategy_bench(float n)
{
	if(n < 0.2)
		return "Simple / O(n^2)";
	else if( n >= 0.2 && n < 0.5)
		return "medium /  O(n√n)";
	return "Complex / O(n log(n))";
}

static t_benchmark * intiat_bench(t_stack *a,t_option *op)
{
	t_benchmark *bench;
	bench=malloc(sizeof(t_benchmark));
	if(!bench)
		return NULL;
	ft_bzero(bench,sizeof(t_benchmark));
	bench->disorder=ft_disorder(a);
	if(op->simple)
                bench->startegy="Simple / O(n^2)";
        else if(op->medium)
                bench->startegy="medium/  O(n√n)";
        else if(op->complx)
                bench->startegy="Complex / O(n log(n))";
        else
                bench->startegy= strategy_bench(ft_disorder(a));
	return bench;
}
int decide_algorithm(t_stack *a,t_stack *b,t_option *op)
{
	t_benchmark *bench;

	bench=intiat_bench(a,op);
	if(!bench)
		return 1;
	if(op->simple)
		ft_simple(a,b,bench);
	else if(op->medium)
		ft_medium(a,b,bench);
	else if(op->complx)
		radix_sort(a,b,bench);
	//else 
		//ft_adaptive(a,b,bench);
	if(op->bench)
		display_bench(bench);
	free(bench);
	return 0;
}
