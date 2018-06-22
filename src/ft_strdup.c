/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:23:11 by sjang             #+#    #+#             */
/*   Updated: 2016/09/23 17:23:12 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char    *ft_strdup(const char *s)
{
    char    *str;
    int     len;

    len = ft_strlen((char*)s);
    str = (char*)malloc(sizeof(*str) * (len + 1));
    if (str == NULL)
        return (NULL);
    ft_memcpy(str, s, len + 1);
    return (str);
}
