/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:48:03 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 17:18:52 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_clst **lst)
{
	*lst = (*lst)->next;
}

void	ft_rr(t_clst **a, t_clst **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

void	ft_rrotate(t_clst **lst)
{
	*lst = (*lst)->prev;
}

void	ft_rrr(t_clst **a, t_clst **b)
{
	ft_rrotate(a);
	ft_rrotate(b);
}
