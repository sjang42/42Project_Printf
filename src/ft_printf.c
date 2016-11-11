/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:03:30 by sjang             #+#    #+#             */
/*   Updated: 2016/11/05 11:03:32 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int		ft_untilsp(const char *restrict format)
{
	int i;

	i = 0;
	while (format[i] != '%' && format[i] != 0)
		i++;
	write(1, format, i);
	return (i);
}

static int		ft_deal_specifies(const char *restrict format, va_list ap,
									t_specifies **pspecifies, char **str)
{
	int				ret;
	t_specifies		*specifies;

	*pspecifies = ft_new_specifies();
	specifies = *pspecifies;
	ret = ft_get_specifies(format, specifies, ap);
	if (specifies->type == 'S' ||
		(specifies->length == 'l' && specifies->type == 's')
	|| (specifies->type == 'C' ||
		(specifies->length == 'l' && specifies->type == 'c')))
		ft_dealtypes_wd(specifies, ap, str);
	else
		ft_dealtypes(specifies, ap, str);
	ft_dealprecision(specifies, str);
	ft_dealflag(specifies, str);
	ft_dealwidth(specifies, str);
	return (ret);
}

static int		ft_display_str(t_specifies *specifies, char *str)
{
	if (((specifies->type == 'c') || (specifies->type == 'C'))
			&& specifies->firstch == 0)
	{
		if (specifies->fromleft)
			ft_putchar(0);
		ft_putstr(str);
		if (!specifies->fromleft)
			ft_putchar(0);
		return (1);
	}
	else
	{
		ft_putstr(str);
		return (0);
	}
}

static int		ft_printf_sub(const char *restrict format, va_list ap)
{
	int				i;
	int				size;
	int				tmp;
	char			*str;
	t_specifies		*specifies;

	i = 0;
	size = 0;
	while (format[i])
	{
		tmp = ft_untilsp(format + i);
		i += tmp;
		size += tmp;
		if (!(format[i]) || !(format[i + 1]))
			break ;
		i++;
		i += ft_deal_specifies(format + i, ap, &specifies, &str);
		size += ft_strlen(str);
		size += ft_display_str(specifies, str);
		if (str)
			free(str);
		if (specifies)
			free(specifies);
	}
	return (size);
}

int				ft_printf(const char *restrict format, ...)
{
	int			size;
	va_list		ap;

	va_start(ap, format);
	size = ft_printf_sub(format, ap);
	va_end(ap);
	return (size);
}
