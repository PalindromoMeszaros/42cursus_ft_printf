/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pablomar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 19:04:50 by pablomar          #+#    #+#             */
/*   Updated: 2019/11/18 19:57:34 by pablomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *aux;

	if (alst && *alst && new)
	{
		aux = *alst;
		while (aux->next)
			aux = aux->next;
		aux->next = new;
	}
	else if (*alst == NULL)
		*alst = new;
}
