/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_integer_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:02:59 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 10:53:11 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putchar_and_modulo(t_format *format_parsed, char c)
{
	int		i;

	i = 0;
	if ((format_parsed->type == '%' && format_parsed->zero_flag == 1) ||
	(format_parsed->type == 'c' && format_parsed->zero_flag == 1))
	{
		while (i < format_parsed->width - 1)
		{
			ft_putchar('0', format_parsed);
			i++;
		}
		ft_putchar(c, format_parsed);
	}
	else
	{
		while (i < format_parsed->width - 1)
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
		ft_putchar(c, format_parsed);
	}
}

void	ft_display_char(t_format *format_parsed, va_list arg)
{
	char	c;
	int		i;

	if (format_parsed->type == 'c')
		c = va_arg(arg, int);
	else
		c = '%';
	if (format_parsed->minus_flag == 1)
	{
		ft_putchar(c, format_parsed);
		i = 0;
		while (i < format_parsed->width - 1)
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
	else
		ft_putchar_and_modulo(format_parsed, c);
}

void	ft_putaddr_width(int size, t_format *format_parsed)
{
	int		i;

	i = -1;
	if (size + 2 > format_parsed->prec)
	{
		while (++i < format_parsed->width - (size + 2))
			ft_putchar(' ', format_parsed);
	}
	else
	{
		while (++i < format_parsed->width - (format_parsed->prec + 2))
			ft_putchar(' ', format_parsed);
	}
}

void	ft_display_addr_minus_flag(t_format *format_parsed, long int addr,
		int size)
{
	int		i;

	ft_putstr("0x", format_parsed);
	i = 0;
	if (format_parsed->prec != -1)
	{
		while (i < format_parsed->prec - size)
		{
			ft_putchar('0', format_parsed);
			i++;
		}
	}
	if (!(format_parsed->prec == 0 && !addr))
		ft_putnbr_hexa_lower(addr, format_parsed);
	ft_putaddr_width(size, format_parsed);
}

void	ft_display_prec_and_zero(t_format *format_parsed, int size)
{
	int		i;

	if (format_parsed->prec != -1)
	{
		i = 0;
		while (i < format_parsed->prec - size)
		{
			ft_putchar('0', format_parsed);
			i++;
		}
	}
	else if (format_parsed->zero_flag != 0)
	{
		i = -1;
		if (size + 2 > format_parsed->prec)
		{
			while (++i < format_parsed->width - (size + 2))
				ft_putchar('0', format_parsed);
		}
		else
		{
			while (++i < format_parsed->width - format_parsed->prec)
				ft_putchar('0', format_parsed);
		}
	}
}
