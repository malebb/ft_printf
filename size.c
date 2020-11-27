/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/27 08:03:10 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/27 08:03:16 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int		ft_size_hexa(unsigned long long int nb)
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

int		ft_size_nb(long long int nb)
{
	int			size;

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

int		ft_size_nb_ull(unsigned long long int nb)
{
	int			size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

int		ft_size_hexa_dec(t_format *format_parsed, t_nb *nb)
{
	int		size_nb;

	if (format_parsed->type == 'x' || format_parsed->type == 'X')
		size_nb = ft_size_hexa(nb->ull);
	else if (format_parsed->type == 'u')
		size_nb = ft_size_nb_ull(nb->ull);
	else
		size_nb = ft_size_nb(nb->ll);
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
