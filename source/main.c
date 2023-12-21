/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:14:38 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/21 17:18:23 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	t_stacks	obj;

	stacks = &obj;
	ft_init(stacks);
	ft_parse(argc, argv, stacks);
	

//	ft_printf("clist size = %d\n", ft_clst_size(a));
//	if (ft_clst_issorted(a))
//		ft_printf("list is sorted\n");
//	else
//		ft_printf("list is NOT sorted\n");
	ft_clst_print_stacks(stacks);

	ft_sort_big(stacks);
	ft_clst_print_stacks(stacks);

	ft_clst_free(stacks->a);
	return (0);
}
