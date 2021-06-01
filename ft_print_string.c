/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:50:36 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/03 19:24:07 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

void	ft_print_string(t_struct specif, char *str)
{
	if (!str)
		return (ft_print_string(specif, "(null)"));
	if (specif.percision < 0)
		specif.percision = -1;
	if ((specif.percision < 0 || specif.percision >= ft_strlen(str))
		&& !specif.minus)
		ft_print_sep((specif.width - ft_strlen(str)), specif.zero);
	else if (!specif.minus && specif.percision != -1)
		ft_print_sep((specif.width - specif.percision), specif.zero);
	if (specif.percision == -1)
		ft_putstr(str);
	else
		ft_short_str(str, specif.percision);
	if ((specif.percision == -1 || specif.percision >= ft_strlen(str))
		&& specif.minus)
		ft_print_sep((specif.width - ft_strlen(str)), specif.zero);
	else if (specif.minus && specif.percision != -1)
		ft_print_sep((specif.width - specif.percision), specif.zero);
}
