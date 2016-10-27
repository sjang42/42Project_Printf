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


#include <stdlib.h>
#include <unistd.h>
#include "use_libft.h"
#include "ft_printf.h"
#include <stdio.h>//

char		*ft_unitoa_base(unsigned int num, int base, int cap)
{
	unsigned int	i;
	unsigned int	size;
	int				mod;
	char			*str;

	i = num;
	size = 0;
	while (i > 0)
	{
		i /= base;
		size++;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	str[size] = 0;
	while (num != 0)
	{
		mod = num % base;
		num /= base;
		if (mod < 10)
			str[--size] = '0' + mod;
		else
			if (cap == 'A')
				str[--size] = 'A' + mod - 10;
			else
				str[--size] = 'a' + mod - 10;
		i++;
	}
	return (str);
}

char		*ft_longtoa_base(long num, int base, int cap)
{
	long	i;
	long	size;
	int		mod;
	char	*str;

	i = num;
	size = 0;
	while (i > 0)
	{
		i /= base;
		size++;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	str[size] = 0;
	while (num != 0)
	{
		mod = num % base;
		num /= base;
		if (mod < 10)
			str[--size] = '0' + mod;
		else
			if (cap == 'A')
				str[--size] = 'A' + mod - 10;
			else
				str[--size] = 'a' + mod - 10;
		i++;
	}
	return (str);
}

static int	get_positional_long(long nb)
{
	long positional;
	long temp;

	positional = 1;
	temp = nb;
	while (temp >= 10 || temp <= -10)
	{
		temp /= 10;
		positional *= 10;
	}
	return (positional);
}

void		ft_putnbr_long(long nb)
{
	char	digit;
	long	positional;

	positional = get_positional_long(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		positional *= -1;
	}
	while (positional != 0)
	{
		digit = nb / positional + '0';
		write(1, &digit, 1);
		nb %= positional;
		positional /= 10;
	}
}




int ft_printf(const char *restrict format, ...)
{
	int i;
	int startpos;
	int nth;
	int checkerror;
	t_specifies *specifies;
	va_list ap;

	va_start(ap, format);
	i = 0;
	while (format[i])
	{
		startpos = i;
		while (format[i] != '%' && format[i] != 0)
			i++;
		write(1, format + startpos, i - startpos);
		if (format[i] == 0)
			break;
		specifies = ft_new_specifies();
		i++;
		if (format[i] == '%')
		{
			ft_putchar('%');
			continue ;//써도 되나?
		}
		else if ((checkerror =
				ft_get_specifies(format + i, specifies)) == -1)
		{
			free(specifies);
			return (-1);
		}
		/*flags*/
		// if (specifies->flag != 0)




		/*type*/
		else if (format[i] == 's')
			ft_putstr(va_arg(ap, char*));//+S
		else if (format[i] == 'p')
		{
			ft_putstr("0x");
			ft_putstr(ft_longtoa_base(
				(long)va_arg(ap, long*), 16, 'a'));
		}
		else if (format[i] == 'd' || format[i] == 'i')
			ft_putnbr(va_arg(ap, int));
		else if (format[i] == 'D')
			ft_putnbr_long(va_arg(ap, long));
		else if (format[i] == 'o')
			ft_putstr(ft_unitoa_base(
				va_arg(ap, int), 8, 'a'));
		else if (format[i] == 'O')
			ft_putstr(ft_longtoa_base(
				va_arg(ap, long), 8, 'a'));
		else if (format[i] == 'u')
			ft_putstr(ft_unitoa_base(
				va_arg(ap, unsigned int), 10, 'a'));
		else if (format[i] == 'U')
			ft_putstr(ft_longtoa_base(
				va_arg(ap, long), 10, 'a'));
		else if (format[i] == 'x')
			ft_putstr(ft_unitoa_base(
				va_arg(ap, unsigned int), 16, 'a'));
		else if (format[i] == 'X')
			ft_putstr(ft_unitoa_base(
				va_arg(ap, unsigned int), 16, 'A'));
		else if (format[i] == 'c')
			ft_putchar((char)(va_arg(ap, int)));//+C
		i++;
	}
	va_end(ap); 
	return (1);
}






void	cheat_print_specifies(t_specifies *specifies)
{
	printf("flag : %c\n", specifies->flag);
	printf("width : %d\n", specifies->width);
	printf("precision : %d\n", specifies->precision);
	printf("length : %c\n", specifies->length);
	printf("type : %c\n", specifies->type);
}

int main(void)
{
	t_specifies *specifies;
	char *str = "#*.*llD5";
	int i;

	i = 0;
	// ft_printf("hey : %d %x\n", -123, 8);
	printf("%04.3d\n", 10);
	printf("%04d\n", -15);
	// printf("%s\n", ft_unitoa_base(110, 16, 'A'));
	// ft_printf("%u\n", (long)4294967296);
	// printf("%#11111115x\n", 15);

	/*check get flags*/
	// specifies = ft_new_specifies();
	// i = ft_get_specifies(str, specifies);
	// printf("result : %d\n", i);
	// cheat_print_specifies(specifies);
	return (0);
}
