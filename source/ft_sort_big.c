/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:07:13 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 15:27:57 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_sort_big(t_stacks *ab)
{
	while (ab->size_a > 3)
	{
		if (ab->size_b < 2)
			ft_push(ab, 'b');
		else
			ft_fill_b(ab);
	}
	ft_clst_print_stacks(ab);
	ft_sort_three(ab->a, 'a');
	ft_printf("sort three\n");
//	if (ab->size_b)
//		ft_refill_a(ab);
	//rotate smallest on top
}
