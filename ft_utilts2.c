/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilc2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:37:15 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/03 19:24:23 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

static int	if_if(const char *str)
{
	int	i;

	i = 0;
	return (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while (if_if(str))
		str++;
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + (*str - '0');
		str++;
	}
	return (nbr * sign);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_print_count(str[i], 1);
		i++;
	}
}

void	ft_short_str(char *str, int i)
{
	int	len;
	int	n;

	if (str == NULL)
		return ;
	len = ft_strlen(str);
	n = 0;
	while (n < len && n < i)
	{
		ft_print_count(str[n], 1);
		n++;
	}
}
