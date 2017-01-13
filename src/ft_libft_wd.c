/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_wd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:02:28 by sjang             #+#    #+#             */
/*   Updated: 2016/11/09 20:02:29 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

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
