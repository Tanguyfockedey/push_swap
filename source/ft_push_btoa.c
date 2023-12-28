/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_btoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:14:04 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/28 19:47:08 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rotate_a(t_stacks *ab, int index_a)
{
	if (index_a > ab->size_a / 2)
		while (index_a++ < ab->size_a)
			ft_rotate(ab->a, 'a');
	else
		while (index_a--)
			ft_rrotate(ab->a, 'a');
}

static void	ft_rotate_b(t_stacks *ab, int index_b)
{
	if (index_b > ab->size_b / 2)
		while (index_b++ < ab->size_b)
			ft_rotate(ab->b, 'b');
	else
		while (index_b--)
			ft_rrotate(ab->b, 'b');
}

static void	ft_rotate_ab(t_stacks *ab, int index_a, int index_b)
{
	if (index_a <= ab->size_a / 2)
		ft_rotate_a(ab, index_a);
	if (index_a <= ab->size_a / 2)
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

static void	ft_rrotate_ab(t_stacks *ab, int index_a, int index_b)
{
	if (index_a >= ab->size_a / 2)
		ft_rotate_a(ab, index_a);
	if (index_a >= ab->size_a / 2)
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

void	ft_push_btoa(t_stacks *ab, int index_b, int sign)
{
	int	index_a;

	index_a = ft_pos_btoa(ab, ft_clst_value(*ab->b, index_b));
	if (sign == 0)
		ft_rotate_a(ab, index_a);
	if (sign == -1)
		ft_rotate_ab(ab, index_a, index_b);
	if (sign == 1)
		ft_rrotate_ab(ab, index_a, index_b);
	ft_push(ab, 'a');
}
