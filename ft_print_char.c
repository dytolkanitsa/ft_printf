/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:11:31 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/03 19:23:36 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

void	ft_print_char(t_struct specif, int c)
{
	if (!specif.zero && specif.width > 1 && !specif.minus)
		ft_print_space(specif.width - 1);
	ft_print_count(c, 1);
	if (!specif.zero && specif.width > 1 && specif.minus)
		ft_print_space(specif.width - 1);
}
