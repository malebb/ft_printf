/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlebrun <mlebrun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 17:59:56 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/26 18:03:38 by mlebrun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

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
