/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_float_utils_4.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:39:37 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 11:28:30 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

long double		ft_put_integer_part(t_format *format_parsed,
				unsigned long long int int_part, long double nb, int *exp)
{
	if (format_parsed->prec != 0)
		nb = nb - int_part;
	if (ft_is_round(nb, format_parsed, 0, 0))
	{
		if (int_part + 1 == 10)
		{
			int_part = 0;
			*exp = *exp + 1;
		}
		ft_putllint(int_part + 1, format_parsed);
	}
	else
	{
		if (int_part == 10)
		{
			int_part = 1;
			nb /= 10;
		}
		ft_putllint(int_part, format_parsed);
	}
	if (format_parsed->prec == 0)
		nb = nb - int_part;
	return (nb);
}

int				ft_size_llnb(unsigned long long int nb)
{
	int			size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}
