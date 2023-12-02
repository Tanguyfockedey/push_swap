/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:35:11 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/02 21:05:19 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clstadd(t_clst **a, t_clst *new)
{
	t_clst	*tmp;

	if (!a || !new)
		return ;
	if (*a == 0)
		*a = new;
	else
		{
			tmp = (*a)->prev;
			tmp->next = new;
			new->next = *a;
			new->prev = tmp;
			(*a)->prev = new;
		}
}
