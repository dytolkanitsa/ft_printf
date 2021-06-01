/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarg <lgarg@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:58:20 by lgarg             #+#    #+#             */
/*   Updated: 2021/05/07 12:08:23 by lgarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_parser.h"
#include "./includes/ft_printf.h"

static void	pars_flags(const char *format, t_struct *specif)
{
	int	i;

	i = 0;
	while (1)
	{
		if (format[i] == '-')
			(*specif).minus = 1;
		else if (format[i] == '+')
			(*specif).plus = 1;
		else if (format[i] == ' ')
			(*specif).space = 1;
		else if (format[i] == '0')
			(*specif).zero = 1;
		else
			break ;
		i++;
	}
	(*specif).skip_symbol = i;
}

static void	pars_width(const char *format, t_struct *specif, va_list arg)
{
	if (format[(*specif).skip_symbol] == '*')
	{
		(*specif).width = va_arg(arg, int);
		if ((*specif).width < 0)
		{
			(*specif).width = -(*specif).width;
			(*specif).minus = 1;
		}
		(*specif).skip_symbol++;
		return ;
	}
	(*specif).width = ft_atoi(format + (*specif).skip_symbol);
	while (ft_isdigit(format[(*specif).skip_symbol]))
		(*specif).skip_symbol++;
}

static void	pars_percision(const char *format, t_struct *specif, va_list arg)
{
	if (format[(*specif).skip_symbol] == '.')
		(*specif).skip_symbol++;
	else
		return ;
	if (format[(*specif).skip_symbol] == '*')
	{
		(*specif).percision = va_arg(arg, int);
		(*specif).skip_symbol++;
		return ;
	}
	(*specif).percision = ft_atoi(format + (*specif).skip_symbol);
	while (ft_isdigit(format[(*specif).skip_symbol]))
		(*specif).skip_symbol++;
}

static void	pars_type(const char *format, t_struct *specif)
{
	if (ft_check(format[(*specif).skip_symbol], "cspdiuxX%"))
	{
		(*specif).type = format[(*specif).skip_symbol];
		(*specif).skip_symbol++;
	}
	else
		return ;
}

t_struct	ft_parser(const char *format, va_list arg)
{
	t_struct	specif;

	specif = init_specif();
	pars_flags(format, &specif);
	pars_width(format, &specif, arg);
	pars_percision(format, &specif, arg);
	pars_type(format, &specif);
	return (specif);
}
