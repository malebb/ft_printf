/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/10/19 14:47:25 by Math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_extract_nb(const char *format, char **size, int i, int *j)
{
	int		size_nb_0;
	int		k;

	size_nb_0 = 0;
	while (ft_isdigit(format[i + size_nb_0]) && format[i + size_nb_0] != '\0')
		size_nb_0++;
	if (!(*size = malloc(sizeof(char) * (size_nb_0 + 1))))
		return (0);
	k = 0;
	while (k < size_nb_0)
	{
		size[0][k] = format[k + i];
		k++;
	}
	size[0][k] = '\0';
	*j = *j + k;
	return (k);
}

void		ft_parse_flag(const char *format, int *i, int *j,
			t_format *data_format)
{
	while (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '0')
			data_format->zero_flag = 1;
		else if(format[*i] == '-')
			data_format->minus_flag = 1;
		*j = *j + 1;
		*i = *i + 1;	
	}/*
	if (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '0')
			data_format->zero_flag = 1;
		else
			data_format->minus_flag = 1;
		*j = *j + 1;
		*i = *i + 1;
	}
	if (format[*i] == '0' || format[*i] == '-')
	{
		if (format[*i] == '0')
			data_format->zero_flag = 1;
		else
			data_format->minus_flag = 1;
		*j = *j + 1;
		*i = *i + 1;
	}*/
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

int			ft_parse_precision(const char *format, int *i, va_list arg, t_format *data_format)
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
			data_format->prec = va_arg(arg, int);
			j++;
			*i = *i + 1;
		}
		else
		{
			*i += ft_extract_nb(format, &size, *i, &j);
			data_format->prec = ft_atoi(size);
		}
		if (data_format->prec < 0)
			data_format->prec = -1;
	}
	return (j);
}

t_format	*ft_parse_format(const char *format, int i, int *j, va_list arg)
{
	t_format	*data_format;

	data_format = ft_init_format();
	ft_parse_flag(format, &i, j, data_format);
	*j = *j + ft_parse_width(format, &i, arg, data_format);
	*j = *j + ft_parse_precision(format, &i, arg, data_format);
	data_format->type = format[i];
	return (data_format);
}
