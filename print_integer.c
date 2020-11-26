/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/25 16:04:33 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_nb	*ft_init_nb()
{
	t_nb	*elem;

	if (!(elem = malloc(sizeof(t_nb) * (1))))
		return (0);
	elem->ll = 0;
	elem->ull = 0;
	return (elem);
}

long int	ft_check_minus_int(long long int nb, t_format *format_parsed)
{
	if (nb < 0)
	{
		ft_putchar('-', format_parsed);
		nb *= -1;
	}
	return (nb);
}

void	ft_putnbr_dec_or_hexa(t_format *format_parsed, t_nb *nb, int size_nb)
{
	if (format_parsed->prec == 0 && size_nb == 0)
		return ;
	else if (format_parsed->type == 'x')
		ft_putnbr_hexa_lower(nb->ull, format_parsed);
	else if (format_parsed->type == 'X')
		ft_putnbr_hexa_upper(nb->ull, format_parsed);
	else
	{
		if (format_parsed->type == 'u')
			ft_putnbr_ull(nb->ull, format_parsed);
		else
			ft_putnbr(nb->ll, format_parsed);
	}
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
			while (++i < format_parsed->width - (size_nb + format_parsed->negative + format_parsed->plus_flag + format_parsed->space_flag + format_parsed->hashtag_flag))
				ft_putchar(' ', format_parsed);
			if (format_parsed->plus_flag)
				ft_putchar('+', format_parsed);
			if (format_parsed->space_flag == 1)
				ft_putchar(' ', format_parsed);

		if (format_parsed->hashtag_flag == 2 && format_parsed->type == 'x' && nb->ull != 0)
			ft_putstr("0x", format_parsed);
		if (format_parsed->hashtag_flag == 2 && format_parsed->type == 'X' && nb->ull != 0)
			ft_putstr("0X", format_parsed);

			ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
		}
		else
		{
			if (format_parsed->plus_flag)
				ft_putchar('+', format_parsed);
			if (format_parsed->space_flag == 1)
				ft_putchar(' ', format_parsed);
			nb->ll = ft_check_minus_int(nb->ll, format_parsed);

		if (format_parsed->hashtag_flag == 2 && format_parsed->type == 'x' && nb->ull != 0)
			ft_putstr("0x", format_parsed);
		if (format_parsed->hashtag_flag == 2 && format_parsed->type == 'X' && nb->ull != 0)
			ft_putstr("0X", format_parsed);

			while (++i < format_parsed->width
			- (size_nb + format_parsed->negative + format_parsed->plus_flag + format_parsed->space_flag + format_parsed->hashtag_flag))
				ft_putchar('0', format_parsed);
			ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
		}
	}
	else
	{
		if (format_parsed->plus_flag)
			ft_putchar('+', format_parsed);
		if (format_parsed->space_flag == 1)
			ft_putchar(' ', format_parsed);

		if (format_parsed->hashtag_flag == 2 && format_parsed->type == 'x' && nb->ull != 0)
			ft_putstr("0x", format_parsed);
		if (format_parsed->hashtag_flag == 2 && format_parsed->type == 'X' && nb->ull != 0)
			ft_putstr("0X", format_parsed);

		ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
	}
}

void	ft_display_int_minus_flag(t_format *format_parsed,
		t_nb *nb, int size_nb)
{
	int		i;

	if (format_parsed->plus_flag)
		ft_putchar('+', format_parsed);
	if (format_parsed->space_flag == 1)
		ft_putchar(' ', format_parsed);
	if (format_parsed->hashtag_flag == 2 && format_parsed->type == 'x' && nb->ull != 0)
		ft_putstr("0x", format_parsed);
	if (format_parsed->hashtag_flag == 2 && format_parsed->type == 'X' && nb->ull != 0)
		ft_putstr("0X", format_parsed);
	if (format_parsed->prec != -1)
		ft_prec_minus(format_parsed, nb, size_nb);
	else if (format_parsed->width != 0)
	{
		i = 0;
		ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
		while (i < format_parsed->width - (size_nb + format_parsed->negative + format_parsed->plus_flag + format_parsed->space_flag + format_parsed->hashtag_flag))
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
	int							size_nb;
	t_nb						*nb;

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
	else if (format_parsed->type == 'u' || format_parsed->type == 'x' || format_parsed->type == 'X')
	{
		if (format_parsed->l)
			nb->ull = (unsigned long long int)va_arg(arg, unsigned long int);
		else if (format_parsed->ll)
			nb->ull = (unsigned long long int)va_arg(arg, unsigned long long int);
		else
			nb->ull =(unsigned long long int)va_arg(arg, unsigned int);
	}
	if (format_parsed->type == 'u' || format_parsed->type == 'x' || format_parsed->type == 'X')
	{
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
	else
	{
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
			ft_display_int(format_parsed, nb, size_nb);
	}
}
