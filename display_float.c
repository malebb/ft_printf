/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 06:33:32 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/26 16:35:34 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putdigit(t_format *format_parsed, long double nb)
{
	int							i;
	int							pos;
	unsigned long long int		int_part;

	i = 0;
	pos = 1;
	while (i < format_parsed->prec)
	{
		nb *= 10;
		int_part = (unsigned long long int)nb;
		nb = nb - int_part;
		if (ft_is_round(nb, format_parsed, 0, pos))
		{
			if (int_part == 9)
				ft_putllint(0, format_parsed);
			else
				ft_putllint(int_part + 1, format_parsed);
		}
		else
			ft_putllint(int_part, format_parsed);
		i++;
		pos++;
	}
}

void	ft_put_float(long double nb, int point, t_format *format_parsed)
{
	unsigned long long int		int_part;

	int_part = (unsigned long long int)nb;
	if (format_parsed->prec != 0)
		nb = nb - int_part;
	if (ft_is_round(nb, format_parsed, 0, 0))
		ft_putllint(int_part + 1, format_parsed);
	else
		ft_putllint(int_part, format_parsed);
	if (format_parsed->prec == 0)
		nb = nb - int_part;
	if (point)
		ft_putchar('.', format_parsed);
	ft_putdigit(format_parsed, nb);
}

void	ft_putprefix(t_format *format_parsed, int neg)
{
	if (format_parsed->space_flag)
		ft_putchar(' ', format_parsed);
	if (format_parsed->plus_flag)
		ft_putchar('+', format_parsed);
	if (neg)
		ft_putchar('-', format_parsed);
}

int		ft_zero_float(t_format *format_parsed, long double nb)
{
	int		neg;

	if (1 / nb <= 0)
	{
		format_parsed->plus_flag = 0;
		format_parsed->space_flag = 0;
		neg = 1;
		format_parsed->negative = 1;
	}
	else
	{
		neg = 0;
		format_parsed->negative = 0;
	}
	return (neg);
}

void	ft_display_float(t_format *format_parsed, va_list arg)
{
	long double					nb;
	int							point;
	int							size_nb;
	int							neg;

	nb = (long double)va_arg(arg, double);
	neg = ft_sign_float(format_parsed, &nb);
	point = ft_init_option(format_parsed);
	size_nb = ft_size_llnb((long int)nb);
	if (format_parsed->minus_flag == 1)
	{
		ft_putprefix(format_parsed, neg);
		ft_putexp_or_float(nb, point, format_parsed);
		ft_display_width_float(format_parsed, size_nb, point, neg);
	}
	else
	{
		ft_putfloat_no_minus(format_parsed, neg, size_nb, point);
		ft_putexp_or_float(nb, point, format_parsed);
	}
}
