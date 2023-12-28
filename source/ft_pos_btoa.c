/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_btoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:41:31 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/28 19:05:57 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_btoa(t_stacks *ab, int value_b)
{
	int	index_a;
	int	high_index_a;

	high_index_a = ft_high_index_a(ab);
	index_a = ft_low_index_a(ab);
	if (value_b > ft_clst_value(*ab->a, high_index_a))
		return (index_a);
	while (value_b > ft_clst_value(*ab->a, index_a))
	{
		index_a--;
		if (index_a == 0)
			index_a = ab->size_a;
	}
	return (index_a);
}
