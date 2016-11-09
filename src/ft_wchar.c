/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 16:36:16 by sjang             #+#    #+#             */
/*   Updated: 2016/11/01 16:36:17 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include <stdio.h>//

wchar_t		*ft_strcpy_wd(wchar_t *dst, const wchar_t *src)
{
	int i;

	i = 0;
	while (src[i] != 0)
	{
		dst[i] = (src)[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

size_t		ft_strlen_wd(const wchar_t *s)
{
	size_t count;

	count = 0;
	while (s[count] != 0)
		count++;
	return (count);
}

wchar_t		*ft_strdup_wd(const wchar_t *s)
{
	wchar_t	*str;
	size_t	len;

	len = ft_strlen_wd(s);
	str = (wchar_t*)malloc(sizeof(wchar_t) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy_wd(str, s);
	return (str);
}

int			ft_mkcpwd(wchar_t **str_wd, char **str)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen_wd(*str_wd);
	*str = (char*)malloc(sizeof(char) * size + 1);
	while ((*str_wd)[i])
	{
		(*str)[i] = (char)((*str_wd)[i]);
		i++;
	}
	(*str)[i] = 0;
	return (1);
}

int			ft_putchar_wd(char const ch)
{
	write(1, &ch, sizeof(wchar_t));
	return (1);
}

void		ft_putstr_wd(wchar_t const *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		write(1, str + i, sizeof(wchar_t));
		i++;
	}
}

int 		ft_mkemptystr(wchar_t *str_wd, char **str)
{
	int size;

	size = ft_strlen_wd(str_wd);
	*str = (char*)malloc(sizeof(char) * size + 1);
	ft_memset(*str, 1, size);
	(*str)[size] = 0;
	return (size);
}

int			ft_countbites(wchar_t *str_wd)
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

void			ft_showbyte(unsigned char value)
{
	if (value / 128 == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if ((value % 128) / 64 == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if ((value % 64) / 32 == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if ((value % 32) / 16 == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if ((value % 16) / 8 == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if ((value % 8) / 4 == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if ((value % 4) / 2 == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
	if ((value % 2) == 1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int 		ft_dealtypes_wd(t_specifies *specifies, va_list ap,
							wchar_t **str_wd, char **str)
{
	wchar_t *tmp;

	if (specifies->type == 'S' ||
		(specifies->length == 'l' && specifies->type == 's'))
	{
		*str_wd = (wchar_t*)va_arg(ap, wchar_t*);
		if (!*str_wd)
			*str_wd = ft_utf8to32le(L"(null)");
		else
			*str_wd = ft_utf8to32le(*str_wd);
	}
	else if (specifies->type == 'C' ||
			(specifies->length == 'l' && specifies->type == 'c'))
	{
		*str_wd = (wchar_t*)malloc(sizeof(wchar_t) * 2);
		(*str_wd)[0] = (wchar_t)va_arg(ap, wchar_t);
		(*str_wd)[1] = 0;
		tmp = ft_utf8to32le(*str_wd);
		free(*str_wd);
		*str_wd = tmp;
	}
	specifies->firstch = (*str_wd)[0];
	if (*str_wd)
	{
		*str = ft_removezero(*str_wd);
		free(*str_wd);
		return (1);
	}
	return (0);
}




// int 		ft_dealtypes_wd(t_specifies *specifies, va_list ap,
// 							wchar_t **str_wd, char **str)
// {
// 	if (specifies->type == 'S' ||
// 		(specifies->length == 'l' && specifies->type == 's'))
// 	{
// 		*str_wd = (wchar_t*)va_arg(ap, wchar_t*);
// 		if (!*str_wd)
// 			*str_wd = ft_strdup_wd(L"(null)");
// 		else
// 			*str_wd = ft_strdup_wd(*str_wd);
// 	}
// 	else if (specifies->type == 'C' ||
// 			(specifies->length == 'l' && specifies->type == 'c'))
// 	{
// 		*str_wd = (wchar_t*)malloc(sizeof(wchar_t) * 2);
// 		(*str_wd)[0] = (char)va_arg(ap, wchar_t);
// 		(*str_wd)[1] = 0;
// 	}
// 	specifies->firstch = (*str_wd)[0];
// 	if (*str_wd)
// 	{
// 		ft_mkemptystr(*str_wd, str);
// 		return (ft_strlen_wd(*str_wd));
// 	}
// 	return (0);
// }
