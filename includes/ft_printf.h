/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Math <Math@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 14:47:47 by mlebrun           #+#    #+#             */
/*   Updated: 2020/11/26 18:08:22 by mlebrun          ###   ########.fr       */
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
	int				zero_flag;
	int				minus_flag;
	int				plus_flag;
	int				space_flag;
	int				hashtag_flag;
	int				width;
	int				prec;
	char			type;
	int				negative;
	int				c_read;
	int				l;
	int				ll;
	int				h;
	int				exp;
}					t_format;

typedef struct		s_nb
{
	long long				ll;
	unsigned long long		ull;
}					t_nb;

int					ft_printf(const char *format, ...);
void				ft_display_by_type(t_format *format_parsed, va_list arg);
void				ft_display_addr(t_format *format_parsed, va_list arg);
void				ft_putnbr_hexa_upper(unsigned long long int nb,
					t_format *format_parsed);
void				ft_putnbr_hexa_lower(unsigned long long int nb,
					t_format *format_parsed);
void				ft_putnbr_dec_or_hexa(t_format *format_parsed,
					t_nb *nb, int size_nb);
void				ft_putstr(char *str, t_format *format_parsed);
void				ft_display_string(t_format *format_parsed, va_list arg);
int					ft_strlength(char *str);
void				ft_display_char(t_format *format_parsed, va_list arg);
void				ft_display_integer(t_format *format_parsed, va_list arg);
void				ft_display_int_minus_flag(t_format *format_parsed,
					t_nb *nb, int size_nb);
void				ft_display_int(t_format *format_parsed, t_nb *nb,
					int size_nb);
int					ft_size_hexa_dec(t_format *format_parsed, t_nb *nb);
void				ft_prec(t_format *format_parsed, t_nb *nb, int size_nb);
void				ft_prec_minus(t_format *format_parsed, t_nb *nb,
					int size_nb);
long int			ft_check_minus_int(long long int nb,
					t_format *format_parsed);
void				ft_putchar(char c, t_format *format_parsed);
t_format			*ft_parse_format(const char *format, int i, int *j,
					va_list arg);
int					ft_parse_precision(const char *format, int *i, va_list arg,
					t_format *data_format);
int					ft_parse_width(const char *format, int *i, va_list arg,
					t_format *data_format);
void				ft_parse_flag(const char *format, int *i, int *j,
					t_format *data_format);
int					ft_extract_nb(const char *format, char **size,
					int i, int *j);
int					ft_size_nb(long long int nbr);
int					ft_size_hexa(unsigned long long int nb);
t_format			*ft_init_format();
void				ft_putnbr(long long int nb, t_format *format_parsed);
void				ft_putstr_prec(char *str, t_format *format_parsed);
void				ft_display_float(t_format *format_parsed, va_list arg);
char				*ft_llitoa(long long nb);
int					ft_size_llnb(unsigned long long int nb);
void				ft_fill_number_read(va_list arg, int character_read,
					t_format *format_parsed);
void				ft_putnbr_ull(unsigned long long int nb,
					t_format *format_parsed);
int					ft_size_nb_ull(unsigned long long int nb);
void				ft_putdigit(t_format *format_parsed, long double nb);
void				ft_put_float(long double nb, int point,
					t_format *format_parsed);
void				ft_putprefix(t_format *format_parsed, int neg);
int					ft_zero_float(t_format *format_parsed, long double nb);
void				ft_display_float(t_format *format_parsed, va_list arg);
void				ft_putllint(unsigned long long int nb,
					t_format *format_parsed);
int					ft_round_prec_0(unsigned long long int int_part,
					long double nb);
int					ft_is_round(long double nb, t_format *format_parsed,
					int i, int pos);
void				ft_display_width_float(t_format *format_parsed,
					int size_nb,
					int point, int neg);
void				ft_display_zero_float(t_format *format_parsed, int size_nb,
					int point, int neg);
long double			ft_neg_float(t_format *format_parsed,
					long double nb, int *neg);
int					ft_init_option(t_format *format_parsed);
void				ft_putexp_or_float(long double nb, int point,
					t_format *format_parsed);
int					ft_sign_float(t_format *format_parsed, long double *nb);
void				ft_putfloat_no_minus(t_format *format_parsed, int neg,
					int size_nb, int point);

int					ft_find_exp(long double nb);
void				ft_put_e_value(t_format *format_parsed, int exp);
long double			ft_put_int_part(t_format *format_parsed, int point,
					int *exp, long double nb);
long double			ft_put_int_part_minus_exp(t_format *format_parsed,
					int point, int *exp, long double nb);
void				ft_putexp(long double nb, int point,
					t_format *format_parsed);
long double			ft_put_integer_part(t_format *format_parsed,
					unsigned long long int int_part, long double nb, int *exp);
void				ft_print_space_prec(t_format *format_parsed,
					int size_nb, t_nb *nb);
void				ft_putprefix_nb(t_format *format_parsed);
void				ft_putzero_x(t_format *format_parsed, t_nb *nb);
void				ft_putnbr_zero_flag(t_format *format_parsed, t_nb *nb,
					int size_nb);
t_nb				*ft_stocknb(va_list arg, t_format *format_parsed);
void				ft_init_unsigned(t_format *format_parsed, t_nb *nb);
void				ft_init_signed(t_format *format_parsed, t_nb *nb);
t_nb				*ft_init_nb(void);

#endif
