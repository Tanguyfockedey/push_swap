/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 18:14:28 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 20:34:53 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_three(t_clst **lst, char ch)
{
	t_clst	a;
	t_clst	b;
	t_clst	c;

	a = **lst;
	b = *(*lst)->next;
	c = *(*lst)->next->next;
	if (a.nbr < b.nbr && b.nbr < c.nbr)
		ft_swap(lst, ch);
	if (c.nbr < a.nbr && a.nbr < b.nbr)
		ft_swap(lst, ch);
	if (b.nbr < c.nbr && c.nbr < a.nbr)
		ft_swap(lst, ch);
}
