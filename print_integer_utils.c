/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_integer_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:26:31 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/26 16:34:02 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

t_nb		*ft_init_nb(void)
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

void		ft_putnbr_dec_or_hexa(t_format *format_parsed, t_nb *nb, int size_nb)
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

void		ft_putprefix_nb(t_format *format_parsed)
{
	if (format_parsed->plus_flag)
		ft_putchar('+', format_parsed);
	if (format_parsed->space_flag == 1)
		ft_putchar(' ', format_parsed);
}

void		ft_putzero_x(t_format *format_parsed, t_nb *nb)
{
	if (format_parsed->hashtag_flag == 2 &&
		format_parsed->type == 'x' && nb->ull != 0)
		ft_putstr("0x", format_parsed);
	if (format_parsed->hashtag_flag == 2 &&
		format_parsed->type == 'X' && nb->ull != 0)
		ft_putstr("0X", format_parsed);
}
