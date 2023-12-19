/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:07:13 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/19 20:08:54 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first_atob(t_stacks *stacks, int value_a)
{
	int	pos;

	pos = ft_pos_atob(stacks, value_a);
	if (stacks->size_b - pos < pos)
		return (stacks->size_b - pos);
	else
		return (pos);
}

int	ft_check_rotate(t_stacks *stacks, int *rotate, int *small_index)
{
	int	i;
	int	pos;

	i = 1;
	while (i < *rotate)
	{
		pos = ft_pos_atob(stacks, ft_clst_value(*stacks->a, i));
		if (pos + i < *rotate)
		{
			*rotate = pos + i;
			*small_index = stacks->size_a - i;
		}
		if (stacks->size_b - pos < *rotate)
		{
			if (stacks->size_b - pos > i)
				*rotate = stacks->size_b - pos;
			else
				*rotate = i;
			*small_index = stacks->size_a - i;
		}
		if (small_index < rotate)
			rotate = small_index;
		i++;
	}
}
int	ft_check_rrotate(t_stacks *stacks, int *rotate, int *small_index)
{
	int	i;
	int	pos;

	i = 1;
	while (i < *rotate)
	{
		pos = ft_pos_atob(stacks, ft_clst_value(*stacks->a, stacks->size_a - i));
		if (stacks->size_b - pos < *rotate)
		{
			*rotate = stacks->size_b - pos + i;
			*small_index = i;
		}
		if (pos < *rotate)
		{
			if (pos > i)
				*rotate = pos;
			else
				*rotate = i;
			*small_index = i;
		}
		if (small_index < rotate)
			rotate = small_index;
		i++;
	}
}

int	ft_pos_atob(t_stacks *stacks, int value_a)
{
	int	index_b;

	index_b = ft_high_index_b(stacks);
	while (value_a < ft_clst_value(*stacks->b, index_b))
	{
		index_b--;
		if (index_b == 0)
			index_b = stacks->size_b;
	}
	return (index_b);
}

void	ft_fill_b(t_stacks *stacks)
{
	int	rotate;
	int	small_index;
	int	tmp_rot;

	small_index = stacks->size_a;
	rotate = ft_first_atob(stacks, ft_clst_value(*stacks->a, stacks->size_a));
	ft_check_rotate(stacks, &rotate, &small_index);
	ft_check_rrotate(stacks, &rotate, &small_index);

}
/*
void	ft_sort_big(t_stacks *stacks)
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
*/