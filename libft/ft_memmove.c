/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:17:31 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/15 17:21:32 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dsa;
	unsigned char	*sra;
	unsigned int	i;

	i = 0;
	dsa = (unsigned char*)dst;
	sra = (unsigned char*)src;
	if (dst || src)
	{
		if (sra < dsa)
			while (i++ < len)
				dsa[len - i] = sra[len - i];
		else
		{
			i = 0;
			while (len-- > 0)
			{
				dsa[i] = sra[i];
				i++;
			}
		}
		return (dst);
	}
	else
		return (NULL);
}
