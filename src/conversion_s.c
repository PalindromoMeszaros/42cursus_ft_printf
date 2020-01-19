/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 15:48:31 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 17:21:12 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static unsigned long	check_precision(unsigned long aux2,
						t_var *var, char *str, unsigned long len)
{
	unsigned long i;

	i = 0;
	i = d_precision_null(str, var, aux2);
	if (aux2 <= len && var->flag[2] == '.')
	{
		while (aux2-- > 0)
		{
			ft_putchar_fd(str[i++], 1);
			var->printf_len++;
		}
		var->printf_len--;
	}
	else
	{
		ft_putstr_fd(str, 1);
		i = ft_strlen(str);
		var->printf_len += (ft_strlen(str) - 1);
	}
	return (i);
}

static void				check_width(unsigned long aux,
						char *str, t_var *var, unsigned int len)
{
	if (var->flag[2] == '.' && str == NULL && var->precision
						<= 6 && var->flag[1] != '0')
	{
		if (var->width > var->precision)
			aux = aux - var->precision;
		else if (var->precision >= var->width)
			aux = 0;
	}
	while (((aux > var->precision && var->flag[2] == '.') || (var->flag[2]
		!= '.' && aux > len && aux > var->precision) || (var->precision
		> len && aux > len)) && (var->flag[1] != '0' || var->flag[0] == '-'))
	{
		ft_putchar_fd(' ', 1);
		aux--;
		var->printf_len++;
	}
	while (aux > len && var->flag[1] == '0')
	{
		ft_putchar_fd('0', 1);
		aux--;
		var->printf_len++;
	}
}

static t_var			*null_processing(char *str, t_var *var)
{
	unsigned int	i;

	i = 0;
	if (str == NULL)
	{
		var->str_null = "(null)";
		while (var->str_null[i] != '\0' && (var->flag[2] != '.' || (var->flag[2]
	== '.' && var->flag[1] == '0' && i < var->precision) || (var->flag[0]
	== '-' && var->flag[2] == '.' && var->precision > 0 && i < var->precision)))
		{
			ft_putchar_fd(var->str_null[i], 1);
			i++;
			var->printf_len++;
		}
	}
	return (var);
}

static unsigned long	len_processing(unsigned long len, t_var *var)
{
	if (var->width > 6 && var->flag[2] != '.')
		len = 6;
	else if (var->width <= 6 && (var->flag[2] != '.'))
		len = 6 - var->width;
	else if (var->flag[2] == '.' && var->width == 0 && var->precision < 6)
		len = 0;
	else if (var->flag[0] == '-' && var->precision > 6)
		len = 6;
	return (len);
}

t_var					*s_conversion(char *str, t_var *var)
{
	unsigned long	aux;
	unsigned long	aux2;
	unsigned long	len;

	aux = var->width;
	aux2 = var->precision;
	len = 0;
	if (str != NULL)
		len = ft_strlen(str);
	else
		len = len_processing(len, var);
	if (var->flag[0] == '-')
	{
		null_processing(str, var);
		check_precision(aux2, var, str, len);
		check_width(aux, str, var, len);
	}
	else
	{
		check_width(aux, str, var, len);
		null_processing(str, var);
		check_precision(aux2, var, str, len);
	}
	return (var);
}
