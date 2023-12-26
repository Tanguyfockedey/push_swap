/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_new.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:55:49 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 17:21:13 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clst	*ft_clst_new(int nbr)
{
	t_clst	*cell;

	cell = malloc(sizeof(t_clst));
	if (!cell)
		return (0);
	cell->nbr = nbr;
	cell->next = cell;
	cell->prev = cell;
	return (cell);
}
