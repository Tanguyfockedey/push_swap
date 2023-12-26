/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_atob.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:29:48 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 15:30:09 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_atob(t_stacks *ab, int value_a)
{
	int	index_b;
	int	low_index_b;

	low_index_b = ft_low_index_b(ab);
	index_b = ft_high_index_b(ab);
	if (value_a < ft_clst_value(*ab->b, low_index_b))
		return (index_b);
	while (value_a < ft_clst_value(*ab->b, index_b))
	{
		index_b--;
		if (index_b == 0)
			index_b = ab->size_b;
	}
	return (index_b);
}
