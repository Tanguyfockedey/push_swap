/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:55:28 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 16:59:18 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_fill_a(t_stacks *ab)
{
	while (ab->size_b)
	{
		if ((*ab->b)->prev->nbr > (*ab->a)->nbr)
			ft_push(ab, 'a');
		else if ((*ab->a)->prev->nbr > (*ab->a)->nbr)
			ft_rrotate(ab->a, 'a');
		else
			ft_push(ab, 'a');
	}
}
