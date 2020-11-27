/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:29:49 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 11:29:04 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_zero_flag(t_format *format_parsed, t_nb *nb, int size_nb)
{
	int		i;

	i = 0;
	ft_putprefix_nb(format_parsed);
	nb->ll = ft_check_minus_int(nb->ll, format_parsed);
	ft_putzero_x(format_parsed, nb);
	while (i < format_parsed->width
			- (size_nb + format_parsed->negative + format_parsed->plus_flag +
			format_parsed->space_flag + format_parsed->hashtag_flag))
	{
		ft_putchar('0', format_parsed);
		i++;
	}
	ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
}

void	ft_putnb_and_prefix(t_format *format_parsed, t_nb *nb, int size_nb)
{
	ft_putprefix_nb(format_parsed);
	ft_putzero_x(format_parsed, nb);
	ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
}

void	ft_display_int(t_format *format_parsed, t_nb *nb, int size_nb)
{
	int				i;

	if (format_parsed->prec != -1)
		ft_prec(format_parsed, nb, size_nb);
	else if (format_parsed->width != 0)
	{
		i = -1;
		if (format_parsed->zero_flag == 0)
		{
			while (++i < format_parsed->width -
				(size_nb + format_parsed->negative + format_parsed->plus_flag
				+ format_parsed->space_flag + format_parsed->hashtag_flag))
				ft_putchar(' ', format_parsed);
			ft_putnb_and_prefix(format_parsed, nb, size_nb);
		}
		else
			ft_putnbr_zero_flag(format_parsed, nb, size_nb);
	}
	else
		ft_putnb_and_prefix(format_parsed, nb, size_nb);
}

void	ft_display_int_minus_flag(t_format *format_parsed,
		t_nb *nb, int size_nb)
{
	int		i;

	ft_putprefix_nb(format_parsed);
	ft_putzero_x(format_parsed, nb);
	if (format_parsed->prec != -1)
		ft_prec_minus(format_parsed, nb, size_nb);
	else if (format_parsed->width != 0)
	{
		i = 0;
		ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
		while (i < format_parsed->width - (size_nb + format_parsed->negative +
			format_parsed->plus_flag + format_parsed->space_flag +
			format_parsed->hashtag_flag))
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
	else
		ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
}

t_nb	*ft_stocknb(va_list arg, t_format *format_parsed)
{
	t_nb	*nb;

	nb = ft_init_nb();
	if (format_parsed->type == 'd' || format_parsed->type == 'i')
	{
		if (format_parsed->l)
			nb->ll = (long long int)va_arg(arg, long int);
		else if (format_parsed->ll)
			nb->ll = (long long int)va_arg(arg, long long int);
		else
			nb->ll = (long long int)va_arg(arg, int);
	}
	else if (format_parsed->type == 'u' || format_parsed->type == 'x'
			|| format_parsed->type == 'X')
	{
		if (format_parsed->l)
			nb->ull = (unsigned long long int)va_arg(arg, unsigned long int);
		else if (format_parsed->ll)
			nb->ull = (unsigned long long int)va_arg(arg,
			unsigned long long int);
		else
			nb->ull = (unsigned long long int)va_arg(arg, unsigned int);
	}
	return (nb);
}
