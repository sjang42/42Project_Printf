/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mknbr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 15:48:17 by sjang             #+#    #+#             */
/*   Updated: 2016/11/01 15:48:18 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>//

static long long	get_positional_longlong(long long nb, int *size)
{
	long long	positional;
	long long	temp;
	int			count;

	positional = 1;
	count = 1;
	temp = nb;
	while (temp >= 10 || temp <= -10)
	{
		temp /= 10;
		positional *= 10;
		count++;
	}
	*size = count;
	return (positional);
}

char				*ft_mknbr_longlong(long long nb)
{
	long long	positional;
	int			i;
	int			size;
	char		*str;

	i = 0;
	positional = get_positional_longlong(nb, &size);
	if (nb < 0)
	{
		size++;
		positional *= -1;
		i++;
	}
	str = (char*)malloc(sizeof(char) * (size + 1));
	if (nb < 0)
		str[0] = '-';
	str[size] = 0;
	while (positional != 0)
	{
		str[i] = nb / positional + '0';
		nb %= positional;
		positional /= 10;
		i++;
	}
	return (str);
}

static size_t		get_positional_sizet(size_t nb, int *size)
{
	long long	positional;
	long long	temp;
	int			count;

	positional = 1;
	count = 1;
	temp = nb;
	while (temp >= 10)
	{
		temp /= 10;
		positional *= 10;
		count++;
	}
	*size = count;
	return (positional);
}

char				*ft_mknbr_sizet(size_t nb)
{
	size_t	positional;
	int		i;
	int		size;
	char	*str;

	i = 0;
	positional = get_positional_sizet(nb, &size);
	str = (char*)malloc(sizeof(char) * (size + 1));
	str[size] = 0;
	while (positional != 0)
	{
		str[i] = nb / positional + '0';
		nb %= positional;
		positional /= 10;
		i++;
	}
	return (str);
}
