/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 11:12:50 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/04 15:24:19 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

void	ft_print_signed(t_struct specif, long int n)
{
	if (n >= 0)
		ft_print_unsigned(specif, (unsigned int)n);
	else
	{
		if (n == 0 && specif.percision == 0)
			return (ft_return_nothing(specif));
		n = -n;
		if (specif.percision >= 0)
			specif.zero = 0;
		if (specif.minus != 0)
			specif.zero = 0;
		if (specif.percision < ft_size(n))
			specif.percision = ft_size(n);
		if (specif.zero)
			ft_print_count('-', 1);
		if (!specif.minus)
			ft_print_sep((specif.width - specif.percision - 1), specif.zero);
		if (!specif.zero)
			ft_print_count('-', 1);
		ft_print_zero(specif.percision - ft_size(n));
		ft_putnbr(n);
		if (specif.minus)
			ft_print_sep((specif.width - specif.percision - 1), specif.zero);
	}
}

void	ft_print_unsigned(t_struct specif, unsigned int n)
{
	if (n == 0 && specif.percision == 0)
		return (ft_return_nothing(specif));
	else
	{
		if (specif.percision >= 0)
			specif.zero = 0;
		if (specif.minus != 0)
			specif.zero = 0;
		if (specif.percision < ft_size(n))
			specif.percision = ft_size(n);
		if (!specif.minus)
			ft_print_sep((specif.width - specif.percision), specif.zero);
		if (specif.plus)
			ft_print_count('+', 1);
		else if (specif.space)
			ft_print_count(' ', 1);
		ft_print_zero(specif.percision - ft_size(n));
		ft_putnbr(n);
		if (specif.minus)
			ft_print_sep((specif.width - specif.percision), specif.zero);
	}
}
