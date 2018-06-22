/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_prtf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 17:33:47 by sjang             #+#    #+#             */
/*   Updated: 2016/10/31 17:33:48 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int      ft_itoa_getsize(size_t value, int base)
{
    int size;

    size = 0;
    while (value != 0)
    {
        value /= base;
        size++;
    }
    return (size);
}

static char     *ft_itoa_dealzero(void)
{
    char *str;

    str = (char*)malloc(sizeof(char) * 2);
    str[0] = '0';
    str[1] = 0;
    return (str);
}

static char     *ft_itoa_mkstr(size_t value, int base, char small, int size)
{
    int     i;
    int     mod;
    char    *str;

    str = (char*)malloc(sizeof(char) * (size + 1));
    str[size] = 0;
    i = 1;
    while (i <= size)
    {
        mod = value % base;
        if (mod < 10)
            str[size - i] = '0' + mod;
        else
        {
            if (small == 'a')
                str[size - i] = 'a' + mod - 10;
            else
                str[size - i] = 'A' + mod - 10;
        }
        value /= base;
        i++;
    }
    return (str);
}

char            *ft_itoa_base_prtf(size_t value, int base, char small)
{
    int     size;

    if (base <= 1)
        return (0);
    if (value == 0)
        return (ft_itoa_dealzero());
    size = ft_itoa_getsize(value, base);
    return (ft_itoa_mkstr(value, base, small, size));
}
