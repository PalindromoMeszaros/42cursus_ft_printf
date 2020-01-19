/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 00:04:16 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/16 18:18:29 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		size;

	size = 0;
	while (s1[size] != '\0')
		size++;
	if (!(cpy = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	size = 0;
	while (s1[size] != '\0')
	{
		cpy[size] = s1[size];
		size++;
	}
	cpy[size] = '\0';
	return (cpy);
}
