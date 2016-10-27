/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_libft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 18:15:08 by sjang             #+#    #+#             */
/*   Updated: 2016/10/25 18:15:09 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "use_libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	get_positional_int(int nb)
{
	int positional;
	int temp;

	positional = 1;
	temp = nb;
	while (temp >= 10 || temp <= -10)
	{
		temp /= 10;
		positional *= 10;
	}
	return (positional);
}

void		ft_putnbr(int nb)
{
	char	digit;
	int		positional;

	positional = get_positional_int(nb);
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

void	ft_putstr(char const *s)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != 0)
	{
		write(1, s + i, 1);
		i++;
	}
}

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}


