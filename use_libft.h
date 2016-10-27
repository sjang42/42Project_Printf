/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_libft.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 17:50:15 by sjang             #+#    #+#             */
/*   Updated: 2016/10/22 17:50:16 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef USE_LIBFT_H
# define USE_LIBFT_H

#include <unistd.h>

void	ft_putchar(char c);
static int	get_positional_int(int nb);
void		ft_putnbr(int nb);
void	ft_putstr(char const *s);
int		ft_isdigit(int c);

#endif