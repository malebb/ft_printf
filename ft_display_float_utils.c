/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_float_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:40:48 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 07:58:54 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putllint(unsigned long long int nb, t_format *format_parsed)
{
	if (nb >= 10)
		ft_putllint(nb / 10, format_parsed);
	ft_putchar((nb % 10) + '0', format_parsed);
}

int		ft_round_prec_0(unsigned long long int int_part, long double nb)
{
	if (int_part % 2 == 0)
	{
		if ((nb * 10) > 5)
			return (1);
	}
	else
	{
		if ((nb * 10) >= 5)
			return (1);
	}
	return (0);
}

int		ft_is_round(long double nb, t_format *format_parsed, int i, int pos)
{
	int					int_part;

	if (i == 0 && format_parsed->prec != 0)
		nb *= 10;
	int_part = (int)nb;
	nb = nb - int_part;
	if (i == 0 && format_parsed->prec == 0)
		return (ft_round_prec_0(int_part, nb));
	if (i == format_parsed->prec - pos)
	{
		if (int_part >= 5)
			return (1);
		else
			return (0);
	}
	if (int_part == 9)
	{
		if (!ft_is_round(nb * 10, format_parsed, i + 1, pos))
			return (0);
	}
	else
		return (0);
	return (1);
}

void	ft_display_width_float(t_format *format_parsed, int size_nb,
		int point, int neg)
{
	int		i;

	i = 0;
	if (format_parsed->width > format_parsed->prec + point + size_nb +
	neg + format_parsed->plus_flag +
	format_parsed->space_flag + format_parsed->exp)
	{
		while (i < format_parsed->width - (format_parsed->prec + point +
		size_nb + neg + format_parsed->plus_flag + format_parsed->space_flag
		+ format_parsed->exp))
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
}

void	ft_display_zero_float(t_format *format_parsed, int size_nb,
		int point, int neg)
{
	int		i;

	i = 0;
	if (format_parsed->width > format_parsed->prec + point + size_nb + neg
	+ format_parsed->plus_flag + format_parsed->space_flag +
	format_parsed->exp)
	{
		while (i < format_parsed->width - (format_parsed->prec + point +
		size_nb + neg + format_parsed->plus_flag + format_parsed->space_flag +
		format_parsed->exp))
		{
			ft_putchar('0', format_parsed);
			i++;
		}
	}
}
