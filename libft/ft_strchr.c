/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:52:34 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/11 21:52:16 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	altc;
	char	*altstr;
	int		i;

	altc = c;
	altstr = (char*)str;
	i = 0;
	while (altstr[i] != '\0')
	{
		if (altstr[i] == altc)
		{
			return (altstr + i);
		}
		i++;
	}
	if (altc == '\0')
		return (altstr + i);
	return (NULL);
}
