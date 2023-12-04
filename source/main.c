/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:14:38 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/04 18:13:19 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int	main(int argc, char **argv)
{
	t_clst	**a;
	//t_clst	*b;
	t_clst	*c;

	(void)argc;
	(void)argv;

	c = 0;
	a = &c;
	//b = ft_clst_new(10);
	//ft_clst_add(a, b);
	//b = ft_clst_new(20);
	//ft_clst_add(a, b);
	//b = ft_clst_new(30);
	//ft_clst_add(a, b);

	if (!parse(argc, argv, a))
		return (1);
	ft_clst_print(a);
	return (0);
}
