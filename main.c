/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 11:40:17 by sjang             #+#    #+#             */
/*   Updated: 2016/10/19 11:40:18 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "use_libft.h"
#include "ft_printf.h"
#include <stdio.h>//
void	cheat_print_specifies(t_specifies *specifies);

int ft_printf(const char *restrict format, ...)
{
	int i;
	int size;
	int startpos;
	int err;
	char *str;
	t_specifies *specifies;
	va_list ap;

	va_start(ap, format);
	i = 0;
	size = 0;
	specifies = ft_new_specifies();
	while (format[i])
	{
		startpos = i;
		while (format[i] != '%' && format[i] != 0)
			i++;
		size += i - startpos;
		write(1, format + startpos, i - startpos);
		if (!(format[i]))
			break;
		i++;
		err = ft_get_specifies(format + i, specifies, ap);
		// cheat_print_specifies(specifies);
		if (err == -1)
			return (-1);
		i += err;
		err = ft_dealtypes(specifies, ap, &str);
		if (err == 0)
			return (-1);
		ft_dealprecision(specifies, &str);
		ft_dealflag(specifies, &str);
		ft_dealwidth(specifies, &str);
		if ((specifies->type == 'c' || specifies->type == 'C') &&
			specifies->firstch == 0 && specifies->fromleft)
		{
			ft_putchar(0);
			size++;
		}
		ft_putstr(str);
		if ((specifies->type == 'c' || specifies->type == 'C') &&
			specifies->firstch == 0 && !specifies->fromleft)
		{
			ft_putchar(0);
			size++;
		}
		size += ft_strlen(str);
		free(str);
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
	printf("length :	%c\n", specifies->length);
	printf("type :		%c\n", specifies->type);
}

int main(void)
{
	char *str = NULL;
	int size[3];
	size[0] = ft_printf("Bla bla %*.*d", 0, -15, 0);
	printf("%s\n", "");
	size[1] = printf("Bla bla %*.*d", 0, -15, 0);
	printf("%s\n", "");
	// size[3] = printf("Bla bla %.*d\n", -45, 0);
	printf("my size: %d\n", size[0]);
	printf("sy size: %d\n", size[1]);
	return (0);
}
