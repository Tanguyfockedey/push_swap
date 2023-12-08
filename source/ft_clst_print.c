/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:31:21 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/08 17:00:12 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_clst_print(t_clst **lst)
{
	t_clst	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	ft_printf("nbr = %d\n", tmp->nbr);
//	ft_printf("index = %d\n", tmp->index);
//	ft_printf("addr = %p\n", tmp);
//	ft_printf("next = %p\n", tmp->next);
//	ft_printf("prev = %p\n\n", tmp->prev);
	while (tmp->next != *lst)
	{
		tmp = tmp->next;
		ft_printf("nbr = %d\n", tmp->nbr);
//		ft_printf("index = %d\n", tmp->index);
		ft_printf("addr = %p\n", tmp);
//		ft_printf("next = %p\n", tmp->next);
//		ft_printf("prev = %p\n\n", tmp->prev);
	}
}
