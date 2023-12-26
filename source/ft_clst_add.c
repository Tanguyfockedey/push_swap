/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:35:11 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 18:38:16 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clst_add(t_clst **lst, t_clst *new)
{
	t_clst	*tmp;

	if (!lst || !new)
		return ;
	if (*lst == 0)
		*lst = new;
	else
	{
		tmp = (*lst)->prev;
		tmp->next = new;
		new->next = *lst;
		new->prev = tmp;
		(*lst)->prev = new;
		*lst = new;
	}
}
