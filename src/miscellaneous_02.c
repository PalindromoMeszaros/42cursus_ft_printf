/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miscellaneous_02.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:58:37 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/16 18:56:42 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void			p_justified_precision(char *ptr, char *value, t_var *var,
				unsigned long num_len)
{
	p_null_processing(ptr, value, var, num_len);
	p_check_precision(ptr, var, value, num_len);
}

void			p_unjustified_precision(char *ptr, char *value, t_var *var,
				unsigned long num_len)
{
	p_check_precision(ptr, var, value, num_len);
	p_null_processing(ptr, value, var, num_len);
}

unsigned long	p_num_len_conditions(char *value, t_var *var)
{
	unsigned long	num_len;

	if (var->precision > ft_strlen(value) && value != 0)
		num_len = ft_strlen(value);
	else
		num_len = ft_strlen(value) + 2;
	return (num_len);
}
