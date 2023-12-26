/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:14:38 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/26 15:38:44 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_stacks	*ab;
	t_stacks	obj;

	ab = &obj;
	ft_init(ab);
	ft_parse(argc, argv, ab);
	

//	ft_printf("clist size = %d\n", ft_clst_size(a));
//	if (ft_clst_issorted(a))
//		ft_printf("list is sorted\n");
//	else
//		ft_printf("list is NOT sorted\n");
	ft_clst_print_stacks(ab);

	ft_sort_big(ab);
	ft_clst_print_stacks(ab);

	ft_clst_free(ab->a);
	return (0);
}
