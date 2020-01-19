/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:32:09 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/19 16:16:27 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *restrict d, const void *restrict s, int c, size_t n)
{
	size_t			i;
	unsigned char	char_c;
	unsigned char	*sr2;
	unsigned char	*dst2;

	sr2 = (unsigned char*)s;
	dst2 = (unsigned char*)d;
	char_c = c;
	i = 0;
	while (i < n)
	{
		dst2[i] = sr2[i];
		if (sr2[i] == char_c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}
