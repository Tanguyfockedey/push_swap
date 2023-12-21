/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:48:03 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/21 17:13:51 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_clst **lst, char c)
{
	*lst = (*lst)->prev;
	if (c == 'a')
		ft_printf("ra\n");
	if (c == 'b')
		ft_printf("rb\n");
}

void	ft_rr(t_clst **a, t_clst **b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	ft_printf("rr\n");
}

void	ft_rrotate(t_clst **lst, char c)
{
	*lst = (*lst)->next;
	if (c == 'a')
		ft_printf("rra\n");
	if (c == 'b')
		ft_printf("rrb\n");
}

void	ft_rrr(t_clst **a, t_clst **b)
{
	ft_rrotate(a, 0);
	ft_rrotate(b, 0);
	ft_printf("rrr\n");
}
