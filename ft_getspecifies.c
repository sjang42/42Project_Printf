/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getspecifies.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 19:27:26 by sjang             #+#    #+#             */
/*   Updated: 2016/10/26 19:27:27 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "use_libft.h"

void			ft_specifies_init(t_specifies *specifies)
{
	specifies->flag = FLAG_NOTHING;
	specifies->width = 0;
	specifies->precision = 0;
	specifies->length = 0;
	specifies->type = 0;
	specifies->fromleft = 0;
	specifies->firstch = 0;
}

t_specifies		*ft_new_specifies(void)
{
	t_specifies *specifies;

	specifies = (t_specifies*)malloc(sizeof(t_specifies));
	ft_specifies_init(specifies);
	return (specifies);
}

int				ft_get_specifies(const char *restrict format,
									t_specifies *specifies, va_list ap)
{
	int i;
	int checkerror;

	i = 0;
	i += ft_get_flag(format, &(specifies->flag));
	if (specifies->flag & FLAG_MINUS)
		specifies->fromleft = 1;
	checkerror = ft_get_width(format + i, &(specifies->width), ap);
	if (checkerror == -1)
		return (-1);
	i += checkerror;
	checkerror = ft_get_precision(format + i, &(specifies->precision), ap);
	if (checkerror == -1)
		return (-1);
	i += checkerror;
	i += ft_get_length(format + i, &(specifies->length));
	checkerror = ft_get_type(format + i, &(specifies->type));
	if (checkerror == 0)
		return (-1);
	i += checkerror;
	return (i);
}
