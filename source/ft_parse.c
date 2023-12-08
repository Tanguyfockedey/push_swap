/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:26:17 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/08 17:30:13 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**ft_tab(int argc, char **argv)
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

void	ft_tab_free(char **argv)
{
	int	i;

	i = -1;
	while (argv[++i])
		free(argv[i]);
	free(argv);
}

int	ft_error(t_clst **a, int argc, char **argv)
{
	if (argc == 2)
		ft_tab_free(argv);
	ft_clst_free(a);
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	ft_fill_a(char **argv, t_clst **a)
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
			ft_clst_add(a, new);
		}
		else
			return (0);
	}
	return (1);
}

int	ft_parse(int argc, char **argv, t_clst **a)
{
	argv = ft_tab(argc, argv);
	if (!argv)
		return (0);
	if (!ft_fill_a(argv, a))
	{
		ft_error(a, argc, argv);
		return (0);
	}
	if (!ft_clst_check_dup(a))
	{
		ft_error(a, argc, argv);
		return (0);
	}
	if (argc == 2)
		ft_tab_free(argv);
	return (1);
}
