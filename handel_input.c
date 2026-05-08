#include<unistd.h>
int ft_strlen(char *s)
{
	int i;
	i=0;
	while(s[i])
		i++;
	return i;
}
int ft_verfier(char *s[],int l)
{
	int i;
	int j;

	i=1;
	while(i<l)
	{
		int j=0;
                if(s[i][j]=='-')
                        j++;
		while(s[i][j]>='0' && s[i][j]<='9')
			j++;
		if(j!=ft_strlen(s[i]) || !ft_strlen(s[i]))
			return 1;
		i++;
	}
	return 0;
}
int main(int l,char *s[])
{
	if(l==1)
		return write(1,"Error\n",6);
	if(ft_verfier(s,l))
		return write(1,"Error\n",6);
}
