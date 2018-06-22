/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getspecifies_sub2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:29:48 by sjang             #+#    #+#             */
/*   Updated: 2016/11/09 19:29:49 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static void ft_getp_getprecision(const char *restrict format,
                                            va_list ap,
                                            t_precisions *pr)
{
    while (format[pr->i] != 0 && !ft_get_length(format + pr->i, NULL) &&
            !ft_get_type(format + pr->i, NULL))
    {
        if (pr->i == 1 && format[pr->i] == '*' && ap)
        {
            if ((pr->tempprecision = (int)va_arg(ap, int)) < 0)
                pr->minus = -1;
            pr->star = 1;
        }
        else if (pr->i == 1 && format[1] == '-')
            pr->minus = -1;
        else if (ft_isdigit(format[pr->i]))
        {
            if (pr->star)
            {
                pr->tempprecision = 0;
                pr->star = 0;
            }
            pr->tempprecision = (pr->tempprecision * 10) +
                                (format[pr->i] - '0');
        }
        else
            break ;
        (pr->i)++;
    }
}

static void ft_getp_put(t_specifies *specifies, t_precisions *pr)
{
    if (specifies)
    {
        if (!specifies->thereiswidth && pr->minus == -1)
        {
            specifies->width = pr->tempprecision;
            specifies->thereisprecision = 0;
            specifies->fromleft = 1;
        }
        else if (pr->minus == -1)
            specifies->thereisprecision = 0;
        else
            specifies->precision = pr->tempprecision * pr->minus;
    }
}

int         ft_get_precision(const char *restrict format,
                            t_specifies *specifies, va_list ap)
{
    t_precisions    precisions;

    precisions.minus = 1;
    precisions.tempprecision = 0;
    precisions.i = 1;
    precisions.star = 0;
    if (format[0] != '.')
        return (0);
    else if (specifies)
        specifies->thereisprecision = 1;
    ft_getp_getprecision(format, ap, &precisions);
    ft_getp_put(specifies, &precisions);
    return (precisions.i);
}

int         ft_get_type(const char *restrict format, t_specifies *specifies)
{
    if (format[0] == 's' || format[0] == 'S' || format[0] == 'p' ||
        format[0] == 'd' || format[0] == 'D' || format[0] == 'i' ||
        format[0] == 'o' || format[0] == 'O' || format[0] == 'u' ||
        format[0] == 'U' || format[0] == 'x' || format[0] == 'X' ||
        format[0] == 'c' || format[0] == 'C' || format[0] == '%')
    {
        if (specifies)
            specifies->type = format[0];
        return (1);
    }
    else if (specifies && format[0])
    {
        specifies->type = format[0];
        specifies->specialtype = 1;
        return (1);
    }
    return (0);
}
