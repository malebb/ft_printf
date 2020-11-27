/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:01:38 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 11:28:46 by mlebrun          ###   ########.fr       */
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

void	ft_putnbr(long long int nb, t_format *format_parsed)
{
	unsigned long long int		nbr;

	if (nb < 0)
	{
		ft_putchar('-', format_parsed);
		nbr = nb *= -1;
	}
	else
		nbr = (unsigned long long int)nb;
	if (nbr >= 10)
		ft_putnbr(nbr / 10, format_parsed);
	ft_putchar((nbr % 10) + '0', format_parsed);
}
