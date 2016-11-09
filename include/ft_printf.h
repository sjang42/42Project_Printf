/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 17:26:40 by sjang             #+#    #+#             */
/*   Updated: 2016/10/25 17:27:01 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# include "../include/libft.h"

typedef int					WCHAR_T;
typedef int					WINT_T;
typedef long long			INTMAX_T;
typedef long long			SIGNED_SIZE_T;
typedef unsigned long long	UINTMAX_T;

#define ABSOL(x) ((x) >= 0) ? (x) : ((x) * -1)

enum						e_printfflags
{
	FLAG_NOTHING = 0,
	FLAG_ZERO = 1,
	FLAG_SHARP = 1 << 1,
	FLAG_MINUS = 1 << 2,
	FLAG_PLUS = 1 << 3,
	FLAG_SPACE = 1 << 4,
	ALL = FLAG_ZERO | FLAG_SHARP | FLAG_MINUS | FLAG_PLUS | FLAG_SPACE
}							printfflags;

typedef struct				s_specifies
{
	enum e_printfflags		flag;
	int						width;
	int						precision;
	int						thereisprecision;
	int						thereiswidth;
	int						fromleft;
	int						firstch;
	int						specialtype;
	int						widechar;
	char					length;
	char					type;
}							t_specifies;

int							ft_printf(const char *restrict format, ...);

int							ft_get_flag(const char *restrict format, enum e_printfflags	*flag);
int							ft_get_width(const char *restrict format, t_specifies *specifies, va_list ap);
int							ft_get_precision(const char *restrict format, t_specifies *specifies, va_list ap);
int							ft_get_length(const char *restrict format, char *length);
int							ft_get_type(const char *restrict format, t_specifies *specifies);


t_specifies					*ft_new_specifies(void);
int 						ft_get_specifies(const char *restrict format, t_specifies *specifies, va_list ap);

int							ft_dealflag(t_specifies *specifies, char **str);
int							ft_dealwidth(t_specifies *specifies, char **str);
int							ft_dealprecision(t_specifies *specifies, char **str);
int 						ft_dealtypes(t_specifies *specifies, va_list ap, char **str);

int							ft_dealminus(t_specifies *specifies, char **str);


int 						ft_dealtypes_wd(t_specifies *specifies, va_list ap, WCHAR_T **str_wd, char **str);

int 						ft_dealtypes_getbase(t_specifies *specifies);

char						*ft_itoa_base_prtf(size_t value, int base, char small);

char						*ft_mknbr_longlong(long long nb);
char						*ft_mknbr_sizet(size_t nb);

WINT_T						*ft_strcpy_wd(WINT_T *dst, const WINT_T *src);
size_t						ft_strlen_wd(const WINT_T *s);
WINT_T						*ft_strdup_wd(const WINT_T *s);

int							ft_putchar_wd(char const ch);
void						ft_putstr_wd(WCHAR_T const *str);
int							ft_countbites(wchar_t *str_wd);


wchar_t						*ft_utf8to32le(wchar_t *wstr);
char	*ft_removezero(wchar_t *wstr);

#endif
