/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:32:18 by sjang             #+#    #+#             */
/*   Updated: 2016/09/23 12:32:26 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void    *ft_memset(void *dest, int c, size_t len)
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
