/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 00:07:48 by mlebrun           #+#    #+#             */
/*   Updated: 2020/10/19 15:26:00 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include "libft/libft.h"

int		main(void)
{  
	int		a;
	
	a = 3;	
	printf("LETk'S TEST THAT LITTLE BABY\n");
	printf("INT:\n");
	printf("EXPECTED      : %d\n", 667);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %d\n", 667);

	printf("EXPECTED      : %05d\n", 55);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %05d\n", 55);
	printf("EXPECTED      : %-6d\n", 3);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %-6d\n", 3);
	printf("EXPECTED      : %*d\n", 7, 50);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %*d\n", 7, 50);
	printf("EXPECTED      : %-2.5d\n", 6);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %-2.5d\n", 6);
	printf("EXPECTED      : %56d\n", 2);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %56d\n", 2);
	printf("EXPECTED      : %07.4d\n", 8);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %07.4d\n", 8);
	printf("EXPECTED      : %.*d\n", 6, 6);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %.*d\n", 6, 6);
	printf("EXPECTED      : %05.3d\n", 9);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %05.3d\n", 9);
	printf("EXPECTED      : %0\*.\*d\n", 9, 9, 3);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %0\*.\*d\n", 9, 9, 3);
	printf("EXPECTED      : %03d %5d\n", 5, 6);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %03d %5d\n", 5, 6);
	printf("CHAR :\n\n");
	fflush(stdout);
	printf("EXPECTED      : %c %3c\n", 'c', 'u');
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %c %3c\n", 'c', 'u');
	printf("POINTER :\n\n");
	printf("EXPECTED      : %p %20p\n", &a, &a);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %p %20p\n", &a, &a);
	printf("STRING :\n\n");
	printf("EXPECTED      : %s %10s\n", "oui", "non");
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %s %10s\n", "oui", "non");
	printf("EXPECTED      : %s %10s\n", "oui", "non");
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %s %10s\n", "oui", "non");
	printf("EXPECTED      : %020u \n", 4294967295);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %020u \n", 4294967295);
	printf("EXPECTED      : %020x \n", 123456);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %020x \n", 123456);
	printf("EXPECTED      : %-20X \n", 523698);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %-20X \n", 523698);
	printf("EXPECTED      : %0.16X \n", 159784);
	fflush(stdout);
	ft_printf("YOUR FUNCTION : %0.16X \n", 159784);
	return (0);
}
