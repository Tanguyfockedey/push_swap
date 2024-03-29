/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:03:14 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 15:12:02 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_clst_size(t_clst **lst)
{
	int		i;
	t_clst	*tmp;

	if (!*lst)
		return (0);
	if ((*lst)->next == *lst)
		return (1);
	i = 0;
	tmp = *lst;
	while (tmp != *lst || i == 0)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
