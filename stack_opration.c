#include"push_swap.h"
void swap_stack(t_stack *a)
{
	int tmp;
	int top;

	top=a->top;
	if(top<1)
		return ;
	tmp=a->tab[top];
	a->tab[top]=a->tab[top-1];
	a->tab[top-1]=tmp;
}
void push_in(t_stack *src,t_stack *dest)
{
	int top;
	top=src->top;
	if(top<0)
		return ;
	push_stack(dest,src->tab[top]);
	pop(src);
}
void re_rotate_stack(t_stack *a)
{
	int i;
	int last;

	i=0;
	if(a->top<1)
		return ;
	last=a->tab[0];
	while(i<a->top)
	{
		a->tab[i]=a->tab[i+1];
		i++;
	}
	a->tab[(a->top)]=last;
}
void rotate_stack(t_stack *a)
{
        int top;
        int first;
        int i;

        top=a->top;
	i=top;
        if(top<1)
                return ;
        first=a->tab[top];
        while(i>0)
        {
                a->tab[i]=a->tab[i-1];
                i--;
        }
        a->tab[0]=first;
}
