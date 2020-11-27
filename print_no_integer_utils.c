/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_integer_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 18:02:59 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 08:02:54 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

void	ft_putchar_and_modulo(t_format *format_parsed, char c)
{
	int		i;

	i = 0;
	if (format_parsed->type == '%' && format_parsed->zero_flag == 1)
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
