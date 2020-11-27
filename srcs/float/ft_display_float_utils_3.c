/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_float_utils_3.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:49:07 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 11:28:23 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				ft_find_exp(long double nb)
{
	int							exp;
	unsigned long long int		int_part;

	exp = 0;
	int_part = (unsigned long long int)nb;
	if (nb == 0)
		exp = 0;
	else if (int_part > 0)
	{
		while (int_part >= 10)
		{
			int_part /= 10;
			exp++;
		}
	}
	else
	{
		while (int_part == 0)
		{
			nb = nb * 10;
			int_part = (unsigned long long int)nb;
			exp--;
		}
	}
	return (exp);
}

void			ft_put_e_value(t_format *format_parsed, int exp)
{
	ft_putchar('e', format_parsed);
	if (exp >= 0)
		ft_putchar('+', format_parsed);
	else
		ft_putchar('-', format_parsed);
	if (exp < 10 && exp > -10)
		ft_putnbr(0, format_parsed);
	if (exp < 0)
		ft_putnbr(-exp, format_parsed);
	else
		ft_putnbr(exp, format_parsed);
}

long double		ft_put_int_part_minus_exp(t_format *format_parsed, int point,
				int *exp, long double nb)
{
	unsigned long long int		int_part;

	int_part = (unsigned long long int)nb;
	while (int_part == 0)
	{
		nb *= 10;
		int_part = (unsigned long long int)nb;
	}
	nb = ft_put_integer_part(format_parsed, int_part, nb, exp);
	if (point)
		ft_putchar('.', format_parsed);
	return (nb);
}

long double		ft_put_int_part(t_format *format_parsed, int point,
				int *exp, long double nb)
{
	unsigned long long int		int_part;

	int_part = (unsigned long long int)nb;
	while (int_part > 10)
	{
		int_part /= 10;
		nb /= 10;
	}
	nb = ft_put_integer_part(format_parsed, int_part, nb, exp);
	if (point)
		ft_putchar('.', format_parsed);
	return (nb);
}

void			ft_putexp(long double nb, int point, t_format *format_parsed)
{
	unsigned long long int		int_part;
	int							exp;

	exp = ft_find_exp(nb);
	int_part = (unsigned long long int)nb;
	if (nb == 0)
	{
		ft_putnbr(0, format_parsed);
		if (point)
			ft_putchar('.', format_parsed);
	}
	else if (int_part > 0)
		nb = ft_put_int_part(format_parsed, point, &exp, nb);
	else
		nb = ft_put_int_part_minus_exp(format_parsed, point, &exp, nb);
	ft_putdigit(format_parsed, nb);
	ft_put_e_value(format_parsed, exp);
}
