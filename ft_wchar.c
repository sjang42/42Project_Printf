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

#include "use_libft.h"
#include "ft_printf.h"

WINT_T	*ft_strcpy_wd(WINT_T *dst, const WINT_T *src)
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

size_t	ft_strlen_wd(const WINT_T *s)
{
	size_t count;

	count = 0;
	while (s[count] != 0)
		count++;
	return (count);
}

WINT_T	*ft_strdup_wd(const WINT_T *s)
{
	WINT_T	*str;
	size_t	len;

	len = ft_strlen_wd(s);
	str = (WINT_T*)malloc(sizeof(WINT_T) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strcpy_wd(str, s);
	return (str);
}
