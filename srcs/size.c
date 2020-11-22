/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 11:30:34 by mlebrun           #+#    #+#             */
/*   Updated: 2020/10/18 18:01:49 by Math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_size_hexa(long int nb)
{
	int		size;

	size = 1;
	while (nb >= 16)
	{
		size++;
		nb /= 16;
	}
	return (size);
}

int		ft_size_nb(long int nbr)
{
	int			size;
	long int	nb;

	nb = (long int)nbr;
	if (nb < 0)
		nb *= -1;
	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

int		ft_size_hexa_dec(t_format *format_parsed, long int nb)
{
	int		size_nb;

	if (format_parsed->type == 'x' || format_parsed->type == 'X')
		size_nb = ft_size_hexa(nb);
	else
		size_nb = ft_size_nb(nb);
	return (size_nb);
}

int		ft_strlength(char *str)
{
	int		size;

	size = 0;
	while (str[size] != '\0')
		size++;
	return (size);
}
