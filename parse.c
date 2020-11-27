/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:00:49 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 08:00:59 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

void		ft_parse_flag(const char *format, int *i, int *j,
			t_format *data_format)
{
	while (format[*i] == '0' || format[*i] == '-'
	|| format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
	{
		if (format[*i] == '0')
			data_format->zero_flag = 1;
		else if (format[*i] == '-')
			data_format->minus_flag = 1;
		else if (format[*i] == '+')
			data_format->plus_flag = 1;
		else if (format[*i] == ' ')
			data_format->space_flag = 1;
		else if (format[*i] == '#')
			data_format->hashtag_flag = 2;
		*j = *j + 1;
		*i = *i + 1;
	}
}

int			ft_parse_width(const char *format, int *i, va_list arg,
			t_format *data_format)
{
	int		j;
	char	*size;

	j = 0;
	if (format[*i] == '*')
	{
		data_format->width = va_arg(arg, int);
		j++;
		*i = *i + 1;
	}
	else if (ft_isdigit(format[*i]))
	{
		*i += ft_extract_nb(format, &size, *i, &j);
		data_format->width = ft_atoi(size);
	}
	if (data_format->width < 0)
	{
		data_format->width *= -1;
		data_format->minus_flag = 1;
	}
	return (j);
}

int			ft_parse_precision(const char *format, int *i, va_list arg,
			t_format *format_parsed)
{
	int		j;
	char	*size;

	j = 0;
	if (format[*i] == '.')
	{
		*i = *i + 1;
		j++;
		if (format[*i] == '*')
		{
			format_parsed->prec = va_arg(arg, int);
			j++;
			*i = *i + 1;
		}
		else
		{
			*i += ft_extract_nb(format, &size, *i, &j);
			format_parsed->prec = ft_atoi(size);
		}
		if (format_parsed->prec < 0)
			format_parsed->prec = -1;
	}
	return (j);
}

int			ft_parse_size(const char *format, int *i, t_format *format_parsed)
{
	int		j;

	j = 0;
	if (format[*i] == 'l')
	{
		if (format[*i + 1] == 'l')
		{
			format_parsed->ll = 1;
			*i = *i + 2;
			j += 2;
		}
		else
		{
			format_parsed->l = 1;
			*i = *i + 1;
			j++;
		}
	}
	else if (format[*i] == 'h')
	{
		format_parsed->h = 0;
		*i = *i + 1;
		j++;
	}
	return (j);
}

t_format	*ft_parse_format(const char *format, int i, int *j, va_list arg)
{
	t_format	*format_parsed;

	format_parsed = ft_init_format();
	ft_parse_flag(format, &i, j, format_parsed);
	*j = *j + ft_parse_width(format, &i, arg, format_parsed);
	*j = *j + ft_parse_precision(format, &i, arg, format_parsed);
	*j = *j + ft_parse_size(format, &i, format_parsed);
	format_parsed->type = format[i];
	return (format_parsed);
}
