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

#include "../include/ft_printf.h"
#include <stdio.h>//

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

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	while (s[count] != 0)
		count++;
	return (count);
}

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != 0)
		i++;
	while (src[j] != 0)
	{
		dest[i + j] = ((char*)src)[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		((char*)dest)[i] = ((char*)src)[i];
		i++;
	}
	return (dest);
}

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((unsigned char*)dest)[i] = (unsigned char)c;
		i++;
	}
	return (dest);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	if (!s)
		return (NULL);
	len = ft_strlen((char*)s);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, len + 1);
	return (str);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dst[i] = ((char*)src)[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t i;

	if (dest == src)
		return (dest);
	else if (dest > src)
	{
		i = n;
		while (i > 0)
		{
			((char*)dest)[i - 1] = ((char*)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
	}
	return (dest);
}

