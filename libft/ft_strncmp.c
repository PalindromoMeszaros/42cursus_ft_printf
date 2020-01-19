/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:35:33 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/08 19:48:53 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char*)str1;
	st2 = (unsigned char*)str2;
	i = 0;
	if (n == 0)
		return (0);
	while (st1[i] == st2[i] && st1[i]
			!= '\0' && st2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return (st1[i] - st2[i]);
}
