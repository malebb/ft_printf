/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 07:57:43 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 11:30:42 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putnbr_ull(unsigned long long int nb, t_format *format_parsed)
{
	if (nb >= 10)
		ft_putnbr(nb / 10, format_parsed);
	ft_putchar((nb % 10) + '0', format_parsed);
}

void	ft_putchar(char c, t_format *format_parsed)
{
	write(1, &c, 1);
	format_parsed->c_read = format_parsed->c_read + 1;
}

void	ft_putstr(char *str, t_format *format_parsed)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i], format_parsed);
		i++;
	}
}

void	ft_putnbr_hexa_lower(unsigned long long int nb, t_format *format_parsed)
{
	char	hexa[16];
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		hexa[i] = '0' + i;
		i++;
	}
	j = 0;
	while (j < 6)
	{
		hexa[i] = 'a' + j;
		j++;
		i++;
	}
	hexa[i] = '\0';
	if (nb >= 16)
	{
		ft_putnbr_hexa_lower(nb / 16, format_parsed);
		ft_putchar(hexa[nb % 16], format_parsed);
	}
	else
		ft_putchar(hexa[nb % 16], format_parsed);
}

void	ft_putnbr_hexa_upper(unsigned long long int nb, t_format *format_parsed)
{
	char	hexa[16];
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		hexa[i] = '0' + i;
		i++;
	}
	j = 0;
	while (j < 6)
	{
		hexa[i] = 'A' + j;
		j++;
		i++;
	}
	hexa[i] = '\0';
	if (nb >= 16)
	{
		ft_putnbr_hexa_upper(nb / 16, format_parsed);
		ft_putchar(hexa[nb % 16], format_parsed);
	}
	else
		ft_putchar(hexa[nb % 16], format_parsed);
}
