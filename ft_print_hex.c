/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 18:24:44 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/05 16:37:47 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

void	ft_print_hexadecimal_lower(t_struct specif, unsigned int nbr)
{
	if (nbr == 0 && specif.percision == 0)
		return (ft_return_nothing(specif));
	if (specif.percision >= 0)
		specif.zero = 0;
	if (specif.percision < hex_size(nbr))
		specif.percision = hex_size(nbr);
	if (!specif.minus)
		ft_print_sep((specif.width - specif.percision), specif.zero);
	ft_print_zero(specif.percision - hex_size(nbr));
	ft_print_lhex(nbr);
	if (specif.minus)
		ft_print_sep((specif.width - specif.percision), specif.zero);
}

void	ft_print_hexademical_upper(t_struct specif, unsigned int nbr)
{
	if (nbr == 0 && specif.percision == 0)
		return (ft_return_nothing(specif));
	if (specif.percision >= 0)
		specif.zero = 0;
	if (specif.percision < hex_size(nbr))
		specif.percision = hex_size(nbr);
	if (!specif.minus)
		ft_print_sep((specif.width - specif.percision), specif.zero);
	ft_print_zero(specif.percision - hex_size(nbr));
	ft_print_uhex(nbr);
	if (specif.minus)
		ft_print_sep((specif.width - specif.percision), specif.zero);
}

int	hex_size(unsigned long long nbr)
{
	int	size;

	size = 0;
	if (nbr == 0)
	{
		size = 1;
	}
	while (nbr)
	{
		nbr = nbr / 16;
		size++;
	}
	return (size);
}
