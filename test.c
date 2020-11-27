/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun </var/mail/mlebrun>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:34:18 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 08:19:56 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"

int		main(void)
{
	char	test[] = "salut";
//	ft_printf("salut%zrtzrt", 0);
//	printf("%wrtwrt", 0);
	ft_printf("%5.p\n", NULL);
//	printf("%5.p\n", NULL);
	return (0);
}
