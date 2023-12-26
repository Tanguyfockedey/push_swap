/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:25:24 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 15:36:10 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init(t_stacks *ab)
{
	ab->point_a = 0;
	ab->point_b = 0;
	ab->a = &(ab->point_a);
	ab->b = &(ab->point_b);
	ab->size_a = 0;
	ab->size_b = 0;
}
