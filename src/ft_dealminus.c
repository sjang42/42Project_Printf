/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealminus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:23:19 by sjang             #+#    #+#             */
/*   Updated: 2016/11/02 16:23:30 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>//

int ft_dealminus(t_specifies *specifies, char **str)
{
	specifies->firstch = (*str)[0];
	if ((*str)[0] == '-' && (specifies->type == 'i' || 
			specifies->type == 'd' || specifies->type == 'D'))
	{
		ft_memmove(*str, (*str) + 1, ft_strlen(*str));
		return (1);
	}
	if (specifies->precision == 0 && specifies->thereisprecision == 1 && 
		(*str)[0] == '0' && specifies->type != 'c' && specifies->type != 'C'
		&& !((specifies->type == 'o' || specifies->type == 'O') &&
			specifies->flag & FLAG_SHARP)
		)
		*str[0] = 0;
	return (0);
}
