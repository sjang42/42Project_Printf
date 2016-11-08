/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealtypes_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:27:38 by sjang             #+#    #+#             */
/*   Updated: 2016/11/01 17:27:40 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>//

int ft_dealtypes_getbase(t_specifies *specifies)
{
	if (specifies->type	== 'u' || specifies->type == 'U')
		return (10);
	else if (specifies->type == 'o' || specifies->type == 'O')
		return (8);
	else if (specifies->type == 'x' || specifies->type == 'X' ||
			specifies->type == 'p')
		return (16);
	return (0);
}
