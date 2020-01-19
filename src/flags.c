/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:02:22 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 18:37:43 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_var		*initialize(t_var *var)
{
	var->count = 0;
	var->printf_len = 0;
	var->width = 0;
	var->flags_map = "-0.*";
	var->precision = 0;
	return (var);
}

t_var		*reinitialize(t_var *var)
{
	var->flag[0] = '\0';
	var->flag[1] = '\0';
	var->flag[2] = '\0';
	var->flag[3] = '\0';
	var->flag[4] = '\0';
	var->width = 0;
	var->precision = 0;
	return (var);
}

t_var		*flags_activate(t_var *var)
{
	int	i;
	int j;

	i = 0;
	var->count++;
	j = var->count;
	while (var->flags_map[i] != '\0')
	{
		while (var->flags_map[i] == var->format[j]
				|| (var->format[j] > '0' && var->format[j] <= '9'))
		{
			j = flag_saving(var, j);
			i = 0;
		}
		i++;
	}
	return (var);
}

t_var		*field_width(t_var *var)
{
	while (var->format[var->count] == '0' || var->format[var->count] == '-')
	{
		var->count++;
	}
	while (var->format[var->count] >= '0' && var->format[var->count] <= '9')
	{
		var->width *= 10;
		var->width += (var->format[var->count] - 48);
		var->count++;
	}
	if (var->format[var->count] == '*')
	{
		var->flag[3] = '*';
		var->neg_star = va_arg(var->args, int);
		if (var->neg_star >= 0)
			var->width = var->neg_star;
		else
		{
			var->width = -1 * var->neg_star;
			var->flag[0] = '-';
			var->flag[1] = '\0';
		}
		var->count++;
	}
	return (var);
}

t_var		*precision(t_var *var)
{
	if (var->format[var->count] == '.')
	{
		var->flag[2] = '.';
		var->count++;
	}
	while (var->format[var->count] > 47 && var->format[var->count] < 58)
	{
		var->precision *= 10;
		var->precision += (var->format[var->count] - 48);
		var->count++;
	}
	if (var->format[var->count] == '*')
	{
		var->flag[3] = '*';
		var->neg_star = va_arg(var->args, int);
		if (var->neg_star >= 0)
			var->precision = var->neg_star;
		else
			var->flag[2] = '\0';
		var->count++;
	}
	return (var);
}
