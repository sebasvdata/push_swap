#include"push_swap.h"
#include<stdio.h>
t_stack * create_stack(int size)
{
	t_stack *stack;
	stack=malloc(sizeof(t_stack));
	if(!stack)
		return NULL;
	stack->tab=malloc(size*sizeof(int));
	if(!(stack->tab))
		return free(stack),NULL;
	stack->size=size;
	stack->top=-1;
}
int push_stack(t_stack *s,int value)
{
	if((s->size-1)==s->top)
		return 0;
	s->tab[++(s->top)]=value;
	return 1;
}
int pop(t_stack *s)
{
	if(s->top==-1)
		return 0;
	(s->top)--;
	return 1;
}
int print_stack(t_stack *s)
{
	int i;
	i=(s->top);
	while(i>=0)
		printf("%d\n",s->tab[i--]);
}
int main(void)
{
	t_stack *a;
	a=create_stack(6);
	push_stack(a,3);
	push_stack(a,4);
	print_stack(a);
	printf("--------------------\n");
       push_stack(a,8);
        push_stack(a,9);
        print_stack(a);
	printf("--------------------\n");
	pop(a);
	print_stack(a);
}
