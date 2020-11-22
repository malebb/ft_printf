/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/10/19 14:46:13 by Math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_format	*ft_init_format()
{
	t_format	*elem;

	if (!(elem = malloc(sizeof(t_format) * 1)))
		return (0);
	elem->zero_flag = 0;
	elem->width = 0;
	elem->type = '0';
	elem->prec = -1;
	elem->negative = 0;
	elem->c_read = 0;
	return (elem);
}

void		ft_display_by_type(t_format *format_parsed, va_list arg)
{
	if (format_parsed->type == 'd' || format_parsed->type == 'i'
		|| format_parsed->type == 'u' || format_parsed->type == 'x'
		|| format_parsed->type == 'X')
		ft_display_integer(format_parsed, arg);
	else if (format_parsed->type == 'c' || format_parsed->type == '%')
		ft_display_char(format_parsed, arg);
	else if (format_parsed->type == 's')
		ft_display_string(format_parsed, arg);
	else if (format_parsed->type == 'p')
		ft_display_addr(format_parsed, arg);
}

int			ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	int			j;
	t_format	*format_parsed;
	int			character_read;

	va_start(arg, format);
	i = 0;
	character_read = 0;
	format_parsed = ft_init_format();
	while (format[i] != '\0')
	{
		j = 0;
		if (format[i] == '%')
		{
			i++;
			format_parsed = ft_parse_format(format, i, &j, arg);
			ft_display_by_type(format_parsed, arg);
			i += j;
		}
		else
			ft_putchar(format[i], format_parsed);
		i++;
		character_read += format_parsed->c_read;
		format_parsed->c_read = 0;
	}
	va_end(arg);
	return (character_read);
}
