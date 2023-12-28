/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:07:13 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/28 21:31:15 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(t_stacks *ab)
{
	int	high_val_a;

	while (ab->size_a > 3)
	{
		if (ab->size_b < 2)
			ft_push(ab, 'b');
		else
			ft_fill_b(ab);
	}
	ft_sort_three(ab->a, 'a');
	while (ab->size_b)
		ft_refill_a(ab);
	high_val_a = ft_clst_value(*ab->a, ft_high_index_a(ab));
	if (ft_high_index_a(ab) >= ab->size_a + 1 / 2)
		while ((*ab->a)->nbr != high_val_a)
			ft_rotate(ab->a, 'a');
	else
		while ((*ab->a)->nbr != high_val_a)
			ft_rrotate(ab->a, 'a');
}
