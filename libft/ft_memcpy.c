/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:13:15 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/19 16:14:23 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t i;

	if (dest || src)
	{
		i = 0;
		while (i < n)
		{
			((char*)dest)[i] = ((char*)src)[i];
			i++;
		}
		return (dest);
	}
	else
		return (NULL);
}
