/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:33:04 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/13 18:52:10 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_len(long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	if (num < 0)
	{
		num = -1 * num;
		len++;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

static char		*algo(long int num, int len, char *itoa, int i)
{
	while (num > 0)
	{
		itoa[(len--) - 1] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	return (itoa);
}

char			*ft_itoa(int n)
{
	int			len;
	char		*itoa;
	int			i;
	long int	num;

	num = n;
	len = ft_len(num);
	i = 0;
	if (!(itoa = (void*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	itoa[len] = '\0';
	if (num == 0)
	{
		itoa[0] = 48;
		return (itoa);
	}
	if (num < 0)
	{
		itoa[0] = '-';
		num = num * -1;
	}
	algo(num, len, itoa, i);
	return (itoa);
}
