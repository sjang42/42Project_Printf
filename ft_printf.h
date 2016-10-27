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

#include <stdlib.h>
#include <stdarg.h>

enum				e_printfflags
{
	FLAG_NOTHING = 0;
	FLAG_ZERO = 1;
	FLAG_SHARP = 1 << 1;
	FLAG_MINUS = 1 << 2;
	FLAG_PLUS = 1 << 3;
	FLAG_SPACE = 1 << 4;
	ALL = FLAG_ZERO | FLAG_SHARP | FLAG_MINUS | FLAG_PLUS | FLAG_SPACE;
}					printflags;

typedef struct		s_specifies
{
	printflags		flags;
	int				width;
	int				precision;
	char			length;
	char			type;
}					t_specifies;




int					ft_get_flag(const char *restrict format, char *flag);
int					ft_get_width(const char *restrict format, int *width);
int					ft_get_precision(const char *restrict format, int *precision);
int					ft_get_length(const char *restrict format, char *length);
int					ft_get_type(const char *restrict format, char *type);

t_specifies			*ft_new_specifies(void);
int 				ft_get_specifies(const char *restrict format, t_specifies *specifies);
#endif
