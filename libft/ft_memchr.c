/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:49:33 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/11 20:10:50 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	char_c;
	unsigned char	*char_s;
	size_t			i;

	char_c = (unsigned char)c;
	char_s = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		if (char_s[i] == char_c)
		{
			return ((void*)(char_s + i));
		}
		i++;
	}
	return (NULL);
}
