/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 06:44:24 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/23 17:14:01 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include "includes/libft.h"

int		main(void)
{
	double			nb;

	nb = 299999787887789.999399990945678;
	printf("%.20f\n", nb);
	fflush(stdout);
	ft_printf("my=%15.1f\n", nb);
	printf("th=%15.1f\n", nb);
	return (0);
}
