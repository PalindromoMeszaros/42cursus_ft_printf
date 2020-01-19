/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:01:27 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 18:32:11 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static void				precision_conditions(unsigned long aux,
				t_var *var, unsigned long num_len, char *value)
{
	unsigned long aux2;

	aux2 = var->precision;
	if (var->negative_num < 0)
		aux--;
	aux = pointer_zero_precision(aux, var, num_len);
	if ((var->precision > num_len))
	{
		ft_putstr_fd("0x", 1);
		var->printf_len += 2;
		while (aux2 > num_len)
		{
			ft_putchar_fd('0', 1);
			aux2--;
			var->printf_len++;
		}
		ft_putstr_fd(value, 1);
	}
}

static unsigned long	check_width(t_var *var, unsigned long aux,
						void *ptr, unsigned long num_len)
{
	if (var->flag[2] == '.' && ptr == NULL && var->precision <= 2
			&& var->flag[1] != '0')
	{
		if (var->width > var->precision && var->precision != 0)
			aux = aux - var->precision;
		else if (var->precision >= var->width)
			aux = 0;
	}
	if (var->flag[2] == '.' && ptr == NULL && var->precision == 0
			&& var->width > 2 && var->flag[1] != '0')
		num_len--;
	while ((aux > var->precision && ((var->flag[1] != '0'
	&& var->flag[2] != '.') || (var->flag[1] == '0' && var->flag[2] == '.')
	|| (var->flag[2] == '.' && var->width > var->precision)) && aux > num_len))
	{
		ft_putchar_fd(' ', 1);
		aux--;
		var->printf_len++;
	}
	return (aux);
}

unsigned long			p_check_precision(void *ptr, t_var *var,
						char *value, unsigned long num_len)
{
	unsigned long i;
	unsigned long aux;

	aux = var->width;
	i = 0;
	precision_conditions(aux, var, num_len, value);
	if (var->flag[2] == '.' && var->precision == 0)
	{
		if (var->width > 0 && ptr != NULL)
			ft_putchar_fd(' ', 1);
		else
			return (var->printf_len--);
	}
	else if (ptr != NULL && var->precision <= num_len)
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(value, 1);
	}
	var->printf_len += num_len - 1;
	i += num_len;
	return (i);
}

void					p_null_processing(void *ptr, char *value, t_var *var,
						unsigned long num_len)
{
	if (var->precision < num_len && ptr == NULL && (var->flag[1] != '0'
		& var->flag[2] == '.' || (var->flag[1] == '0' && var->flag[2] == '.'
		&& var->width == 0 && var->precision == 0)))
	{
		ft_putstr_fd("0x", 1);
		var->printf_len += 2;
	}
	else if (var->precision < num_len && ptr == NULL
		&& var->flag[1] != '0' && var->flag[2] != '0')
	{
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(value, 1);
	}
}

t_var					*p_conversion(void *ptr, t_var *var)
{
	unsigned long	num;
	unsigned long	aux;
	unsigned long	aux2;
	unsigned long	num_len;
	char			*value;

	num = (unsigned long)ptr;
	if (!(value = ft_itoa_base(num, 16, 'a')))
		exit(-1);
	num_len = p_num_len_conditions(value, var);
	aux = var->width;
	aux2 = var->precision;
	if (var->flag[0] == '-')
	{
		p_justified_precision(ptr, value, var, num_len);
		check_width(var, aux, ptr, num_len);
	}
	else
	{
		check_width(var, aux, ptr, num_len);
		p_unjustified_precision(ptr, value, var, num_len);
	}
	free(value);
	return (var);
}
