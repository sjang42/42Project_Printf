/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 22:56:50 by sjang             #+#    #+#             */
/*   Updated: 2016/09/23 22:56:51 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char    *ft_strcat(char *dest, const char *src)
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
