/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:15:32 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/11 21:43:35 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_1;
	unsigned char	*s_2;
	size_t			i;

	s_1 = (unsigned char*)s1;
	s_2 = (unsigned char*)s2;
	i = 0;
	while ((i < n) && (s_1[i] == s_2[i]))
	{
		if (s_1[i] == s_2[i])
			i++;
	}
	if (i == n)
		return (0);
	else
		return (s_1[i] - s_2[i]);
}
