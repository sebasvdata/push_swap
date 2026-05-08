#include <stdio.h>

void recursive_merge(int *tab,int start,int end)
{
	int i;
	int counter;
	int j;
	i=start;
	counter=0;
	j=(end+start)/2 +1;
	if(start<end)
	{
		recursive_merge(tab,start,(end+start)/2);
		recursive_merge(tab,(end+start)/2 +1,end);
	}
	int tmptab[end-start+1];
	while(counter<=(end-start))
	{
		if(i<=(end+start)/2 && j<=end)
		{
			if(tab[i]<tab[j])
				tmptab[counter]=tab[i++];
			else
				tmptab[counter]=tab[j++];
		}
		else if(i<=(end+start)/2)
			tmptab[counter]=tab[i++];
		else if(j<=end)
			tmptab[counter]=tab[j++];
		counter++;
	}
	counter=0;
	while(start<=end)
	{
		tab[start]=tmptab[counter];
		start++;
		counter++;
	}
}
void merge_sort(int *tab , int size)
{
	 recursive_merge(tab,0,size-1);
}

int	main(void)
{
	int	tab[] = {5, 2, 9, 1, 3,6,9,100,-223,191919};
	int	size;
	int	i;

	merge_sort(tab, 10);
	i = 0;
	while (i < 10)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
	return (0);
}
