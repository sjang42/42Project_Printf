/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealtypes_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 17:27:38 by sjang             #+#    #+#             */
/*   Updated: 2016/11/01 17:27:40 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int			ft_dealminus(t_specifies *specifies, char **str)
{
	specifies->firstch = (*str)[0];
	if ((*str)[0] == '-' && (specifies->type == 'i' ||
			specifies->type == 'd' || specifies->type == 'D'))
	{
		ft_memmove(*str, (*str) + 1, ft_strlen(*str));
		return (1);
	}
	if (specifies->precision == 0 && specifies->thereisprecision == 1 &&
		(*str)[0] == '0' && specifies->type != 'c' && specifies->type != 'C'
		&& !((specifies->type == 'o' || specifies->type == 'O') &&
			specifies->flag & FLAG_SHARP))
		*str[0] = 0;
	return (0);
}

int			ft_dealtypes_getbase(t_specifies *specifies)
{
	if (specifies->type == 'u' || specifies->type == 'U')
		return (10);
	else if (specifies->type == 'o' || specifies->type == 'O')
		return (8);
	else if (specifies->type == 'x' || specifies->type == 'X' ||
			specifies->type == 'p')
		return (16);
	return (0);
}

void		ft_dealtypes_psc(t_specifies *specifies, va_list ap, char **str)
{
	int base;

	base = ft_dealtypes_getbase(specifies);
	if (specifies->type == 'p')
	{
		*str = ft_itoa_base_prtf((size_t)va_arg(ap, void*)
									, base, 'a');
		specifies->flag |= FLAG_SHARP;
	}
	if (specifies->type == 's')
	{
		*str = (char*)va_arg(ap, char*);
		if (!*str)
			*str = ft_strdup("(null)");
		else
			*str = ft_strdup(*str);
	}
	else if (specifies->type == 'c')
	{
		*str = (char*)malloc(sizeof(char) * 2);
		(*str)[0] = (char)va_arg(ap, int);
		(*str)[1] = 0;
	}
}

void		ft_dealtypes_special(t_specifies *specifies, char **str)
{
	if (specifies->type == '%')
	{
		*str = (char*)malloc(sizeof(char) * 2);
		(*str)[0] = '%';
		(*str)[1] = 0;
	}
	else
	{
		*str = (char*)malloc(sizeof(char) * 2);
		(*str)[0] = specifies->type;
		(*str)[1] = 0;
	}
}
