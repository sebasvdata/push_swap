/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bench.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoben-ch <yoben-ch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 23:37:31 by yoben-ch          #+#    #+#             */
/*   Updated: 2026/06/11 00:43:15 by yoben-ch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../push_swap.h"
static int count_total(t_benchmark *bench)
{
	int totale;
	totale=bench->sa + bench->sb + bench->ss;
	totale += bench->ra +bench->rb +bench->rr;
	totale +=bench->rra +bench->rrb +bench->rrr;
	totale +=bench->pa +bench->pb;
	return totale;
}


static int print_disorder(int n)
{
	int div;
	int ret;
	char c;
	div=(n/100);
	ret=(n%100);
	
	if(n==10000)
		return write(2,"100.00\n",7);
	c= div/10 +'0';
	write(2,&c,1);
	c=div%10 +'0';
	write(2,&c,1);
	write(2,".",1);
	c= ret/10 +'0';
	write(2,&c,1);
	c=ret%10 +'0';
	write(2,&c,1);
	write(2,"%\n",2);
	return 0;
}
void display_bench(t_benchmark *bench)
{
	ft_printf("[bench] disorder :");
	print_disorder(bench->disorder);
	ft_printf("[bench] strategy: %s\n",bench->startegy);
	ft_printf("[bench] total_ops: %d\n",count_total(bench));
	ft_printf("[bench] sa: %d sb: %d pa: %d pb: %d\n",bench->sa,bench->sb,bench->pa,bench->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",bench->ra,bench->rb,bench->rr,bench->rra,bench->rrb,bench->rrr);
}
