/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 00:37:08 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/12 19:47:22 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*cal;
	size_t	i;

	i = 0;
	if (!(cal = malloc(size * count)))
		return (NULL);
	while (i < size * count)
	{
		((char*)cal)[i] = 0;
		i++;
	}
	return (cal);
}
