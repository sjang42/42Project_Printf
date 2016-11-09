/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealprecision_wd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:36:02 by sjang             #+#    #+#             */
/*   Updated: 2016/11/08 14:36:03 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int		ft_dealprecision_wd(t_specifies *specifies, wchar_t **str_wd)
// {
// 	diff = specifies->precision - ft_countbites(*str_wd);

// 	if ((specifies->type == 's' || specifies->type == 'S') &&
// 		diff < 0 && specifies->thereisprecision)
// 	{
// 		if (specifies->precision >= 0)
// 			(*str_wd)[specifies->precision] = 0;
// 		else if (specifies->precision < -1)
// 			(*str_wd)[0] = 0;
// 	}
// }