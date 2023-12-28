/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refill_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:55:28 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/28 21:31:04 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_first_btoa(t_stacks *ab, int value_a)
{
	int	pos;

	pos = ft_pos_btoa(ab, value_a);
	if (ab->size_a - pos < pos)
		return (ab->size_a - pos);
	else
		return (pos);
}

static void	ft_check_rotate(t_stacks *ab, int *rotate, int *small_i, int *sign)
{
	int	i;
	int	pos;

	i = 1;
	while (i < *rotate && i < ab->size_b / 2)
	{
		pos = ft_pos_btoa(ab, ft_clst_value(*ab->b, ab->size_b - i));
		if (pos + i < *rotate)
		{
			*rotate = pos + i;
			*small_i = ab->size_b - i;
			*sign = -1;
		}
		if (ab->size_a - pos < *rotate)
		{
			if (ab->size_a - pos > i)
				*rotate = ab->size_a - pos;
			else
				*rotate = i;
			*small_i = ab->size_b - i;
			*sign = -1;
		}
		i++;
	}
}

static void	ft_check_rrotate(t_stacks *ab, int *rotate, int *small_i, int *sign)
{
	int	i;
	int	pos;

	i = 1;
	while (i < *rotate && i < ab->size_b / 2)
	{
		pos = ft_pos_btoa(ab, ft_clst_value(*ab->b, i));
		if (ab->size_a - pos + i < *rotate)
		{
			*rotate = ab->size_a - pos + i;
			*small_i = i;
			*sign = 1;
		}
		if (pos < *rotate)
		{
			if (pos > i)
				*rotate = pos;
			else
				*rotate = i;
			*small_i = i;
			*sign = 1;
		}
		i++;
	}
}

void	ft_refill_a(t_stacks *ab)
{
	int	rotate;
	int	small_index;
	int	sign;

	sign = 0;
	small_index = ab->size_b;
	rotate = ft_first_btoa(ab, ft_clst_value(*ab->b, ab->size_b));
	ft_check_rotate(ab, &rotate, &small_index, &sign);
	ft_check_rrotate(ab, &rotate, &small_index, &sign);
	ft_push_btoa(ab, small_index, sign);
}
