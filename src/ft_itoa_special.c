/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 16:20:39 by pablomar          #+#    #+#             */
/*   Updated: 2020/01/09 16:48:30 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

static int		ft_len(long int num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	if (num < 0)
		num = -1 * num;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char			*ft_itoa_special(int n)
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
		num = num * -1;
	while (num > 0)
	{
		itoa[(len--) - 1] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	return (itoa);
}
