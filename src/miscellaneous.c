/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:53:04 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 18:42:17 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void				check_negative(t_var *var)
{
	if (var->negative_num < 0)
	{
		ft_putchar_fd('-', 1);
		var->printf_len++;
	}
}

unsigned long		d_precision_null(char *str, t_var *var, unsigned long aux2)
{
	unsigned long i;

	i = 0;
	if (str == NULL && var->flag[2] == '.' && var->flag[0]
			!= '-' && var->precision <= 6 && var->flag[1] != '0')
	{
		while (aux2-- > 0)
		{
			ft_putchar_fd(var->str_null[i++], 1);
			var->printf_len++;
		}
	}
	return (i);
}

int					flag_saving(t_var *var, int j)
{
	while (var->format[j] > '0' && var->format[j] <= '9')
		j++;
	while (var->format[j] == '-' && j++)
		var->flag[0] = '-';
	while (var->format[j] == '0' && j++)
	{
		if ((var->format[j - 2] == '%') || (var->format[j - 2] < 48)
				|| (var->format[j - 2] > 57))
			var->flag[1] = '0';
	}
	while (var->format[j] == '.' && j++)
		var->flag[2] = '.';
	while (var->format[j] == '*' && j++)
		var->flag[3] = '*';
	while (var->format[j] == '%')
		j++;
	return (j);
}

unsigned long		pointer_zero_precision(unsigned long aux, t_var *var,
					unsigned long num_len)
{
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
	return (aux);
}

unsigned long		di_num_len(char *value, t_var *var, int num)
{
	unsigned long	num_len;

	num_len = ft_strlen(value);
	if (var->flag[3] == '*' && num != 0)
		var->flag[2] = '\0';
	return (num_len);
}
