/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/26 16:32:35 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_init_unsigned(t_format *format_parsed, t_nb *nb)
{
	int		size_nb;

	size_nb = ft_size_hexa_dec(format_parsed, nb);
	if (nb->ull == 0 && format_parsed->prec == 0)
		size_nb = 0;
	if (nb->ull == 0)
		format_parsed->hashtag_flag = 0;
	if (format_parsed->minus_flag)
		ft_display_int_minus_flag(format_parsed, nb, size_nb);
	else
		ft_display_int(format_parsed, nb, size_nb);
}

void	ft_init_signed(t_format *format_parsed, t_nb *nb)
{
	int		size_nb;

	if (nb->ll < 0)
	{
		format_parsed->negative = 1;
		format_parsed->plus_flag = 0;
	}
	if (nb->ll < 0 || format_parsed->plus_flag == 1)
		format_parsed->space_flag = 0;
	size_nb = ft_size_hexa_dec(format_parsed, nb);
	if (nb->ll == 0 && format_parsed->prec == 0)
		size_nb = 0;
	if (format_parsed->minus_flag)
		ft_display_int_minus_flag(format_parsed, nb, size_nb);
	else
	{
		ft_display_int(format_parsed, nb, size_nb);
	}
}

void	ft_display_integer(t_format *format_parsed, va_list arg)
{
	t_nb						*nb;

	nb = ft_stocknb(arg, format_parsed);
	if (format_parsed->type == 'u' || format_parsed->type == 'x'
		|| format_parsed->type == 'X')
		ft_init_unsigned(format_parsed, nb);
	else
		ft_init_signed(format_parsed, nb);
}
