/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sylvain <sylvain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:16:51 by sylvain           #+#    #+#             */
/*   Updated: 2022/02/14 16:40:02 by sylvain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"

int main() {
    char a = 'a';
    ft_printf("Hello %c coucou %c %s - %s | pointer %p\n", 'a', 'b', "ca va", "re hello", &a);
    printf("Hello %c coucou %c %s - %s | pointer %p\n", 'a', 'b', "ca va", "re hello", &a);

    // printf("Hello");
}