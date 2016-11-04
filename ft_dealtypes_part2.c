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

#include "ft_printf.h"
#include "use_libft.h"

int ft_dealtypes_wd(t_specifies *specifies, va_list ap, WINT_T **str)
{
	if (specifies->type == 'S' ||
		(specifies->type == 's' && specifies->length == 'l'))
	{
		*str = ft_strdup_wd((WINT_T*)va_arg(ap, WINT_T*));
		return (1);
	}
	else if (specifies->type == 'C' ||
			(specifies->type == 'c' && specifies->length == 'l'))
	{
		*str = (WINT_T*)malloc(sizeof(WINT_T) * 2);
		(*str)[0] = (WINT_T)va_arg(ap, WINT_T);
		(*str)[1] = 0;
		return (1);
	}
	return (0);
}

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
