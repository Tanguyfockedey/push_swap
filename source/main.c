/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:14:38 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/13 17:51:09 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_clst	**a;
	t_clst	**b;
	t_clst	*point_a;
	t_clst	*point_b;

	point_a = 0;
	point_b = 0;
	a = &point_a;
	b = &point_b;

	if (!ft_parse(argc, argv, a))
		return (1);
	
	ft_clst_print_ab(a, b);

//	ft_printf("clist size = %d\n", ft_clst_size(a));
//	if (ft_clst_issorted(a))
//		ft_printf("list is sorted\n");
//	else
//		ft_printf("list is NOT sorted\n");

	ft_clst_free(a);
	return (0);
}
