/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:55:49 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/02 20:43:19 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_clst	*ft_clstnew(int nbr)
{
	t_clst	*cell;

	cell = malloc(sizeof(t_clst));
	if (!cell)
		return (0);
	cell->nbr = nbr;
	cell->index = 0;
	cell->next = cell;
	cell->prev = cell;
	return (cell);
}
