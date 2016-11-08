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
#include <stdio.h>//

void	cheat_print_specifies(t_specifies *specifies);

int ft_printf(const char *restrict format, ...)
{
	int i;
	int size;
	int startpos;
	int		err;
	char		*str;
	wchar_t		*str_wd;
	t_specifies *specifies;
	va_list ap;

	va_start(ap, format);
	i = 0;
	size = 0;
	specifies = ft_new_specifies();
	while (format[i])
	{
		startpos = i;
		str_wd = NULL;

		while (format[i] != '%' && format[i] != 0)
			i++;
		size += i - startpos;
		write(1, format + startpos, i - startpos);
		if (!(format[i]) || !(format[i + 1]))
			break;
		i++;
		err = ft_get_specifies(format + i, specifies, ap);
		// cheat_print_specifies(specifies);
		if (err == -1)
			return (-1);
		i += err;
		if (specifies->type == 'S' ||
			(specifies->length == 'l' && specifies->type == 's')
		||  (specifies->type == 'C' ||
			(specifies->length == 'l' && specifies->type == 'c')))
			ft_dealtypes_wd(specifies, ap, &str_wd, &str);
		else
			err = ft_dealtypes(specifies, ap, &str);
		if (err == 0)
			return (-1);
		ft_dealprecision(specifies, &str);
		ft_dealflag(specifies, &str);
		ft_dealwidth(specifies, &str);
		if (specifies->type == 'S' ||
			(specifies->length == 'l' && specifies->type == 's')
		||  (specifies->type == 'C' ||
			(specifies->length == 'l' && specifies->type == 'c')))
		{
			if (((specifies->type == 'c') || specifies->type == 'C') &&
				specifies->firstch == 0)
			{
				if (specifies->fromleft)
					ft_putchar(0);
				ft_putstr(str);
				if (!specifies->fromleft)
					ft_putchar(0);
				size++;
			}
			else if (specifies->fromleft)
			{
				ft_putstr_wd(str_wd);
				ft_putstr(str + ft_strlen_wd(str_wd));
			}
			else
			{
				str[ft_strlen(str) - ft_strlen_wd(str_wd)] = 0;
				ft_putstr(str);
				ft_putstr_wd(str_wd);
			}
			printf("[%d]\n", ft_strlen_wd(str_wd));
			printf("[%d]\n", ft_strlen(str));
			size += ft_countbites(str_wd) + ft_strlen(str) - ft_strlen_wd(str_wd);
		}
		else
		{
			size += ft_strlen(str);
			if ((specifies->type == 'c') && specifies->firstch == 0)
			{

				if (specifies->fromleft)
					ft_putchar(0);
				ft_putstr(str);
				if (!specifies->fromleft)
					ft_putchar(0);
				size++;
			}
			else
				ft_putstr(str);
		}
		if (str)
			free(str);
		if (str_wd)
			free(str_wd);
	}
	free(specifies);
	va_end(ap); 
	return (size);
}

void	cheat_print_specifies(t_specifies *specifies)
{
	printf("flag :		%d\n", specifies->flag);
	printf("width :		%d\n", specifies->width);
	printf("precision :	%d\n", specifies->precision);
	printf("length :	%d\n", specifies->length);
	printf("type :		%d\n", specifies->type);
}
