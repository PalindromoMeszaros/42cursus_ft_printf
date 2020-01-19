/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:28:52 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/18 22:23:21 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	altc;
	char	*altstr;
	int		i;

	altc = c;
	altstr = (char*)str;
	i = 0;
	while (altstr[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (altstr[i] == altc)
		{
			return (altstr + i);
		}
		i--;
	}
	return (NULL);
}
