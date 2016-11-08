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
#include <stdio.h>//

wchar_t		*ft_utf8to32le(wchar_t *wstr)
{  
 	wchar_t	*ret;
 	wchar_t	wc;
 	int		i;
 	int		j;

 	ret = (wchar_t*)malloc(sizeof(wchar_t) * (ft_strlen_wd(wstr) + 1));
 	i = 0;
 	j = 0;
 	while (wstr[i])
 	{
 		wc = wstr[i];
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
 		i++;
 		j += 4;
 	}
 	ret[i] = 0;
	return (ret);
}

// unsigned char unicode2utf8(wchar_t uc)  
// {  
//  	unsigned char *ret;
//  	unsigned char u1, u2, u3, u4;

//  	ret = (unsigned char*)malloc(sizeof(char) * 4);

// 	if (uc < 0x80) 
// 	{  
// 		ret[0] = (unsigned char)uc;
// 		ret[1] = 0;
// 		ret[2] = 0;
// 		ret[3] = 0;
// 	}
// 	else if (uc < 0x800) 
// 	{
// 		u2 = 0xC0 | (uc >> 6);
// 		u1 = 0x80 | (uc & 0x3F);
// 		ret[0] = u2;  
// 		ret[1] = u1;
// 		ret[2] = 0;
// 		ret[3] = 0;
// 	}
// 	else if (uc < 0x10000) 
// 	{  
// 		u3 = 0xE0 | (uc >> 12);  
// 		u2 = 0x80 | ((uc >> 6) & 0x3F);  
// 		u1 = 0x80 | (uc & 0x3F);  
// 		ret[0] = u3;  
// 		ret[1] = u2;
// 		ret[2] = u1;
// 		ret[3] = 0;
// 	}
// 	else if (uc < 0x200000) 
// 	{  
// 		u4 = 0xF0 | (uc >> 18);  
// 		u3 = 0x80 | ((uc >> 12) & 0x3F);  
// 		u2 = 0x80 | ((uc >> 6) & 0x3F);  
// 		u1 = 0x80 | (uc & 0x3F);
// 		ret[0] = u4;  
// 		ret[1] = u3;
// 		ret[2] = u2;
// 		ret[3] = u1; 
// 	}
// 	return (ret);
// }
