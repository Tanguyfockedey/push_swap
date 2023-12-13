/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:28:48 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 18:50:34 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push_op(t_clst **from, t_clst **to)
{
	t_clst	*tmp;

	tmp = (*from)->prev;
	if ((*from)->next == *from)
		*from = 0;
	else
	{
		(*from)->prev = (*from)->prev->prev;
		(*from)->prev->next = *from;
	}
	if (!(*to))
	{
		*to = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->prev = (*to)->prev;
		tmp->next = *to;
		(*to)->prev->next = tmp;
		(*to)->prev = tmp;
	}
}

void	ft_push(t_clst **from, t_clst **to, char c)
{
	if (!(from))
		return ;
	ft_push_op(from, to);
	if (c == 'a')
		ft_printf("pa\n");
	if (c == 'b')
		ft_printf("pb\n");
}
