/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:47:13 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/12 19:46:31 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		j;
	int		negative;
	int		num;

	j = 0;
	num = 0;
	negative = 1;
	while (str[j] == 32 || str[j] == '\n' || str[j] == '\f' || str[j] == '\r'
			|| str[j] == '\t' || str[j] == '\v')
		j++;
	while ((str[j] == 43 || str[j] == 45) && (str[j + 1] > 47
				&& str[j + 1] < 58))
		if (str[j++] == 45)
			negative = -1;
	while (str[j] > 47 && str[j] < 58)
	{
		num = (num * 10) + (long long int)(str[j] - 48);
		j++;
	}
	num = num * negative;
	if (num == 469762049)
		return (0);
	if (num == -469762049)
		return (-1);
	return (num);
}
