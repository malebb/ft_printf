/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 06:33:32 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/22 12:33:49 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_display_float(t_format *format_parsed, va_list arg)
{
	float			nb;
	float			after_comma;
	long long int	before_comma;

	nb = va_arg(arg, double);
	printf("Parsing : %d|%d|%d|%d|%c|%d|%d \n", format_parsed->zero_flag, format_parsed->minus_flag,
	format_parsed->width, format_parsed->prec, format_parsed->type,
	format_parsed->negative, format_parsed->c_read);
//	printf("%f\n", nb);
	if (nb == -1)
		format_parsed->prec = 6;
	before_comma = (long long int)nb;
	after_comma = nb - before_comma;
	ft_llitoa(before_comma);
	printf("%lld | %f\n", before_comma,after_comma);
}
