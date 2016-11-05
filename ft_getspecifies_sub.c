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

#include "ft_printf.h"
#include "use_libft.h"
#include <stdio.h>///

int		ft_get_flag(const char *restrict format, enum e_printfflags	*flag)
{
	int i;

	i = 0;
	while (1)
	{
		if (format[i] == '0')
			*flag |= FLAG_ZERO;
		else if (format[i] == '#')
			*flag |= FLAG_SHARP;
		else if (format[i] == '+')
			*flag |= FLAG_PLUS;
		else if (format[i] == '-')
			*flag |= FLAG_MINUS;
		else if (format[i] == ' ')
			*flag |= FLAG_SPACE;
		else
			break;
		i++;
	}
	return (i);
}

int		ft_get_width(const char *restrict format,
					t_specifies *specifies, va_list ap)
{
	int		i;
	int		tempwidth;
	int 	star;
	int		count;

	i = 0;
	tempwidth = 0;
	count = 0;
	while (format[i] != 0 &&
		!ft_get_precision(format + i, NULL, 0) &&
			!ft_get_length(format + i, NULL) &&
			!ft_get_type(format + i, NULL))
	{
		if (format[i] == '*')
		{
			tempwidth = (int)va_arg(ap, int);
			star = 1;
			if (tempwidth < 0)
			{
				tempwidth *= -1;
				specifies->fromleft = 1;
			}
		}
		else if (ft_isdigit(format[i]))
		{
			if (star)
			{
				tempwidth = 0;
				star = 0;
			}
			tempwidth = (tempwidth * 10) + (format[i] - '0');
		}
		else if (format[i] == 0 || format[i] != '%')
			break;
		specifies->thereiswidth = 1;
		count++;
		i++;
	}
	if (specifies && count)
		specifies->width = tempwidth;
	return (count);
}

int		ft_get_precision(const char *restrict format,
							t_specifies *specifies, va_list ap)
{
	int		i;
	int		minus;
	int		star;
	int		tempprecision;
	int		count;

	count = 1;
	star = 0;
	tempprecision = 0;
	if (format[0] != '.')
		return (0);
	if (specifies)
		specifies->thereisprecision = 1;
	i = 1;
	minus = 1;
	while (format[i] != 0 &&
		!ft_get_length(format + i, NULL) && !ft_get_type(format + i, NULL))
	{
		if (i == 1 && format[i] == '*' && ap)
		{
			star = 1;
			if ((tempprecision = (int)va_arg(ap, int)) < 0)
				minus = -1;
		}
		else if (i == 1 && format[1] == '-')
			minus = -1;
		else if (ft_isdigit(format[i]))
		{
			if (star)
			{
				tempprecision = 0;
				star = 0;
			}
			tempprecision = (tempprecision * 10) + (format[i] - '0');
		}
		else
			break;
		count++;
		i++;
	}
	if (specifies)
	{
		if (!specifies->thereiswidth && minus == -1)
		{
			specifies->width = (tempprecision != 0) ? tempprecision : -1;
			specifies->fromleft = 1;
			specifies->thereisprecision = 0;
		}
		else
			specifies->precision = tempprecision * minus;
	}
	return (count);
}

int			ft_get_length(const char *restrict format, char *length)
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

int		ft_get_type(const char *restrict format, char *type)
{
	if (format[0] == 's' || format[0] == 'S' || format[0] == 'p' ||
		format[0] == 'd' || format[0] == 'D' || format[0] == 'i' ||
		format[0] == 'o' || format[0] == 'O' || format[0] == 'u' ||
		format[0] == 'U' || format[0] == 'x' || format[0] == 'X' ||
		format[0] == 'c' || format[0] == 'C' || format[0] == '%')
	{
		if (type)
			*type = format[0];
		return (1);
	}
	else if (type)
	{
		*type = format[0];
		return (1);
	}
	return (0);
}
