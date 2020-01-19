/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 21:16:02 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/19 18:37:07 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		s_len;
	size_t		m_size;
	size_t		i;
	char		*p;

	s_len = 0;
	i = 0;
	if (!s)
		return (NULL);
	while (s[s_len] != '\0')
		s_len++;
	if (s_len >= len + start + 1)
		m_size = len;
	else
		m_size = (s_len - start);
	if (s_len < start)
		return (ft_strdup(""));
	if (!(p = ((char*)malloc(sizeof(char) * m_size + 1))))
		return (NULL);
	while (i < m_size)
		p[i++] = s[start++];
	p[i] = '\0';
	return (p);
}
