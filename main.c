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

#include "main.h"
#include "string.h"
#include <locale.h>

int main(void)
{
	int size[3];

	setlocale(LC_ALL, "");
	size[0] = ft_printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	printf("%s\n", "");
	size[1] = printf("%s %C %d %p %x %% %S", "bonjour ", L'該', 42, &free, 42, L"لحم خنزير");
	printf("%s\n", "");
	printf("my size: %d\n", size[0]);
	printf("sy size: %d\n", size[1]);
	return (0);
}
