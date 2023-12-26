/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refill_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:55:28 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 21:33:28 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_refill_a(t_stacks *ab)
{
	while (ab->size_b)
	{
		if ((*ab->b)->prev->nbr > (*ab->a)->nbr)
			if ((*ab->b)->prev->nbr < (*ab->a)->prev->nbr)
				ft_push(ab, 'a');
			else 
				if ((*ab->a)->nbr < (*ab->a)->prev->nbr)
					if	((*ab->b)->prev->nbr < (*ab->a)->prev->prev->nbr)
						ft_rotate(ab->a, 'a');
					else
						ft_rrotate(ab->a, 'a');
				else
					ft_push(ab, 'a');
		else
			if ((*ab->b)->prev->nbr < (*ab->a)->prev->nbr)
				if ((*ab->a)->nbr < (*ab->a)->prev->nbr)
					ft_rrotate(ab->a, 'a');
				else
					ft_push(ab, 'a');
			else
				ft_rrotate(ab->a, 'a');
	}
}
