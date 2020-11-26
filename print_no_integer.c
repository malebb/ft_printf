/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_no_integer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/26 17:11:17 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putstr_and_null(char *str, t_format *format_parsed)
{
	if (str)
	{
		if (format_parsed->prec != -1)
			ft_putstr_prec(str, format_parsed);
		else
			ft_putstr(str, format_parsed);
	}
	else
	{
		if (format_parsed->prec != -1)
			ft_putstr_prec("(null)", format_parsed);
		else
			ft_putstr("(null)", format_parsed);
	}
}

int		ft_size_to_print(t_format *format_parsed, char *str)
{
	int		size;

	if (format_parsed->prec == 0)
		size = 0;
	else if (!str && format_parsed->prec != -1 && format_parsed->prec < 6)
		size = format_parsed->prec;
	else if (!str)
		size = 6;
	else if (format_parsed->prec < ft_strlength(str) &&
			format_parsed->prec != -1)
		size = format_parsed->prec;
	else
		size = ft_strlength(str);
	return (size);
}

void	ft_display_string(t_format *format_parsed, va_list arg)
{
	char	*str;
	int		size;
	int		i;

	str = va_arg(arg, char *);
	size = ft_size_to_print(format_parsed, str);
	if (format_parsed->minus_flag == 1)
	{
		ft_putstr_and_null(str, format_parsed);
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
		ft_putstr_and_null(str, format_parsed);
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

void	ft_fill_number_read(va_list arg, int character_read,
		t_format *format_parsed)
{
	int			*i;
	long		*li;
	long long	*lli;

	if (format_parsed->l)
	{
		li = va_arg(arg, long int *);
		*li = character_read;
	}
	else if (format_parsed->ll)
	{
		lli = va_arg(arg, long long int *);
		*lli = character_read;
	}
	else
	{
		i = va_arg(arg, int *);
		*i = character_read;
	}
}
