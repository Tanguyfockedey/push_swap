/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:07:13 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/21 21:09:27 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_pos_atob(t_stacks *stacks, int value_a)
{
	int	index_b;
	int	low_index_b;

	low_index_b = ft_low_index_b(stacks);
	index_b = ft_high_index_b(stacks);
	if (value_a < ft_clst_value(*stacks->b, low_index_b))
		return (index_b);
	while (value_a < ft_clst_value(*stacks->b, index_b))
	{
		index_b--;
		if (index_b == 0)
			index_b = stacks->size_b;
	}
	return (index_b);
}

int	ft_first_atob(t_stacks *stacks, int value_a)
{
	int	pos;

	pos = ft_pos_atob(stacks, value_a);
	if (stacks->size_b - pos < pos)
		return (stacks->size_b - pos);
	else
		return (pos);
}

void	ft_check_rotate(t_stacks *stacks, int *rotate, int *small_index, int *sign)
{
	int	i;
	int	pos;

	i = 1;
	while (i < *rotate)
	{
		pos = ft_pos_atob(stacks, ft_clst_value(*stacks->a, stacks->size_a - i));
		if (pos + i < *rotate)
		{
			*rotate = pos + i;
			*small_index = stacks->size_a - i;
			*sign = -1;
		}
		if (stacks->size_b - pos < *rotate)
		{
			if (stacks->size_b - pos > i)
				*rotate = stacks->size_b - pos;
			else
				*rotate = i;
			*small_index = stacks->size_a - i;
			*sign = -1;
		}
//		if (*small_index < *rotate)
//			*rotate = *small_index;
		i++;
	}
}

void	ft_check_rrotate(t_stacks *stacks, int *rotate, int *small_index, int *sign)
{
	int	i;
	int	pos;

	i = 1;
	while (i < *rotate)
	{
		pos = ft_pos_atob(stacks, ft_clst_value(*stacks->a, i));
		if (stacks->size_b - pos + i < *rotate)
		{
			*rotate = stacks->size_b - pos + i;
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
//		if (*small_index < *rotate)
//			*rotate = *small_index;
		i++;
	}
}

void	ft_rotate_a(t_stacks *stacks, int index_a)
{
	if (index_a > stacks->size_a / 2)
		while (index_a++ < stacks->size_a)
			ft_rotate(stacks->a, 'a');
	else
		while (index_a--)
			ft_rrotate(stacks->a, 'a');
}

void	ft_rotate_b(t_stacks *stacks, int index_b)
{
	if (index_b > stacks->size_b / 2)
		while (index_b++ < stacks->size_b)
			ft_rotate(stacks->b, 'b');
	else
		while (index_b--)
			ft_rrotate(stacks->b, 'b');
}

void	ft_rotate_ab(t_stacks *stacks, int index_a, int index_b)
{
	if (index_b <= stacks->size_b / 2)
	{
		ft_rotate_a(stacks, index_a);
		ft_rotate_b(stacks, index_b);
	}	
	else
	{
		if (stacks->size_a - index_a < stacks->size_b - index_b)
		{
			while (index_a++ < stacks->size_a)
			{
				ft_rr(stacks->a, stacks->b);
				index_b++;
			}
			ft_rotate_b(stacks, index_b);
		}
		else
		{
			while (index_b++ < stacks->size_b)
			{
				ft_rr(stacks->a, stacks->b);
				index_a++;
			}
			ft_rotate_a(stacks, index_a);
		}
	}
}

void	ft_rrotate_ab(t_stacks *stacks, int index_a, int index_b)
{
	if (index_b >= stacks->size_b / 2)
	{
		ft_rotate_a(stacks, index_a);
		ft_rotate_b(stacks, index_b);
	}	
	else
	{
		if (index_a < index_b)
		{
			while (index_a--)
			{
				ft_rrr(stacks->a, stacks->b);
				index_b--;	
			}
			ft_rotate_b(stacks, index_b);
		}
		else
		{
			while (index_b--)
			{
				ft_rrr(stacks->a, stacks->b);
				index_a--;
			}
			ft_rotate_a(stacks, index_a);
		}
	}
}

void	ft_push_atob(t_stacks *stacks, int index_a, int sign)
{
	int	index_b;

	index_b = ft_pos_atob(stacks, ft_clst_value(*stacks->a, index_a));
	if (sign == 0)
		ft_rotate_b(stacks, index_b);
	if (sign == -1)
		ft_rotate_ab(stacks, index_a, index_b);
	if (sign == 1)
		ft_rrotate_ab(stacks, index_a, index_b);
	ft_push(stacks, 'b');
}

void	ft_fill_b(t_stacks *stacks)
{
	int	rotate;
	int	small_index;
	int	sign;

	ft_clst_print_stacks(stacks);
	
	sign = 0;
	small_index = stacks->size_a;
	rotate = ft_first_atob(stacks, ft_clst_value(*stacks->a, stacks->size_a));
	ft_check_rotate(stacks, &rotate, &small_index, &sign);
	ft_check_rrotate(stacks, &rotate, &small_index, &sign);
	ft_printf("index = %d, rotate = %d, sign = %d\n", small_index, rotate, sign);
	ft_push_atob(stacks, small_index, sign);
}

void	ft_sort_big(t_stacks *stacks)
{
	while (stacks->size_a > 3)
	{
		if (stacks->size_b < 2)
			ft_push(stacks, 'b');
		else
			ft_fill_b(stacks);
	}
	ft_clst_print_stacks(stacks);
	ft_sort_three(stacks->a, 'a');
	ft_printf("sort three\n");
//	if (stacks->size_b)
//		ft_refill_a(stacks);
	//rotate smallest on top
}
