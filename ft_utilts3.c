/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilts3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 14:57:07 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/05 16:44:11 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_print_lhex(unsigned int nbr)
{
	unsigned int	basetype;
	char			*base;

	base = "0123456789abcdef";
	basetype = 16;
	if (nbr > basetype - 1)
	{
		ft_print_lhex(nbr / basetype);
		ft_print_count((base[nbr % basetype]), 1);
	}
	else
		ft_print_count((base[nbr]), 1);
}

void	ft_print_uhex(unsigned int nbr)
{
	unsigned int	basetype;
	char			*base;

	base = "0123456789ABCDEF";
	basetype = 16;
	if (nbr > basetype - 1)
	{
		ft_print_uhex(nbr / basetype);
		ft_print_count((base[nbr % basetype]), 1);
	}
	else
		ft_print_count((base[nbr]), 1);
}

void	ft_print_adres(unsigned long long nbr)
{
	unsigned int	basetype;
	char			*base;

	base = "0123456789abcdef";
	basetype = 16;
	if (nbr > basetype - 1)
	{
		ft_print_adres(nbr / basetype);
		ft_print_count((base[nbr % basetype]), 1);
	}
	else
		ft_print_count((base[nbr]), 1);
}

char	ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
