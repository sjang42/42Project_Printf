 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealprecision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:53:06 by sjang             #+#    #+#             */
/*   Updated: 2016/10/28 15:53:06 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>//

int				ft_dealprecision(t_specifies *specifies, char **str)
{
	int diff;
	char *temp;

	diff = specifies->precision - ft_strlen(*str);
	if ((specifies->type == 'd' || specifies->type == 'D' ||
		specifies->type == 'u' || specifies->type == 'U' ||
		specifies->type == 'o' || specifies->type == 'O' ||
		specifies->type == 'x' || specifies->type == 'X' ||
		specifies->type == 'i' || specifies->type == 'p') &&
		diff > 0 && specifies->precision > 0)
	{
		temp = (char*)malloc(ft_strlen(*str) + diff + 1);
		ft_memset(temp, '0', diff);
		temp[diff] = 0;
		ft_strcat(temp + diff, (*str));
		free(*str);
		*str = temp;
	}
	if (specifies->type == 's' && diff < 0 &&
		specifies->thereisprecision)
	{
		if (specifies->precision >= 0)
			(*str)[specifies->precision] = 0;
		else if (specifies->precision < -1)
			(*str)[0] = 0;
	}
	return (specifies->precision);
}
