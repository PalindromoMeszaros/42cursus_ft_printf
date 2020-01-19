/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:38:39 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/19 13:33:40 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*nwlist;
	int		l;

	nwlist = (t_list*)malloc(sizeof(t_list));
	if (nwlist == NULL)
		return (NULL);
	if (content == NULL)
	{
		nwlist->content = NULL;
	}
	else
	{
		l = ft_strlen(content);
		nwlist->content = malloc(sizeof(content) * l);
		if (content == NULL)
			return (NULL);
		ft_memcpy(nwlist->content, content, l);
	}
	nwlist->next = NULL;
	return (nwlist);
}
