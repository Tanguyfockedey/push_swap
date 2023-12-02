/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 21:31:15 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/02 21:47:04 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clst_free(t_clst **lst)
{
	t_clst	*cell;

	if (!lst || !(*lst))
		return ;
	while ((*lst)->next != *lst)
	{
		cell = (*lst)->next;
		(*lst)->next = cell->next;
		free(cell);
	}
	free(*lst);
}
