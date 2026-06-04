#include"push_swap.h"
void ft_memcpy(void *dst,void*src,int n)
{
	char *d;
	char *s;

	d=(char *)dst;
	s=(char *)src;
	while(n--)
	{
		*(d)=*(s);
		d++;
		s++;
	}
}
static void bubble_sort(int *tab,int size)
{
        int looping;
        int min;
        int i;
        looping=1;
        while(looping)
        {
                i=size-1;
                looping=0;
                while(i >= 0)
                {
                        if(tab[i] < tab[i-1])
                        {
                                min=tab[i-1];
                                tab[i-1]=tab[i];
                                tab[i]=min;
                                looping=1;

                        }
                        i--;
                }
        }
}
int normlize_stack(t_stack *a)
{
	int *tab;
	int i;
	int j;

	tab=malloc((a->size)*sizeof(int));
	if(!tab)
		return 1;
	ft_memcpy(tab,a->tab,a->size*sizeof(int));
	bubble_sort(tab,a->size);
	i=0;
	while(i< a->size)
	{
		j=0;
		while(j< a->size)
		{
			if(a->tab[i]==tab[j])
				a->tab[i]=j;
			j++;
		}
		i++;
	}

	return free(tab),0;
}
