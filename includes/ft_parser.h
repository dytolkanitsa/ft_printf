/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:58:16 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/07 12:13:43 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_struct
{
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		width;
	int		percision;
	int		skip_symbol;
	char	type;
}	t_struct;

t_struct	ft_parser(const char *format, va_list arg);

void		ft_printing(t_struct specif, va_list arg);
void		ft_print_char(t_struct specif, int c);
void		ft_print_signed(t_struct specif, long int n);
void		ft_print_unsigned(t_struct specif, unsigned int n);
void		ft_print_string(t_struct specif, char *str);
void		ft_print_precent(t_struct specif);
void		ft_print_hexadecimal_lower(t_struct specif, unsigned int nbr);
void		ft_print_hexademical_upper(t_struct specif, unsigned int nbr);
void		ft_print_pointer(t_struct specif, unsigned long long nbr);

int			ft_printf(const char *format, ...);
int			ft_print_count(char c, int flag);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
int			ft_size(long int n);
int			ft_strlen(char *str);
int			hex_size(unsigned long long nbr);
void		ft_print_zero(int len);
void		ft_print_space(int len);
void		ft_return_nothing(t_struct specif);
void		ft_putnbr(long int n);
void		ft_print_sep(int len, int flag);
void		ft_putstr(char *str);
void		ft_short_str(char *str, int len);
void		ft_print_lhex(unsigned int nbr);
void		ft_print_uhex(unsigned int nbr);
void		ft_print_adres(unsigned long long nbr);
char		ft_check(char c, const char *set);
t_struct	init_specif(void);

#endif