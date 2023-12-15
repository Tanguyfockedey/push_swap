/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:25:24 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/15 17:37:11 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_stacks *stacks)
{
	stacks->point_a = 0;
	stacks->point_b = 0;
	stacks->a = &(stacks->point_a);
	stacks->b = &(stacks->point_b);
	stacks->size_a = 0;
	stacks->size_b = 0;
}
