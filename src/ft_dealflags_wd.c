/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealflags_wd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:31:57 by sjang             #+#    #+#             */
/*   Updated: 2016/11/08 14:31:58 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int 		ft_dealtypes_wd(t_specifies *specifies, va_list ap,
							wchar_t **str_wd, char **str)
{
	wchar_t *tmp;

	if (specifies->type == 'S' ||
		(specifies->length == 'l' && specifies->type == 's'))
	{
		*str_wd = (wchar_t*)va_arg(ap, wchar_t*);
		if (!*str_wd)
			*str_wd = ft_utf8to32le(L"(null)");
		else
			*str_wd = ft_utf8to32le(*str_wd);
	}
	else if (specifies->type == 'C' ||
			(specifies->length == 'l' && specifies->type == 'c'))
	{
		*str_wd = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		(*str_wd)[0] = (char)va_arg(ap, wchar_t);
		(*str_wd)[1] = 0;
		tmp = ft_utf8to32le(*str_wd);
		free(*str_wd);
		*str_wd = tmp;
	}
	specifies->firstch = (*str_wd)[0];
	if (*str_wd)
	{
		*str = ft_removezero(*str_wd);
		free(*str);
		return (1);
	}
	return (0);
}

