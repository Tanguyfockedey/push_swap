/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:28:48 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/15 18:11:38 by tafocked         ###   ########.fr       */
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

void	ft_push(t_stacks *stacks, char c)
{
	if (c == 'a')
	{
		if (!stacks->b)
			return ;
		ft_push_op(stacks->b, stacks->a);
		ft_printf("pa\n");
		stacks->size_a++;
		stacks->size_b--;
	}
	if (c == 'b')
	{
		if (!stacks->a)
			return ;
		ft_push_op(stacks->a, stacks->b);
		ft_printf("pb\n");
		stacks->size_a--;
		stacks->size_b++;
	}
}
