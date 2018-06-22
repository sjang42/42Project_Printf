/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealwidth.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:15:40 by sjang             #+#    #+#             */
/*   Updated: 2016/10/28 15:15:41 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int  ft_dealw_getdiff(t_specifies *specifies, char **str)
{
    int diff;

    diff = (specifies->width - ft_strlen(*str));
    if ((specifies->type == 'c' || specifies->type == 'C') &&
        specifies->firstch == 0)
        diff--;
    return (diff);
}

static void ft_dealw_addwidth(t_specifies *specifies, char **str, int diff)
{
    char    *temp;

    temp = (char*)malloc(sizeof(char) * (ft_strlen(*str) + diff + 1));
    temp[ft_strlen(*str) + diff] = 0;
    if (!specifies->fromleft)
    {
        ft_memset(temp, ' ', diff);
        ft_memcpy(temp + diff, *str, ft_strlen(*str));
        free(*str);
        *str = temp;
    }
    else
    {
        ft_strcpy(temp, *str);
        ft_memset(temp + ft_strlen(*str), ' ', diff);
        free(*str);
        *str = temp;
    }
}

int         ft_dealwidth(t_specifies *specifies, char **str)
{
    int diff;

    diff = ft_dealw_getdiff(specifies, str);
    if (specifies->width == 0
        || (specifies->fromleft != 1 && specifies->flag & FLAG_ZERO &&
            specifies->thereisprecision == 0)
        || diff <= 0)
        return (1);
    ft_dealw_addwidth(specifies, str, diff);
    return (1);
}
