/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:16:51 by sylvain           #+#    #+#             */
/*   Updated: 2022/04/01 12:37:33 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <assert.h>
// #include "src/ft_printf.h"

// int	main(void)
// {
// 	printf("TEST CHAR\n");
// 	printf("-----------\n");
// 	ft_printf("%c\n", 'a');
// 	printf("%c\n", 'a');
// 	printf("\n\n");

// 	printf("TEST STR\n");
// 	printf("-----------\n");
// 	ft_printf("%s -- %s\n",  "ca va", "heee");
// 	printf("%s -- %s\n",  "ca va", "heee");
// 	printf("\n\n");

// 	ft_printf(" NULL %s NULL ", '\0');
// 	// printf(" NULL %s NULL ", '\0');
// 	printf("\n\n");

// 	printf("TEST POINTER\n");
// 	printf("-----------\n");
// 	char a;
// 	int b;
// 	ft_printf("%p - %p\n", &a, &b);
// 	printf("%p - %p\n", &a, &b);
// 	printf("\n\n");

// 	printf("TEST DECIMAL\n");
// 	printf("-----------\n");
// 	ft_printf("%i - %i\n", INT_MAX, ft_printf("%i", INT_MAX));
// 	printf("%i - %i\n", INT_MAX, printf("%i", INT_MAX));
// 	printf("\n\n");
// 	ft_printf("%i\n", INT_MIN);
// 	printf("%i\n", INT_MIN);
// 	printf("\n\n");

// 	printf("TEST UNSIGNED\n");
// 	printf("-----------\n");
// 	ft_printf("%u - %u\n", -1, ft_printf("%u", -1));
// 	printf("%u - %u\n", -1, printf("%u", -1));
// 	printf("\n\n");
// 	ft_printf("%u - %u\n", INT_MAX, ft_printf("%u", INT_MAX));
// 	printf("%u - %u\n", INT_MAX, printf("%u", INT_MAX));
// 	printf("\n\n");
// 	ft_printf("%u - %u\n", INT_MIN, ft_printf("%u", INT_MIN));
// 	printf("%u - %u\n", INT_MIN, printf("%u", INT_MIN));
// 	printf("\n\n");

// 	printf("TEST HEXA\n");
// 	printf("-----------\n");
// 	ft_printf("%x - %x\n", -1, ft_printf("%x", -1));
// 	printf("%x - %x\n", -1, printf("%x", -1));
// 	printf("\n\n");
// 	ft_printf("%x - %x\n", INT_MAX, ft_printf("%x", INT_MAX));
// 	printf("%x - %x\n", INT_MAX, printf("%x", INT_MAX));
// 	printf("\n\n");
// 	ft_printf("%x - %x\n", INT_MIN, ft_printf("%x", INT_MIN));
// 	printf("%x - %x\n", INT_MIN, printf("%x", INT_MIN));
// 	printf("\n\n");
// }