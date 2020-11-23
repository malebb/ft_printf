/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 06:33:32 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/23 16:06:45 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putllint(unsigned long long int nb, t_format *format_parsed)
{
	if (nb >= 10)
		ft_putllint(nb / 10, format_parsed);
	ft_putchar((nb % 10) + '0', format_parsed);
}

int		ft_is_round(double nb, t_format * format_parsed, int i, int pos)
{
	int					int_part;

	if (i == 0)
		nb *= 10;
	int_part = (int)nb;
	nb = nb - int_part;
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
		return(0);
	return (1);
}

void	ft_put_float(double nb, int point, t_format *format_parsed)
{
	unsigned long long int		int_part;
	int							i;
	int							pos;

	int_part = (unsigned long long int)nb;
	nb = nb - int_part;
	if (ft_is_round(nb, format_parsed, 0, 0))
		ft_putllint(int_part + 1, format_parsed);
	else
		ft_putllint(int_part, format_parsed);
	if (point)
		ft_putchar('.', format_parsed);
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

void	ft_display_width_float(t_format *format_parsed, int size_nb, int point, int neg)
{
	int		i;

	i = 0;
	if (format_parsed->width > format_parsed->prec + point + size_nb + neg)
	{
		while (i < format_parsed->width - (format_parsed->prec + point + size_nb + neg))
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
}

void	ft_display_zero_float(t_format *format_parsed, int size_nb, int point, int neg)
{
	int		i;

	i = 0;
	if (format_parsed->width > format_parsed->prec + point + size_nb + neg)
	{
		while (i < format_parsed->width - (format_parsed->prec + point + size_nb + neg))
		{
			ft_putchar('0', format_parsed);
			i++;
		}
	}
}

void	ft_display_float(t_format *format_parsed, va_list arg)
{
	double						nb;
	int							i;
	int							point;
	int							size_nb;
	int							neg;

	nb = va_arg(arg, double);
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb *= -1;
	}
	if (format_parsed->prec == -1)
		format_parsed->prec = 6;
	i = 0;
	point = 0;
	if (format_parsed->prec != 0)
		point = 1;
	size_nb = ft_size_llnb((long int)nb);
	if (format_parsed->minus_flag == 1)
	{
		if (neg)
			ft_putchar('-', format_parsed);
		ft_put_float(nb, point, format_parsed);
		ft_display_width_float(format_parsed, size_nb, point, neg);
	}
	else
	{
		if (format_parsed->zero_flag != 0)
		{
			if (neg)
				ft_putchar('-', format_parsed);
			ft_display_zero_float(format_parsed, size_nb, point, neg);
		}
		else
		{
			ft_display_width_float(format_parsed, size_nb, point, neg);
			if (neg)
				ft_putchar('-', format_parsed);
		}
		ft_put_float(nb, point, format_parsed);
	}
}
