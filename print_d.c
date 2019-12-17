/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbarrius <hbarrius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:29:42 by hbarrius          #+#    #+#             */
/*   Updated: 2019/12/11 19:20:12 by hbarrius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>

static void	ft_putnbr(int num)
{
	int count;
	int pot;
	int negativo;

	negativo = 45;
	count = num;
	pot = 1;
	if (count < 0)
	{
		write(1, &negativo, 1);
	}
	while (count > 9)
	{
		count = (count / 10);
		pot = pot * 10;
	}
	while (pot >= 1)
	{
		if(num /pot < 0)
		{
		count = (num / pot) * -1 + '0';
		}
		else
		{
			count = (num / pot) + '0';
		}
			write(1, &count, 1);
			num = (num % pot);
			pot = (pot / 10);
	}
}

t_tab   *print_d(t_tab *tab)
{
    int num;
    
    if (tab->flag_ident == 'd' || tab->flag_ident == 'i')
        num = (int)(va_arg(tab->args, int));
    ft_putnbr(num);
    return (tab);
}

static int  get_tens(int num)
{
  int tens;

  if (num < 0)
    num *= -1;
  while ((num/10) > 0)
    tens++;
  return(tens);
}
/*
static  char  sign(t_tab *tab, int num)
{
  char *tmp

  tmp = tab->flags;
  if (num < 0)
    return("-")
  if (tmp[1] == 1)
    return ("+")
  if (tmp[2] == 1)
    

}
*/
