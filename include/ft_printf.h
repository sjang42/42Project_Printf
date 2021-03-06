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

typedef long long           t_inxmax_t;
typedef long long           t_signed_size_t;
typedef unsigned long long  t_uintmax_t;

# define ABSOL(x) ((x) >= 0) ? (x) : ((x) * -1)

enum                        e_printfflags
{
    FLAG_NOTHING = 0,
    FLAG_ZERO = 1,
    FLAG_SHARP = 1 << 1,
    FLAG_MINUS = 1 << 2,
    FLAG_PLUS = 1 << 3,
    FLAG_SPACE = 1 << 4,
    ALL = FLAG_ZERO | FLAG_SHARP | FLAG_MINUS | FLAG_PLUS | FLAG_SPACE
}                           printfflags;

typedef struct              s_specifies
{
    enum e_printfflags      flag;
    int                     width;
    int                     precision;
    int                     thereisprecision;
    int                     thereiswidth;
    int                     fromleft;
    int                     firstch;
    int                     specialtype;
    char                    length;
    char                    type;
}                           t_specifies;

typedef struct              s_precisions
{
    int                     minus;
    int                     tempprecision;
    int                     i;
    int                     star;
}                           t_precisions;

typedef struct              s_widths
{
    int                     tempwidth;
    int                     i;
    int                     star;
}                           t_widths;

int                         ft_printf(
                                const char *restrict format, ...);

t_specifies                 *ft_new_specifies(
                                void);

int                         ft_get_specifies(
                                const char *restrict format,
                                t_specifies *specifies, va_list ap);
int                         ft_get_flag(
                                const char *restrict format,
                                t_specifies *specifies);
int                         ft_get_width(
                                const char *restrict format,
                                t_specifies *specifies,
                                va_list ap);
int                         ft_get_precision(
                                const char *restrict format,
                                t_specifies *specifies,
                                va_list ap);
int                         ft_get_length(
                                const char *restrict format,
                                char *length);
int                         ft_get_type(
                                const char *restrict format,
                                t_specifies *specifies);
int                         ft_dealflag(
                                t_specifies *specifies,
                                char **str);
int                         ft_dealwidth(
                                t_specifies *specifies,
                                char **str);
int                         ft_dealprecision(
                                t_specifies *specifies,
                                char **str);
int                         ft_dealtypes(
                                t_specifies *specifies,
                                va_list ap,
                                char **str);
int                         ft_dealtypes_wd(
                                t_specifies *specifies,
                                va_list ap,
                                char **str);

int                         ft_dealtypes_getbase(
                                t_specifies *specifies);
void                        ft_dealtypes_psc(
                                t_specifies *specifies,
                                va_list ap,
                                char **str);
void                        ft_dealtypes_special(
                                t_specifies *specifies,
                                char **str);
int                         ft_dealminus(
                                t_specifies *specifies,
                                char **str);
char                        *ft_itoa_base_prtf(
                                size_t value, int base,
                                char small);
char                        *ft_mknbr_longlong(
                                long long nb);
char                        *ft_mknbr_sizet(
                                size_t nb);
wchar_t                     *ft_utf8to32le(
                                wchar_t *wstr);
wchar_t                     *ft_strcpy_wd(
                                wchar_t *dst,
                                const wchar_t *src);
size_t                      ft_strlen_wd(
                                const wchar_t *s);
wchar_t                     *ft_strdup_wd(
                                const wchar_t *s);
int                         ft_putchar_wd(
                                char const ch);
void                        ft_putstr_wd(
                                wchar_t const *str);

size_t                      ft_strlen(
                                const char *s);
char                        *ft_strdup(
                                const char *s);
char                        *ft_strcat(
                                char *dest,
                                const char *src);
char                        *ft_strcpy(
                                char *dst,
                                const char *src);
void                        ft_putstr(
                                char const *s);
void                        ft_putchar(
                                char c);
void                        *ft_memset(
                                void *dest,
                                int c,
                                size_t len);
void                        *ft_memmove(
                                void *dest,
                                const void *src,
                                size_t n);
void                        *ft_memset(
                                void *dest,
                                int c,
                                size_t len);
void                        *ft_memmove(
                                void *dest,
                                const void *src,
                                size_t n);
void                        *ft_memcpy(
                                void *dest,
                                const void *src,
                                size_t count);
int                         ft_isdigit(
                                int c);
#endif
