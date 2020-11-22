/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:47:47 by mlebrun           #+#    #+#             */
/*   Updated: 2020/10/18 17:38:55 by Math             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_format
{
	int			zero_flag;
	int			minus_flag;
	int			width;
	int			prec;
	char		type;
	int			negative;
	int			c_read;
}					t_format;

int			ft_printf(const char *, ...);
void		ft_display_by_type(t_format *format_parsed, va_list arg);
void		ft_display_addr(t_format *format_parsed, va_list arg);
void		ft_putnbr_hexa_upper(long int nb, t_format *format_parsed);
void		ft_putnbr_hexa_lower(long int nb, t_format *format_parsed);
void		ft_putnbr_dec_or_hexa(t_format *format_parsed, long int nb, int size_nb);
void		ft_putstr(char *str, t_format *format_parsed);
void		ft_display_string(t_format *format_parsed, va_list arg);
int			ft_strlength(char *str);
void		ft_display_char(t_format *format_parsed, va_list arg);
void		ft_display_integer(t_format *format_parsed, va_list arg);
void		ft_display_int_minus_flag(t_format *format_parsed, long int nb, int size_nb);
void		ft_display_int(t_format *format_parsed, long int nb, int size_nb);
int			ft_size_hexa_dec(t_format *format_parsed, long int nb);
void		ft_prec(t_format *format_parsed, long int nb, int size_nb);
void		ft_prec_minus(t_format *format_parsed, long int nb, int size_nb);
long int	ft_check_minus_int(long int nb, t_format *format_parsed);
void		ft_putchar(char c, t_format *format_parsed);
t_format	*ft_parse_format(const char *format, int i, int *j, va_list arg);
int			ft_parse_precision(const char *format, int *i, va_list arg, t_format *data_format);
int			ft_parse_width(const char *format, int *i, va_list arg, t_format *data_format);
void		ft_parse_flag(const char *format, int *i, int *j, t_format *data_format);
int			ft_extract_nb(const char *format, char **size, int i, int *j);
int			ft_size_nb(long int nbr);
int			ft_size_hexa(long int nb);
t_format	*ft_init_format();
void		ft_putnbr(long int nb, t_format *format_parsed);
void	ft_putstr_prec(char *str, t_format *format_parsed);
#endif
