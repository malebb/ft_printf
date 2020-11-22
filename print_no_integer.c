/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/10/19 15:23:10 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void 	ft_display_null(t_format *format_parsed)
{
	char	null[7];
	int		i;
	
	null[0] = '(';
	null[1] = 'n';
	null[2] = 'u';
	null[3] = 'l';
	null[4] = 'l';
	null[5] = ')';
	null[6] = '\0';
	i = 0;
	if (format_parsed->prec != -1)
	{
		while (null[i] != '\0' && i < format_parsed->prec)
		{
			ft_putchar(null[i], format_parsed);
			i++;
		}
	}
	else
		ft_putstr(null, format_parsed);
	
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
	{
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
}

void	ft_display_string(t_format *format_parsed, va_list arg)
{
	char	*str;
	int		size;
	int		i;

	str = va_arg(arg, char *);
	if (format_parsed->prec == 0)
		size = 0;
	else if (!str)
		size = 6;
	else if (format_parsed->prec < ft_strlength(str) && format_parsed->prec != -1)
		size = format_parsed->prec;
	else
		size = ft_strlength(str);
	if (format_parsed->minus_flag == 1)
	{
		if (str)
		{
			if (format_parsed->prec != -1)
				ft_putstr_prec(str, format_parsed);
			else
				ft_putstr(str, format_parsed);	
		}
		else
			ft_display_null(format_parsed);
		i = 0;
		while (i < format_parsed->width - size)
		{
			ft_putchar(' ', format_parsed);
			i++;
		}
	}
	else
	{
		i = -1;
		while (++i < format_parsed->width - size)
			ft_putchar(' ', format_parsed);
		if (str)
		{
			if (format_parsed->prec != -1){
				ft_putstr_prec(str, format_parsed);}
			else
				ft_putstr(str, format_parsed);
		}
		else
			ft_display_null(format_parsed);
	}
}

void	ft_display_addr(t_format *format_parsed, va_list arg)
{
	long int		addr;
	int				i;
	int				size;

	addr = (long int)va_arg(arg, long int);
	size = ft_size_hexa(addr);
	if (format_parsed->minus_flag == 1)
	{
		ft_putstr("0x", format_parsed);
		ft_putnbr_hexa_lower(addr, format_parsed);
		i = -1;
		while (++i < format_parsed->width - (size + 2))
			ft_putchar(' ', format_parsed);
	}
	else
	{
		i = -1;
		while (++i < format_parsed->width - (size + 2))
			ft_putchar(' ', format_parsed);
		ft_putstr("0x", format_parsed);
		ft_putnbr_hexa_lower(addr, format_parsed);
	}
}
