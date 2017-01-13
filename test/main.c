/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 11:02:37 by sjang             #+#    #+#             */
/*   Updated: 2016/11/05 11:02:38 by sjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <locale.h>
#include "main.h"

int		main(void)
{
	int size[3];

	setlocale(LC_ALL, "");
	size[0] = ft_printf	("%-S\n", L"Test Success!😂");
	size[1] = printf	("%-S\n", L"Test Success!😂");
	printf("my size: %d\n", size[0]);
	printf("sy size: %d\n", size[1]);
	return (0);
}
