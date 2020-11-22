/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/10/18 17:41:14 by Math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_prec_minus(t_format *format_parsed, long int nb, int size_nb)
{
	int			i;
	long int	nbr;
	
	i = 0;
	nbr = ft_check_minus_int(nb, format_parsed);
	while (i < format_parsed->prec - size_nb)
	{
		ft_putchar('0', format_parsed);
		i++;
	}
	ft_putnbr_dec_or_hexa(format_parsed, nbr, size_nb);
	if (format_parsed->width != 0)
	{
		i = 0;
		while (i < format_parsed->width - (size_nb + format_parsed->negative)
				&& i < format_parsed->width
				- (format_parsed->prec + format_parsed->negative))
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
}

void	ft_prec(t_format *format_parsed, long int nb, int size_nb)
{
	int			i;
	long int	nbr;

	if (format_parsed->width != 0)
	{
		if (nb < 0)
			nbr = nb * -1;
		else
			nbr = (long int)nb;
		i = -1;
		while (++i < format_parsed->width
			- (size_nb + (format_parsed->negative))
			&& i < format_parsed->width -
			(format_parsed->prec + format_parsed->negative))
			ft_putchar(' ', format_parsed);
		if (nb < 0)
			ft_putchar('-', format_parsed);
	}
	else
		nbr = ft_check_minus_int(nb, format_parsed);
	i = -1;
	while (++i < format_parsed->prec - size_nb)
		ft_putchar('0', format_parsed);
	ft_putnbr_dec_or_hexa(format_parsed, nbr, size_nb);
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