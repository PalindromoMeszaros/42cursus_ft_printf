/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:06:24 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 17:03:28 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"
#include <stdio.h>

static void		conditional_putchar(int c, int aux, t_var *var)
{
	while (aux-- > 1)
	{
		ft_putchar_fd(c, 1);
		var->printf_len++;
	}
}

t_var			*pct_conversion(t_var *var)
{
	int aux;

	aux = var->width;
	if (var->flag[0] == '-')
	{
		ft_putchar_fd('%', 1);
		conditional_putchar(' ', aux, var);
	}
	else if (var->flag[1] == '0' && var->flag[0] != '-')
	{
		conditional_putchar(48, aux, var);
		ft_putchar_fd('%', 1);
	}
	else
	{
		conditional_putchar(' ', aux, var);
		ft_putchar_fd('%', 1);
	}
	return (var);
}
