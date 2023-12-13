/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:08:58 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 15:28:37 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_clst **lst)
{
	t_clst	*last;
	t_clst	*swap;

	if (!(*lst))
		return ;
	last = (*lst)->prev;
	swap = last->prev;
	last->prev = swap->prev;
	last->next = swap;
	swap->prev = last;
	swap->next = (*lst);
}

void	ft_ss(t_clst **a, t_clst **b)
{
	ft_swap(a);
	ft_swap(b);
}
