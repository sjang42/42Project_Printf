/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealprecision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 15:53:06 by sjang             #+#    #+#             */
/*   Updated: 2016/10/28 15:53:06 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int		ft_dealp_getdiff(t_specifies *specifies, char **str)
{
	int diff;

	diff = specifies->precision - ft_strlen(*str);
	if ((specifies->type == 'o' || specifies->type == 'O') &&
		specifies->firstch != '0' && specifies->flag & FLAG_SHARP)
		diff--;
	return (diff);
}

static void		ft_dealp_nchars(char **str, int diff)
{
	char *temp;

	temp = (char*)malloc(ft_strlen(*str) + diff + 1);
	ft_memset(temp, '0', diff);
	temp[diff] = 0;
	ft_strcat(temp + diff, (*str));
	free(*str);
	*str = temp;
}

static void		ft_dealp_wchars(t_specifies *specifies, char **str)
{
	int i;

	i = specifies->precision;
	while (1)
	{
		if ((unsigned char)((*str)[i]) < 0x80)
		{
			(*str)[i] = 0;
			break ;
		}
		else if ((unsigned char)((*str)[i]) < 0xc0)
			i--;
		else
		{
			(*str)[i] = 0;
			break ;
		}
	}
}

static void		ft_dealp_chars(t_specifies *specifies, char **str)
{
	if (specifies->precision >= 0)
		(*str)[specifies->precision] = 0;
	else if (specifies->precision < -1)
		(*str)[0] = 0;
}

int				ft_dealprecision(t_specifies *specifies, char **str)
{
	int	diff;

	diff = ft_dealp_getdiff(specifies, str);
	if ((specifies->type == 'd' || specifies->type == 'D' ||
		specifies->type == 'u' || specifies->type == 'U' ||
		specifies->type == 'o' || specifies->type == 'O' ||
		specifies->type == 'x' || specifies->type == 'X' ||
		specifies->type == 'i' || specifies->type == 'p') &&
		diff > 0 && specifies->precision > 0)
	{
		ft_dealp_nchars(str, diff);
	}
	if ((specifies->type == 'S' || (specifies->type == 's' &&
		specifies->length == 'l')) && diff < 0 &&
		specifies->thereisprecision && specifies->precision >= 0)
	{
		ft_dealp_wchars(specifies, str);
	}
	else if (specifies->type == 's' && diff < 0 &&
		specifies->thereisprecision)
	{
		ft_dealp_chars(specifies, str);
	}
	return (specifies->precision);
}
