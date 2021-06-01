/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:58:21 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/05 17:31:20 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

void	ft_printing(t_struct specif, va_list arg)
{
	if (specif.type == 'c')
		ft_print_char(specif, (va_arg(arg, int)));
	else if (specif.type == 's')
		ft_print_string(specif, (va_arg(arg, char *)));
	else if (specif.type == 'p')
		ft_print_pointer(specif, (va_arg(arg, unsigned long long)));
	else if (specif.type == 'd' || specif.type == 'i')
		ft_print_signed(specif, (va_arg(arg, int)));
	else if (specif.type == 'u')
		ft_print_unsigned(specif, (va_arg(arg, unsigned int)));
	else if (specif.type == 'x')
		ft_print_hexadecimal_lower(specif, (va_arg(arg, unsigned int)));
	else if (specif.type == 'X')
		ft_print_hexademical_upper(specif, (va_arg(arg, unsigned int)));
	else if (specif.type == '%')
		ft_print_precent(specif);
}

void	ft_print_zero(int len)
{
	while (len > 0)
	{
		ft_print_count('0', 1);
		len--;
	}
}

void	ft_print_space(int len)
{
	while (len > 0)
	{
		ft_print_count(' ', 1);
		len--;
	}
}

int	ft_print_count(char c, int flag)
{
	static int		count;
	int				temp;

	if (flag)
	{
		count++;
		write(1, &c, 1);
		return (1);
	}
	else
	{
		temp = count;
		count = 0;
		return (temp);
	}
}
