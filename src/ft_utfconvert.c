/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utfconvert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 22:33:17 by sjang             #+#    #+#             */
/*   Updated: 2016/11/07 22:33:19 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void		ft_utf_put12(wchar_t *ret, wchar_t wc, int j)
{
	if (wc < 0x80)
	{
		((unsigned char*)ret)[j + 0] = (char)wc;
		((unsigned char*)ret)[j + 1] = 0;
		((unsigned char*)ret)[j + 2] = 0;
		((unsigned char*)ret)[j + 3] = 0;
	}
	else if (wc < 0x800)
	{
		((unsigned char*)ret)[j + 0] = 0xC0 | (wc >> 6);
		((unsigned char*)ret)[j + 1] = 0x80 | (wc & 0x3F);
		((unsigned char*)ret)[j + 2] = 0;
		((unsigned char*)ret)[j + 3] = 0;
	}
}

static void		ft_utf_put34(wchar_t *ret, wchar_t wc, int j)
{
	if (wc < 0x800)
		;
	else if (wc < 0x10000)
	{
		((unsigned char*)ret)[j + 0] = 0xE0 | (wc >> 12);
		((unsigned char*)ret)[j + 1] = 0x80 | ((wc >> 6) & 0x3F);
		((unsigned char*)ret)[j + 2] = 0x80 | (wc & 0x3F);
		((unsigned char*)ret)[j + 3] = 0;
	}
	else if (wc < 0x200000)
	{
		((unsigned char*)ret)[j + 0] = 0xF0 | (wc >> 18);
		((unsigned char*)ret)[j + 1] = 0x80 | ((wc >> 12) & 0x3F);
		((unsigned char*)ret)[j + 2] = 0x80 | ((wc >> 6) & 0x3F);
		((unsigned char*)ret)[j + 3] = 0x80 | (wc & 0x3F);
	}
}

wchar_t			*ft_utf8to32le(wchar_t *wstr)
{
	wchar_t	*ret;
	int		i;
	int		j;

	ret = (wchar_t*)malloc(sizeof(wchar_t) * (ft_strlen_wd(wstr) + 1));
	i = 0;
	j = 0;
	while (wstr[i])
	{
		ft_utf_put12(ret, wstr[i], j);
		ft_utf_put34(ret, wstr[i], j);
		i++;
		j += 4;
	}
	ret[i] = 0;
	return (ret);
}
