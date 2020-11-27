/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun </var/mail/mlebrun>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:34:18 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 09:05:02 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		main(void)
{
	char	test[] = "salut";
//	ft_printf("salut%zrtzrt", 0);
//	printf("%wrtwrt", 0);
	ft_printf("% #-+010u", -2147483647, - 1);
	fflush(stdout);
	printf("% #-+010u", -2147483647, - 1);
//	printf("%5.p\n", NULL);
	return (0);
}
