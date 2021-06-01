/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 14:20:37 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/05 16:34:54 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

static void	print_pointer(t_struct specif, unsigned long long nbr)
{
	if (specif.percision > 0)
		specif.zero = 0;
	if (specif.percision < hex_size(nbr))
		specif.percision = hex_size(nbr);
	if (specif.zero)
		ft_putstr("0x");
	if (!specif.minus)
		ft_print_sep((specif.width - specif.percision - 2), specif.zero);
	if (!specif.zero)
		ft_putstr("0x");
	ft_print_zero(specif.percision - hex_size(nbr));
	ft_print_adres(nbr);
	if (specif.minus)
		ft_print_sep((specif.width - specif.percision - 2), specif.zero);
}

void	ft_print_pointer(t_struct specif, unsigned long long nbr)
{
	if (nbr == 0 && specif.percision == 0)
	{
		if (specif.zero)
			ft_putstr("0x");
		if (!specif.minus)
			ft_print_sep((specif.width - specif.percision - 2), specif.zero);
		if (!specif.zero)
			ft_putstr("0x");
	}
	else
	{
		print_pointer(specif, nbr);
	}
}
