/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   high_low_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:31:48 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/21 21:46:30 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_high_index_b(t_stacks *stacks)
{
	int	i;
	int	high_index;
	int	high_nb;

	i = 1;
	high_index = 1;
	high_nb = ft_clst_value(*stacks->b, i);
	while (i <= stacks->size_b)
	{
		if (ft_clst_value(*stacks->b, i) > high_nb)
		{
			high_nb = ft_clst_value(*stacks->b, i);
			high_index = i;
		}
		i++;
	}
	return (high_index);
}

int	ft_low_index_b(t_stacks *stacks)
{
	int	i;
	int	low_index;
	int	low_nb;

	i = 1;
	low_index = 1;
	low_nb = ft_clst_value(*stacks->b, i);
	while (i <= stacks->size_b)
	{
		if (ft_clst_value(*stacks->b, i) < low_nb)
		{
			low_nb = ft_clst_value(*stacks->b, i);
			low_index = i;
		}
		i++;
	}
	return (low_index);
}
