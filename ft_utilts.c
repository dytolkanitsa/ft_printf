/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 20:08:48 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/07 12:13:56 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

t_struct	init_specif(void)
{
	t_struct	specif;

	specif.minus = 0;
	specif.plus = 0;
	specif.space = 0;
	specif.zero = 0;
	specif.width = 0;
	specif.percision = -1;
	specif.skip_symbol = 0;
	specif.type = '0';
	return (specif);
}

void	ft_return_nothing(t_struct specif)
{
	if (specif.width == 0)
		return ;
	else
		ft_print_space(specif.width);
}

void	ft_print_sep(int len, int flag)
{
	while (len > 0)
	{
		if (flag == 1)
			ft_print_count('0', 1);
		else
			ft_print_count(' ', 1);
		len--;
	}
}

int	ft_size(long int n)
{
	int	size;

	size = 1;
	if (n < 0)
	{
		n = -n;
		size++;
	}
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void	ft_putnbr(long int n)
{
	long long	nbr;

	nbr = n;
	if (n < 0)
	{
		ft_print_count('-', 1);
		n = -n;
	}
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_print_count((nbr % 10 + '0'), 1);
	}
	else
		ft_print_count((nbr % 10 + '0'), 1);
}
