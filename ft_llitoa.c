/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 10:39:42 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/22 12:31:33 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_size_nbr(long long nb)
{
	int		size;

	size = 1;
	while (nb >= 10)
	{
		nb /= 10;
		size++;
	}
	return (size);
}

static void		ft_fill_nbr(char *nbr, long long nb, int *i)
{
	if (nb >= 10)
		ft_fill_nbr(nbr, nb / 10, i);
	nbr[*i] = (nb % 10) + '0';
	*i = *i + 1;
}

static void		ft_fill_sign_nbr(long long nb, char *nbr, int pos_or_neg,
				int size_nb)
{
	int		i;

	if (pos_or_neg)
	{
		nbr[0] = '-';
		nbr[size_nb + 1] = '\0';
		i = 1;
	}
	else
	{
		nbr[size_nb] = '\0';
		i = 0;
	}
	ft_fill_nbr(nbr, nb, &i);
}

char			*ft_llitoa(long long nb)
{
	char	*nbr;
	int		pos_or_neg;
	int		size_nb;

	pos_or_neg = 0;
	if (nb < 0)
	{
		pos_or_neg = 1;
		nb *= -1;
	}
	size_nb = ft_size_nbr(nb);
	if (!(nbr = malloc(sizeof(char) * (size_nb + pos_or_neg + 1))))
		return (0);
	ft_fill_sign_nbr(nb, nbr, pos_or_neg, size_nb);
	return (nbr);
}
