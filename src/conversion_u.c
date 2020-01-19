/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 12:39:06 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 17:23:09 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

static char				*itoa_for_u(unsigned int num)
{
	char			*str;
	unsigned int	len;
	unsigned int	aux;

	len = 0;
	aux = num;
	if (num == 0)
		len = 1;
	while (aux != 0)
	{
		aux = aux / 10;
		len++;
	}
	if (!(str = malloc(sizeof(char) * len + 1)))
		exit(-1);
	str[len] = '\0';
	while (len > 0 && num >= 0)
	{
		len--;
		aux = (num % 10);
		str[len] = (aux + 48);
		num = (num / 10);
	}
	return (str);
}

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

static unsigned long	check_precision(unsigned long aux2,
				t_var *var, char *value, unsigned long num_len)
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
	else
		ft_putstr_fd(value, 1);
	var->printf_len += num_len - 1;
	i += num_len;
	return (i);
}

static void				check_width(t_var *var, unsigned long aux,
				unsigned long aux2, unsigned long num_len)
{
	while ((aux > aux2 && ((var->flag[1] != '0' && var->flag[2] != '.')
		|| (var->flag[1] == '0' && var->flag[2] == '.') || (var->flag[2] == '.'
		&& var->width > var->precision)) && aux > num_len))
	{
		ft_putchar_fd(' ', 1);
		aux--;
		var->printf_len++;
	}
}

t_var					*u_conversion(unsigned int num, t_var *var)
{
	char			*value;
	unsigned long	num_len;
	unsigned long	aux;
	unsigned long	aux2;

	value = itoa_for_u(num);
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
