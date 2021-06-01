/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_precent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:59:24 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/04 19:38:13 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

void	ft_print_precent(t_struct specif)
{
	char	c;

	c = '%';
	if (specif.percision != 1)
		specif.percision = 1;
	if (specif.minus != 0)
		specif.zero = 0;
	if (!specif.minus && !specif.zero)
		ft_print_sep((specif.width - 1), specif.zero);
	else if (!specif.minus && specif.zero == 1)
		ft_print_zero(specif.width - specif.percision);
	ft_print_count(c, 1);
	if (specif.minus)
		ft_print_sep((specif.width - 1), specif.zero);
}
