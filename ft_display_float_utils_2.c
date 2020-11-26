/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_float_utils_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 10:44:52 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/26 12:01:52 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

long double		ft_neg_float(t_format *format_parsed, long double nb, int *neg)
{
	*neg = 0;
	format_parsed->negative = 0;
	if (nb < 0)
	{
		format_parsed->plus_flag = 0;
		format_parsed->space_flag = 0;
		format_parsed->negative = 1;
		*neg = 1;
		nb *= -1;
	}
	return (nb);
}

int				ft_init_option(t_format *format_parsed)
{
	int		point;

	if (format_parsed->plus_flag)
		format_parsed->space_flag = 0;
	if (format_parsed->type == 'e')
		format_parsed->exp = 4;
	if (format_parsed->prec == -1)
		format_parsed->prec = 6;
	point = 0;
	if (format_parsed->prec != 0 || format_parsed->hashtag_flag == 2)
		point = 1;
	return (point);
}

void			ft_putexp_or_float(long double nb, int point,
				t_format *format_parsed)
{
	if (format_parsed->type == 'e')
		ft_putexp(nb, point, format_parsed);
	else
		ft_put_float(nb, point, format_parsed);
}

int				ft_sign_float(t_format *format_parsed, long double *nb)
{
	int		neg;

	if (*nb == 0)
		neg = ft_zero_float(format_parsed, *nb);
	else
		*nb = ft_neg_float(format_parsed, *nb, &neg);
	return (neg);
}

void			ft_putfloat_no_minus(t_format *format_parsed, int neg,
		int size_nb, int point)
{
	if (format_parsed->zero_flag != 0)
	{
		ft_putprefix(format_parsed, neg);
		ft_display_zero_float(format_parsed, size_nb, point, neg);
	}
	else
	{
		ft_display_width_float(format_parsed, size_nb, point, neg);
		ft_putprefix(format_parsed, neg);
	}
}
