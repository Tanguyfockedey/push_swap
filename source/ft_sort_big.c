/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:07:13 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/15 18:49:49 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


ft_count_atob()
{

}

ft_fill_b(t_stacks *stacks)
{
	int	count;
	int	index;
	int	small_index;

	index = 1;
	small_index = index;
	count = ft_count_atob(stacks, stacks->size_a - index + 1);
	while (count--)
	{
		if 
	}
}

ft_sort_big(t_stacks *stacks)
{
	while (stacks->size_a > 3)
	{
		if (stacks->size_b < 2)
			ft_push(stacks, 'b');
		else
			ft_fill_b(stacks);
	}
	ft_sort_three(stacks->a, 'a');
	if (stacks->size_b)
		ft_refill_a(stacks);
	//rotate smallest on top
}
