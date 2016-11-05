/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:15:40 by sjang             #+#    #+#             */
/*   Updated: 2016/10/28 15:15:41 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>//

int ft_dealwidth(t_specifies *specifies, char **str)
{
	int		diff;
	char	*temp;

	if (specifies->width == 0)
		return (0);
	if (specifies->flag & FLAG_ZERO && specifies->thereisprecision == 0 &&
		specifies->fromleft != 1)
		return (1);
	diff = (specifies->width - ft_strlen(*str));
	if ((specifies->type == 'c' || specifies->type == 'C') &&
			specifies->firstch == 0)
		diff--;
	if (diff <= 0)
		return (1);
	temp = (char*)malloc(sizeof(char) * (ft_strlen(*str) + diff + 1));
	temp[ft_strlen(*str) + diff] = 0;
	if (!specifies->fromleft)
	{
		ft_memset(temp, ' ', diff);
		ft_memcpy(temp + diff, *str, ft_strlen(*str));
		free(*str);
		*str = temp;
	}
	else
	{
		ft_strcpy(temp, *str);
		ft_memset(temp + ft_strlen(*str), ' ', diff);
		free(*str);
		*str = temp;
	}
	return (1);//
}
