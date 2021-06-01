/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:58:18 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/07 12:09:42 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list		arg;
	int			i;
	t_struct	specif;

	i = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			specif = ft_parser(format + i + 1, arg);
			ft_printing(specif, arg);
			i = i + specif.skip_symbol;
		}
		else
			ft_print_count(format[i], 1);
		i++;
	}
	va_end(arg);
	return (ft_print_count('-', 0));
}
