/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 15:58:57 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/14 14:43:34 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static void		conditional_putchar(int c, int aux, t_var *var)
{
	while (aux-- > 1)
	{
		ft_putchar_fd(c, 1);
		var->printf_len++;
	}
}

t_var			*c_conversion(int c, t_var *var)
{
	int aux;

	c = (unsigned char)c;
	aux = var->width;
	if (var->flag[0] == '-')
	{
		ft_putchar_fd(c, 1);
		conditional_putchar(' ', aux, var);
	}
	else if (var->flag[1] == '0' && var->flag[0] != '-')
	{
		conditional_putchar('0', aux, var);
		ft_putchar_fd(c, 1);
	}
	else
	{
		conditional_putchar(' ', aux, var);
		ft_putchar_fd(c, 1);
	}
	return (var);
}
