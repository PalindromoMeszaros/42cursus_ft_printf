/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 21:48:00 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/19 15:41:48 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *l, void *(*f)(void *), void (*d)(void *))
{
	t_list	*tmp;

	if (l == NULL)
		return (NULL);
	if ((tmp = ft_lstnew(l->content)) == NULL)
		return (NULL);
	tmp->content = (*f)(tmp->content);
	tmp->next = ft_lstmap(l->next, f, d);
	return (tmp);
}
