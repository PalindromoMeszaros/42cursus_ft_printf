/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 20:13:57 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/19 13:36:52 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*aux;
	t_list	*nxt;

	if (lst && *lst && del)
	{
		aux = *lst;
		while (aux)
		{
			nxt = aux->next;
			ft_lstdelone(aux, del);
			aux = nxt;
		}
		*lst = NULL;
	}
}
