/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:26:17 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/15 17:40:53 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**ft_tab(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		if (!argv)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
	}
	else
		argv = &argv[1];
	return (argv);
}

static void	ft_tab_free(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

static void	ft_error(t_clst **a, int argc, char **argv)
{
	if (argc == 2)
		ft_tab_free(argv);
	ft_clst_free(a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	ft_fill_a(char **argv, t_stacks *stacks)
{
	int		i;
	int		nbr;
	t_clst	*new;

	i = -1;
	while (argv[++i])
	{
		if (ft_int_arg(argv[i], &nbr))
		{
			new = ft_clst_new(nbr);
			if (!new)
				return (0);
			ft_clst_add(stacks->a, new);
			stacks->size_a++;
		}
		else
			return (0);
	}
	return (1);
}

void	ft_parse(int argc, char **argv, t_stacks *stacks)
{
	argv = ft_tab(argc, argv);
	if (!argv)
		exit(1);
	if (!ft_fill_a(argv, stacks))
		ft_error(stacks->a, argc, argv);
	if (!ft_clst_check_dup(stacks->a))
		ft_error(stacks->a, argc, argv);
	if (argc == 2)
		ft_tab_free(argv);
}
