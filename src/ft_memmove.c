/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:58:41 by sjang             #+#    #+#             */
/*   Updated: 2016/09/23 12:58:42 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
