/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealspecifies.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 19:31:58 by sjang             #+#    #+#             */
/*   Updated: 2016/10/26 19:31:59 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void ft_dealf_zero(t_specifies *specifies, char **str,
                            int diff, char *temp)
{
    diff = specifies->width - ft_strlen(*str);
    if (((specifies->type == 'x' || specifies->type == 'X') &&
        specifies->flag & FLAG_SHARP && specifies->firstch != '0')
        || specifies->type == 'p')
        diff -= 2;
    else if (((specifies->type == 'o' || specifies->type == 'O') &&
        specifies->flag & FLAG_SHARP && specifies->firstch != '0')
        || ((specifies->flag & FLAG_PLUS || specifies->firstch == '-') &&
            (specifies->type == 'd' || specifies->type == 'D' ||
            specifies->type == 'i'))
        || (specifies->flag & FLAG_SPACE &&
            specifies->type != 'c' && specifies->type != 'C' &&
            specifies->type != 's' && specifies->type != 'S')
        || ((specifies->type == 'c' || specifies->type == 'C') &&
            specifies->firstch == 0))
        diff -= 1;
    if (diff > 0)
    {
        temp = (char*)malloc(sizeof(char) * (ft_strlen(*str) + diff + 1));
        ft_memset(temp, '0', diff);
        temp[diff] = 0;
        ft_strcat(temp, *str);
        free(*str);
        *str = temp;
    }
}

static void ft_dealf_sharp(t_specifies *specifies, char **str, char *temp)
{
    if (specifies->firstch == '0' && specifies->type != 'p')
        ;
    else if (specifies->type == 'o' || specifies->type == 'O')
    {
        temp = (char*)malloc(sizeof(char) * (ft_strlen(*str) + 1));
        temp[0] = '0';
        temp[1] = 0;
        ft_strcat(temp, *str);
        free(*str);
        *str = temp;
    }
    else if (specifies->type == 'x' || specifies->type == 'X' ||
            specifies->type == 'p')
    {
        temp = (char*)malloc(sizeof(char) * (ft_strlen(*str) + 2));
        temp[0] = '0';
        temp[1] = ((specifies->type == 'X') ? 'X' : 'x');
        temp[2] = 0;
        ft_strcat(temp, *str);
        free(*str);
        *str = temp;
    }
}

static void ft_dealf_ps(t_specifies *specifies, char **str, char *temp)
{
    temp = (char*)malloc(sizeof(char) * (ft_strlen(*str) + 1));
    ft_memcpy(temp, *str, ft_strlen(*str) + 1);
    free(*str);
    *str = (char*)malloc(sizeof(char) * (ft_strlen(*str) + 2));
    if (specifies->firstch == '-')
        (*str)[0] = '-';
    else if (specifies->flag & FLAG_PLUS)
        (*str)[0] = '+';
    else
        (*str)[0] = ' ';
    (*str)[1] = 0;
    ft_strcat(*str, temp);
    free(temp);
}

int         ft_dealflag(t_specifies *specifies, char **str)
{
    if (specifies->flag & FLAG_ZERO && specifies->fromleft != 1 &&
        (specifies->thereisprecision != 1 || specifies->type == '%' ||
        specifies->type == 'c' || specifies->type == 'C' ||
        specifies->type == 's' || specifies->type == 'S' ||
        specifies->specialtype == 1))
    {
        ft_dealf_zero(specifies, str, 0, 0);
    }
    if (specifies->flag & FLAG_SHARP)
    {
        ft_dealf_sharp(specifies, str, 0);
    }
    if ((specifies->flag & FLAG_PLUS || specifies->flag & FLAG_SPACE ||
        specifies->firstch == '-') && (specifies->type == 'i' ||
        specifies->type == 'd' || specifies->type == 'D'))
    {
        ft_dealf_ps(specifies, str, 0);
    }
    return (1);
}
