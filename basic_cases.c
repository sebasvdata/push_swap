#include"push_swap.h"
void sort_2(t_stack *a)
{
	if(a->top!=1)
		return;
	if(a->tab[1]>a->tab[0])
		swap_stack(a,'a');
}
void sort_3(t_stack *a)
{
	if(a->top != 2)
		return ;
	if(a->tab[2]==0 && a->tab[0]==1)
	{
		swap_stack(a,'a');
		rotate_stack(a,'a');
	}
	else if(a->tab[2]==1 && a->tab[0]==0)
		re_rotate_stack(a,'a');
        else if(a->tab[2]==1 && a->tab[0]==2)
                swap_stack(a,'a');
        else if(a->tab[2]==2 && a->tab[0]==1)
                rotate_stack(a,'a');
        else if(a->tab[2]==2 && a->tab[0]==0)
        {       
                rotate_stack(a,'a');
                swap_stack(a,'a');
        }
}
void sort_4(t_stack *a,t_stack *b)
{
	if(a->top!=3)
		return ;
	if(a->tab[3]==0 || a->tab[2]==0)
	{	while(a->tab[a->top]!=0)
                	rotate_stack(a,'a');
	}
	else
	{
		while(a->tab[a->top]!=0)
                        re_rotate_stack(a,'a');
	}
	push_in(a,b,'b');
	Coordinate_stack(a);
	sort_3(a);
	push_in(b,a,'a');
}
void sort_5(t_stack *a,t_stack *b)
{
	if(a->top!=4)
                return ;
	if(a->tab[4]==0 || a->tab[3]==0 || a->tab[2]==0)
        {       while(a->tab[a->top]!=0)
                        rotate_stack(a,'a');
        }
        else
        {
                while(a->tab[a->top]!=0)
                        re_rotate_stack(a,'a');
        }

	push_in(a,b,'b');
	Coordinate_stack(a);
	sort_4(a,b);
	push_in(b,a,'a');
}

void basic_case(t_stack *a,t_stack *b,int size)
{
	if(size==2)
		sort_2(a);
	else if(size==3)
                sort_3(a);
	else if(size==4)
                sort_4(a,b);
	else if(size==5)
                sort_5(a,b);
}
	

