/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:57:05 by sjang             #+#    #+#             */
/*   Updated: 2016/09/23 12:57:06 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void    *ft_memcpy(void *dest, const void *src, size_t count)
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
