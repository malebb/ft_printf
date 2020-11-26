/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/26 16:09:56 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_print_space_prec(t_format *format_parsed, int size_nb, t_nb *nb)
{
	int		i;

	i = 0;
	if (format_parsed->prec > size_nb)
	{
		while (i < format_parsed->width - (format_parsed->prec + format_parsed->negative + format_parsed->plus_flag + format_parsed->space_flag + format_parsed->hashtag_flag))
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
	else
	{
		while (i < format_parsed->width - (size_nb + format_parsed->negative + format_parsed->plus_flag + format_parsed->space_flag + format_parsed->hashtag_flag))
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
	nb->ll = ft_check_minus_int(nb->ll, format_parsed);
}

void	ft_prec_minus(t_format *format_parsed, t_nb *nb, int size_nb)
{
	int				i;
	
	i = 0;
	nb->ll = ft_check_minus_int(nb->ll, format_parsed);
	while (i < format_parsed->prec - size_nb)
	{
		ft_putchar('0', format_parsed);
		i++;
	}
	ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
	if (format_parsed->width != 0)
	{
		ft_print_space_prec(format_parsed, size_nb, nb);
		/*
		i = 0;
		if (format_parsed->prec > size_nb)
		{
			while (i < format_parsed->width - (format_parsed->prec + format_parsed->negative + format_parsed->plus_flag + format_parsed->space_flag + format_parsed->hashtag_flag))
			{
				ft_putchar(' ', format_parsed);
				i++;
			}
		}
		else
		{
			while (i < format_parsed->width - (size_nb + format_parsed->negative + format_parsed->plus_flag + format_parsed->space_flag + format_parsed->hashtag_flag))
			{
				ft_putchar(' ', format_parsed);
				i++;
			}
		}*/
	}
}

void	ft_prec(t_format *format_parsed, t_nb *nb, int size_nb)
{
	int				i;

	if (format_parsed->width != 0)
		ft_print_space_prec(format_parsed, size_nb, nb);
	else
		nb->ll = ft_check_minus_int(nb->ll, format_parsed);
	ft_putprefix_nb(format_parsed, nb);
	ft_putzero_x(format_parsed);
	i = -1;
	while (++i < format_parsed->prec - size_nb)
	{
		ft_putchar('0', format_parsed);
	}
	ft_putnbr_dec_or_hexa(format_parsed, nb, size_nb);
}

void	ft_putstr_prec(char *str, t_format *format_parsed)
{
	int		i;

	i = 0;
	while (str[i] != '\0' && i < format_parsed->prec)
	{
		ft_putchar(str[i], format_parsed);
		i++;
	}
}
