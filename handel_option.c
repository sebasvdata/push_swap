#include"push_swap.h"
int ft_strcmp(char *s1,char *s2)
{
	int i;
	i=0;
	while(s1[i] && s1[i]==s2[i])
		i++;
	return s1[i]-s2[i];
}
void ft_op(t_option *p)
{
    p->adaptive=1;
    p->complx=0;
    p->medium=0;
    p->simple=0;
    p->bench=0;

}
int already_option(t_option *p)
{
        if(p->adaptive==2)
			return 0;
        else if(p->complx)
			return 0;
        else if(p->medium)
			return 0;
        else if(p->simple)
			return 0;
	else if(p->bench)
			return 2;
        return 1;
}
int ft_option(char *s,t_option *p)
{
	if(!ft_strcmp(s,"--adaptive") && already_option(p))
		p->adaptive++;
	else if(!ft_strcmp(s,"--complex") && already_option(p))
		p->complx++;
	else if(!ft_strcmp(s,"--medium") && already_option(p))
		p->medium++;
	else if(!ft_strcmp(s,"--simple")&& already_option(p))
                p->simple++;
	else if(!ft_strcmp(s,"--bench") && already_option(p)!=2)
                p->bench++;
	else
		return 0;
	return 1;
}
