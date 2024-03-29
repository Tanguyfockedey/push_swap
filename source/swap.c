/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:08:58 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 18:58:50 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_clst **lst, char c)
{
	t_clst	*last;
	t_clst	*swap;

	if (!(*lst) || (*lst)->prev == *lst)
		return ;
	if ((*lst)->prev->prev == *lst)
		ft_rotate(lst, 0);
	else
	{
		last = (*lst)->prev;
		swap = last->prev;
		swap->prev->next = last;
		last->prev = swap->prev;
		last->next = swap;
		swap->prev = last;
		swap->next = *lst;
		(*lst)->prev = swap;
	}
	if (c == 'a')
		ft_printf("sa\n");
	if (c == 'b')
		ft_printf("sb\n");
}

void	ft_ss(t_clst **a, t_clst **b)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	ft_printf("ss\n");
}
