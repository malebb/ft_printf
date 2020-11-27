/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:00:04 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 08:00:15 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

t_format	*ft_init_format(void)
{
	t_format	*elem;

	if (!(elem = malloc(sizeof(t_format) * 1)))
		return (0);
	elem->zero_flag = 0;
	elem->minus_flag = 0;
	elem->plus_flag = 0;
	elem->space_flag = 0;
	elem->hashtag_flag = 0;
	elem->width = 0;
	elem->type = '0';
	elem->prec = -1;
	elem->negative = 0;
	elem->c_read = 0;
	elem->l = 0;
	elem->ll = 0;
	elem->h = 0;
	elem->exp = 0;
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
	else if (format_parsed->type == 'f' || format_parsed->type == 'e')
		ft_display_float(format_parsed, arg);
}

t_format	*ft_parse_and_print(int *i, const char *format,
			int *j, va_list arg)
{
	t_format		*format_parsed;

	*i = *i + 1;
	format_parsed = ft_parse_format(format, *i, j, arg);
	ft_display_by_type(format_parsed, arg);
	*i += *j;
	return (format_parsed);
}

void		ft_count_char(int *character_read, t_format *format_parsed)
{
	*character_read = *character_read + format_parsed->c_read;
	format_parsed->c_read = 0;
}

int			ft_valid_and_n_flag(t_format *format_parsed, va_list arg,
			int character_read)
{
	if (format_parsed->type == 'n')
		ft_fill_number_read(arg, character_read, format_parsed);
	if (format_parsed->type != 'n' && format_parsed->type != 'd' &&
		format_parsed->type != 'u' && format_parsed->type != 'f' &&
		format_parsed->type != 's' && format_parsed->type != 'x' &&
		format_parsed->type != 'X' && format_parsed->type != 'c' &&
		format_parsed->type != 'p' && format_parsed->type != 'e' &&
		format_parsed->type != '%' && format_parsed->type != 'i')
			return (0);
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	int			j;
	t_format	*format_parsed;
	int			character_read;

	va_start(arg, format);
	i = -1;
	character_read = 0;
	format_parsed = ft_init_format();
	while (format[++i] != '\0')
	{
		j = 0;
		if (format[i] == '%')
		{
			format_parsed = ft_parse_and_print(&i, format, &j, arg);
			if (!ft_valid_and_n_flag(format_parsed, arg, character_read))
				break ;
		}
		else
			ft_putchar(format[i], format_parsed);
		ft_count_char(&character_read, format_parsed);
	}
	va_end(arg);
	return (character_read);
}
