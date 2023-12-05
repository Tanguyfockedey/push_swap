/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:03:14 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/05 17:15:22 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_clst_size(t_clst **a)
{
	int	i;
	t_clst *tmp;

	if (!*a)
		return (0);
	if ((*a)->next == *a)
		return (1);
	i = 0;
	tmp = *a;
	while (tmp != *a || i == 0)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
