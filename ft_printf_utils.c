/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 07:52:54 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 08:00:27 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"

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
