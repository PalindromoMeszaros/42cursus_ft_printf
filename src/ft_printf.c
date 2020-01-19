/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:43:40 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 18:35:40 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_var		*print(t_var *var)
{
	if (var->format[var->count] == '%')
		var = pct_conversion(var);
	if (var->format[var->count] == 'c')
		c_conversion(va_arg(var->args, int), var);
	else if (var->format[var->count] == 's')
		var = s_conversion(va_arg(var->args, char*), var);
	else if (var->format[var->count] == 'x')
		var = x_conversion(va_arg(var->args, unsigned int), var);
	else if (var->format[var->count] == 'X')
		var = x_capital_conversion(va_arg(var->args, unsigned int), var);
	else if (var->format[var->count] == 'd' || var->format[var->count] == 'i')
		var = di_conversion(va_arg(var->args, int), var);
	else if (var->format[var->count] == 'u')
		var = u_conversion(va_arg(var->args, unsigned int), var);
	else if (var->format[var->count] == 'p')
		var = p_conversion(va_arg(var->args, void*), var);
	var->printf_len++;
	return (var);
}

int			processing(t_var *var)
{
	flags_activate(var);
	field_width(var);
	precision(var);
	print(var);
	if (var->format[var->count] == 's' || var->format[var->count] == 'c' ||
		var->format[var->count] == 'p' || var->format[var->count] == 'd' ||
		var->format[var->count] == 'i' || var->format[var->count] == 'u' ||
		var->format[var->count] == 'x' || var->format[var->count] == 'X' ||
		var->format[var->count] == '%')
		var->count++;
	return (var->printf_len);
}

int			ft_printf(const char *format, ...)
{
	t_var		*var;

	if (!(var = (t_var*)malloc(sizeof(t_var))))
		exit(-1);
	var->format = (char*)format;
	var = initialize(var);
	va_start(var->args, format);
	while (var->format[var->count] != '\0')
	{
		if (var->format[var->count] == '%')
		{
			reinitialize(var);
			processing(var);
		}
		else if (var->format[var->count] != '%')
		{
			ft_putchar_fd(format[var->count], 1);
			var->printf_len++;
			var->count++;
		}
	}
	va_end(var->args);
	free(var);
	return (var->printf_len);
}
