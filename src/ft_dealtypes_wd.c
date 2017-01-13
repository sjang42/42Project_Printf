/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealtypes_wd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:08:46 by sjang             #+#    #+#             */
/*   Updated: 2016/11/09 20:08:49 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int			ft_countbites_wd(wchar_t *str_wd)
{
	int count;
	int i;
	int j;

	count = 0;
	i = 0;
	j = 0;
	while (str_wd[i])
	{
		if (((unsigned char*)str_wd)[j + 0])
			count++;
		if (((unsigned char*)str_wd)[j + 1])
			count++;
		if (((unsigned char*)str_wd)[j + 2])
			count++;
		if (((unsigned char*)str_wd)[j + 3])
			count++;
		i++;
		j += 4;
	}
	return (count);
}

static char			*ft_removezero(wchar_t *wstr)
{
	char	*ret;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	ret = (char*)malloc(sizeof(char) * (ft_countbites_wd(wstr) + 1));
	while (wstr[i])
	{
		if (((char*)wstr)[j + 0])
			ret[k++] = ((char*)wstr)[j + 0];
		if (((char*)wstr)[j + 1])
			ret[k++] = ((char*)wstr)[j + 1];
		if (((char*)wstr)[j + 2])
			ret[k++] = ((char*)wstr)[j + 2];
		if (((char*)wstr)[j + 3])
			ret[k++] = ((char*)wstr)[j + 3];
		j += 4;
		i++;
	}
	ret[k] = 0;
	return (ret);
}

static wchar_t		*ft_dealtw_getsc(t_specifies *specifies, va_list ap)
{
	wchar_t *tmp;
	wchar_t *str_wd;

	str_wd = NULL;
	if (specifies->type == 'S' ||
		(specifies->length == 'l' && specifies->type == 's'))
	{
		str_wd = (wchar_t*)va_arg(ap, wchar_t*);
		if (!str_wd)
			str_wd = ft_utf8to32le(L"(null)");
		else
			str_wd = ft_utf8to32le(str_wd);
	}
	else if (specifies->type == 'C' ||
			(specifies->length == 'l' && specifies->type == 'c'))
	{
		str_wd = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		(str_wd)[0] = (wchar_t)va_arg(ap, wchar_t);
		(str_wd)[1] = 0;
		tmp = ft_utf8to32le(str_wd);
		free(str_wd);
		str_wd = tmp;
	}
	return (str_wd);
}

int					ft_dealtypes_wd(t_specifies *specifies,
									va_list ap, char **str)
{
	wchar_t *str_wd;

	str_wd = ft_dealtw_getsc(specifies, ap);
	specifies->firstch = (str_wd)[0];
	if (str_wd)
	{
		*str = ft_removezero(str_wd);
		free(str_wd);
		return (1);
	}
	return (0);
}
