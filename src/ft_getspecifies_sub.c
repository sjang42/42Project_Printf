/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getspecifies_sub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 19:31:17 by sjang             #+#    #+#             */
/*   Updated: 2016/10/26 19:31:18 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int				ft_get_flag(const char *restrict format, t_specifies *specifies)
{
	int i;

	i = 0;
	while (1)
	{
		if (format[i] == '0')
			specifies->flag |= FLAG_ZERO;
		else if (format[i] == '#')
			specifies->flag |= FLAG_SHARP;
		else if (format[i] == '+')
			specifies->flag |= FLAG_PLUS;
		else if (format[i] == '-')
		{
			specifies->flag |= FLAG_MINUS;
			specifies->fromleft = 1;
		}
		else if (format[i] == ' ')
			specifies->flag |= FLAG_SPACE;
		else
			break ;
		i++;
	}
	return (i);
}

int				ft_get_length(const char *restrict format, char *length)
{
	if (format[0] == 'h' && format[1] == 'h')
	{
		if (length)
			*length = 'H';
		return (2);
	}
	else if (format[0] == 'l' && format[1] == 'l')
	{
		if (length)
			*length = 'L';
		return (2);
	}
	else if (format[0] == 'h' || format[0] == 'l' || format[0] == 'j' ||
			format[0] == 'z')
	{
		if (length)
			*length = format[0];
		return (1);
	}
	return (0);
}

static void		ft_getw_sub2(char ch, t_specifies *specifies,
								va_list ap, t_widths *wd)
{
	if (ch == '*')
	{
		wd->star = 1;
		wd->tempwidth = (int)va_arg(ap, int);
		if (wd->tempwidth < 0)
		{
			wd->tempwidth *= -1;
			specifies->fromleft = 1;
		}
	}
	else if (ft_isdigit(ch))
	{
		if (wd->star)
		{
			wd->star = 0;
			wd->tempwidth = 0;
		}
		wd->tempwidth = (wd->tempwidth * 10) + (ch - '0');
	}
}

static void		ft_getw_sub(const char *restrict format,
					t_specifies *specifies, va_list ap, t_widths *wd)
{
	while (format[wd->i] != 0 && !ft_get_precision(format + wd->i, NULL, 0) &&
		!ft_get_length(format + wd->i, NULL) &&
		!ft_get_type(format + wd->i, NULL))
	{
		if (format[wd->i] == '*' || ft_isdigit(format[wd->i]))
			ft_getw_sub2(format[wd->i], specifies, ap, wd);
		else
			break ;
		specifies->thereiswidth = 1;
		(wd->i)++;
	}
}

int				ft_get_width(const char *restrict format,
					t_specifies *specifies, va_list ap)
{
	t_widths widths;

	widths.i = 0;
	widths.star = 0;
	widths.tempwidth = 0;
	ft_getw_sub(format, specifies, ap, &widths);
	if (specifies && widths.i)
		specifies->width = widths.tempwidth;
	return (widths.i);
}
