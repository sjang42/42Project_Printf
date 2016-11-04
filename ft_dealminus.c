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

#include "ft_printf.h"
#include "use_libft.h"

int ft_dealminus(t_specifies *specifies, char **str)
{
	specifies->firstch = (*str)[0];
	if ((*str)[0] == '-')
	{
		ft_memmove(*str, (*str) + 1, ft_strlen(*str));
		return (1);
	}
	return (0);
}
