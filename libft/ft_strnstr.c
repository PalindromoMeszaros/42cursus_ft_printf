/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:43:27 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/16 21:05:21 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (n[0] == '\0')
		return ((char*)h);
	while (h[i] != 0 && i < len)
	{
		j = 0;
		while (n[j] == h[i + j])
		{
			if (n[j + 1] == '\0' && ((i + j) < len))
			{
				return (((char*)h + i));
			}
			j++;
		}
		i++;
	}
	return (0);
}
