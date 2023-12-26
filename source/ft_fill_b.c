/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:27:28 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 16:59:53 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_first_atob(t_stacks *ab, int value_a)
{
	int	pos;

	pos = ft_pos_atob(ab, value_a);
	if (ab->size_b - pos < pos)
		return (ab->size_b - pos);
	else
		return (pos);
}

void	ft_check_rotate(t_stacks *ab, int *rotate, int *small_index, int *sign)
{
	int	i;
	int	pos;

	i = 1;
	while (i < *rotate)
	{
		pos = ft_pos_atob(ab, ft_clst_value(*ab->a, ab->size_a - i));
		if (pos + i < *rotate)
		{
			*rotate = pos + i;
			*small_index = ab->size_a - i;
			*sign = -1;
		}
		if (ab->size_b - pos < *rotate)
		{
			if (ab->size_b - pos > i)
				*rotate = ab->size_b - pos;
			else
				*rotate = i;
			*small_index = ab->size_a - i;
			*sign = -1;
		}
		i++;
	}
}

void	ft_check_rrotate(t_stacks *ab, int *rotate, int *small_index, int *sign)
{
	int	i;
	int	pos;

	i = 1;
	while (i < *rotate)
	{
		pos = ft_pos_atob(ab, ft_clst_value(*ab->a, i));
		if (ab->size_b - pos + i < *rotate)
		{
			*rotate = ab->size_b - pos + i;
			*small_index = i;
			*sign = 1;
		}
		if (pos < *rotate)
		{
			if (pos > i)
				*rotate = pos;
			else
				*rotate = i;
			*small_index = i;
			*sign = 1;
		}
		i++;
	}
}

void	ft_fill_b(t_stacks *ab)
{
	int	rotate;
	int	small_index;
	int	sign;

	sign = 0;
	small_index = ab->size_a;
	rotate = ft_first_atob(ab, ft_clst_value(*ab->a, ab->size_a));
	ft_check_rotate(ab, &rotate, &small_index, &sign);
	ft_check_rrotate(ab, &rotate, &small_index, &sign);
	ft_push_atob(ab, small_index, sign);
}
