/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 20:07:24 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 17:26:40 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

static void				precision_conditions(unsigned long aux,
		unsigned long aux2, t_var *var, unsigned long num_len)
{
	if (var->negative_num < 0)
		aux--;
	if (aux > num_len && var->flag[1] == 48 &&
			(var->width < var->precision || var->flag[2] != '.'))
	{
		while (aux > num_len)
		{
			ft_putchar_fd('0', 1);
			aux--;
			var->printf_len++;
		}
	}
	if ((var->precision > num_len))
	{
		while (aux2 > num_len)
		{
			ft_putchar_fd('0', 1);
			aux2--;
			var->printf_len++;
		}
	}
}

static unsigned long	check_precision(unsigned long aux2, t_var *var,
						char *value, unsigned long num_len)
{
	unsigned long i;
	unsigned long aux;

	aux = var->width;
	i = 0;
	precision_conditions(aux, aux2, var, num_len);
	if (var->flag[2] == '.' && var->precision == 0)
	{
		if (var->width > 0)
			ft_putchar_fd(' ', 1);
		else
			return (var->printf_len--);
	}
	else if (value != NULL)
		ft_putstr_fd(value, 1);
	var->printf_len += num_len - 1;
	i += num_len;
	return (i);
}

static unsigned long	check_width(t_var *var, unsigned long aux,
						unsigned long aux2, unsigned long num_len)
{
	if (var->negative_num < 0)
	{
		if (num_len > var->precision)
			num_len++;
		else
			aux2++;
	}
	while ((aux > aux2 && ((var->flag[1] != '0' && var->flag[2] != '.')
		|| (var->flag[1] == '0' && var->flag[2] == '.') || (var->flag[2] == '.'
		&& var->width > var->precision)) && aux > num_len))
	{
		ft_putchar_fd(' ', 1);
		aux--;
		var->printf_len++;
	}
	return (aux);
}

t_var					*x_conversion(unsigned int num, t_var *var)
{
	unsigned long	num_len;
	unsigned long	aux;
	unsigned long	aux2;
	char			*value;

	if (!(value = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	num_len = ft_strlen(value);
	aux = var->width;
	aux2 = var->precision;
	if (var->flag[0] == '-')
	{
		check_precision(aux2, var, value, num_len);
		check_width(var, aux, aux2, num_len);
	}
	else
	{
		check_width(var, aux, aux2, num_len);
		check_precision(aux2, var, value, num_len);
	}
	free(value);
	return (var);
}

t_var					*x_capital_conversion(unsigned int num, t_var *var)
{
	unsigned long	num_len;
	unsigned long	aux;
	unsigned long	aux2;
	char			*value;

	if (!(value = ft_itoa_base(num, 16, 'A')))
		exit(-1);
	num_len = ft_strlen(value);
	aux = var->width;
	aux2 = var->precision;
	if (var->flag[0] == '-')
	{
		check_precision(aux2, var, value, num_len);
		check_width(var, aux, aux2, num_len);
	}
	else
	{
		check_width(var, aux, aux2, num_len);
		check_precision(aux2, var, value, num_len);
	}
	free(value);
	return (var);
}
