/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:07:13 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/21 21:57:23 by tafocked         ###   ########.fr       */
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

void	ft_rotate_a(t_stacks *ab, int index_a)
{
	if (index_a > ab->size_a / 2)
		while (index_a++ < ab->size_a)
			ft_rotate(ab->a, 'a');
	else
		while (index_a--)
			ft_rrotate(ab->a, 'a');
}

void	ft_rotate_b(t_stacks *ab, int index_b)
{
	if (index_b > ab->size_b / 2)
		while (index_b++ < ab->size_b)
			ft_rotate(ab->b, 'b');
	else
		while (index_b--)
			ft_rrotate(ab->b, 'b');
}

void	ft_rotate_ab(t_stacks *ab, int index_a, int index_b)
{
	if (index_b <= ab->size_b / 2)
		ft_rotate_a(ab, index_a);
	if (index_b <= ab->size_b / 2)
		ft_rotate_b(ab, index_b);
	else
	{
		if (ab->size_a - index_a < ab->size_b - index_b)
		{
			while (index_a++ < ab->size_a)
			{
				ft_rr(ab->a, ab->b);
				index_b++;
			}
			ft_rotate_b(ab, index_b);
		}
		else
		{
			while (index_b++ < ab->size_b)
			{
				ft_rr(ab->a, ab->b);
				index_a++;
			}
			ft_rotate_a(ab, index_a);
		}
	}
}

void	ft_rrotate_ab(t_stacks *ab, int index_a, int index_b)
{
	if (index_b >= ab->size_b / 2)
		ft_rotate_a(ab, index_a);
	if (index_b >= ab->size_b / 2)
		ft_rotate_b(ab, index_b);
	else
	{
		if (index_a < index_b)
		{
			while (index_a--)
			{
				ft_rrr(ab->a, ab->b);
				index_b--;
			}
			ft_rotate_b(ab, index_b);
		}
		else
		{
			while (index_b--)
			{
				ft_rrr(ab->a, ab->b);
				index_a--;
			}
			ft_rotate_a(ab, index_a);
		}
	}
}

void	ft_push_atob(t_stacks *ab, int index_a, int sign)
{
	int	index_b;

	index_b = ft_pos_atob(ab, ft_clst_value(*ab->a, index_a));
	if (sign == 0)
		ft_rotate_b(ab, index_b);
	if (sign == -1)
		ft_rotate_ab(ab, index_a, index_b);
	if (sign == 1)
		ft_rrotate_ab(ab, index_a, index_b);
	ft_push(ab, 'b');
}

void	ft_fill_b(t_stacks *ab)
{
	int	rotate;
	int	small_index;
	int	sign;

	ft_clst_print_stacks(ab);
	sign = 0;
	small_index = ab->size_a;
	rotate = ft_first_atob(ab, ft_clst_value(*ab->a, ab->size_a));
	ft_check_rotate(ab, &rotate, &small_index, &sign);
	ft_check_rrotate(ab, &rotate, &small_index, &sign);
	ft_printf("index = %d, rotate = %d, sign = %d\n", small_index, rotate, sign);
	ft_push_atob(ab, small_index, sign);
}

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
