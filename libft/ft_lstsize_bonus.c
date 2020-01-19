/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltsize_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:25:29 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/19 13:35:03 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		lst_size;
	t_list	*aux;

	lst_size = 0;
	aux = lst;
	if (!aux)
		return (0);
	while (aux->next != NULL)
	{
		lst_size++;
		aux = aux->next;
	}
	if (aux->next == NULL)
		lst_size++;
	return (lst_size);
}
