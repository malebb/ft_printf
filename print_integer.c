/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/10/19 14:26:24 by Math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

long int	ft_check_minus_int(long int nb, t_format *format_parsed)
{
	long int	nbr;

	if (nb < 0)
	{
		ft_putchar('-', format_parsed);
		nbr = nb *= -1;
	}
	else
		nbr = nb;
	return (nbr);
}

void	ft_putnbr_dec_or_hexa(t_format *format_parsed, long int nb, int size_nb)
{
	if (format_parsed->prec == 0 && size_nb == 0)
		return ;
	else if (format_parsed->type == 'x')
		ft_putnbr_hexa_lower(nb, format_parsed);
	else if (format_parsed->type == 'X')
		ft_putnbr_hexa_upper(nb, format_parsed);
	else
		ft_putnbr(nb, format_parsed);
}

void	ft_display_int(t_format *format_parsed, long int nb, int size_nb)
{
	int			i;
	long int	nbr;

	if (format_parsed->prec != -1)
		ft_prec(format_parsed, nb, size_nb);
	else if (format_parsed->width != 0)
	{
		i = -1;
		if (format_parsed->zero_flag == 0)
		{
			while (++i < format_parsed->width
				- (size_nb + format_parsed->negative))
				ft_putchar(' ', format_parsed);
			ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
		}
		else
		{
			nbr = ft_check_minus_int(nb, format_parsed);
			while (++i < format_parsed->width
			- (size_nb + format_parsed->negative))
				ft_putchar('0', format_parsed);
			ft_putnbr_dec_or_hexa(format_parsed, nbr, size_nb);
		}
	}
	else
		ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
}

void	ft_display_int_minus_flag(t_format *format_parsed,
		long int nb, int size_nb)
{
	int		i;
	if (format_parsed->prec != -1)
		ft_prec_minus(format_parsed, nb, size_nb);
	else if (format_parsed->width != 0)
	{
		i = 0;
		ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
		while (i < format_parsed->width - (size_nb + format_parsed->negative))
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
	else
		ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
}

void	ft_display_integer(t_format *format_parsed, va_list arg)
{
	long int	nb;
	int			size_nb;

	if (format_parsed->type == 'd' || format_parsed->type == 'i')
		nb = (long int)va_arg(arg, int);
	else if (format_parsed->type == 'u' || format_parsed->type == 'x' || format_parsed->type == 'X')
		nb = (long int)va_arg(arg, unsigned int);
	else
		nb = 0;
	
	size_nb = ft_size_hexa_dec(format_parsed, nb);
	if (nb == 0 && format_parsed->prec == 0)
				size_nb = 0;
	if (nb < 0)
		format_parsed->negative = 1;
	if (format_parsed->minus_flag == 1)
		ft_display_int_minus_flag(format_parsed, nb, size_nb);
	else
		ft_display_int(format_parsed, nb, size_nb);
}
