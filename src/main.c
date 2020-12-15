/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annharut <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/13 17:33:20 by annharut          #+#    #+#             */
/*   Updated: 2020/12/13 21:43:42 by annharut         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


char *found_text(int num, t_list *tab)
{
	int i;

	i = 0;
	if(num == 0)
		return("");
	while(i < 33)
	{
		if(num == tab[i].nb)
		   return tab[i].val;
		i++;	
	}
	exit (1);
}

int num_count(int num)
{
	int q;

	q = 0;
	while(num != 0)
	{
		num = num / 10;
		q++;
	}
	return q;
}

int thous_count(int num)
{
	int t;

	t = 0;
	while(num >= 1000)
	{
		num = num / 1000;
		t++;
	}
	return t;
}

int zero_count(int n)
{
	int i;
	int num;

	i = 0;
	num  = 1;
	while(i < n)
	{
		num = num * 10;
		i++;
	}
	return num;
}

void	ft_print_num(int num, t_list *tab, int num_count)
{
	int a;
	int b;
	int c;
	int d;
	int t = zero_count(num_count - num_count % 3);
	
	if(num < 1000)
	{
		if((a = num / 100))
		{
			ft_putstr(found_text(a, tab));
			ft_putstr(" ");
			ft_putstr(found_text(100, tab));
			ft_putstr(" ");
		}
		b = num % 100;
		if(b > 20)
		{
			c = b / 10 * 10;
			d = b % 10;
			ft_putstr(found_text(c, tab));
			ft_putstr(" ");
			ft_putstr(found_text(d, tab));
			ft_putstr(" ");
		}
		else
			ft_putstr(found_text(b, tab));
			ft_putstr(" ");
		
		
	}
	
	else
	{
		
		ft_print_num(num / 1000, tab, num_count); 
			ft_putstr(" ");
		
		ft_print_num(num % 1000, tab, 3); 
	}
	ft_putstr(found_text(t, tab));
			ft_putstr(" ");
	
}


int	main(int ac, char **av)
{
	t_list *tab;
	int *first;
	int addr_first;
	addr_first = 1;
	first = &addr_first;
	
	if (ac == 2)
	{
		if (ft_atoi(av[1]) < 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		tab = process("dict.txt");
		ft_print_num(ft_atoi(av[1]), tab, num_count(ft_atoi(av[1])));
	}
	return (0);
}


