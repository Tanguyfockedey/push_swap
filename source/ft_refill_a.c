/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refill_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:55:28 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/28 19:48:54 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
void	ft_refill_a(t_stacks *ab)
{
	while (ab->size_b)
	{
		if ((*ab->b)->prev->nbr > (*ab->a)->nbr)
			if ((*ab->b)->prev->nbr < (*ab->a)->prev->nbr)
				ft_push(ab, 'a');
			else
				if ((*ab->a)->nbr < (*ab->a)->prev->nbr)
					if ((*ab->b)->prev->nbr < (*ab->a)->prev->prev->nbr)
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
*/

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
//	ft_printf("rotate = %d\n", rotate);//
	ft_check_rotate(ab, &rotate, &small_index, &sign);
	ft_check_rrotate(ab, &rotate, &small_index, &sign);
//	ft_printf("small_index = %d   sign = %d   rotate = %d\n", small_index, sign, rotate);//
	ft_push_btoa(ab, small_index, sign);
//	ft_clst_print_stacks(ab);//
}
