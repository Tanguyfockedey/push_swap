/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/28 18:38:55 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../includes/libft_updated/libft/libft.h"
# include "../includes/libft_updated/printf/ft_printf.h"

typedef struct s_clst
{
	struct s_clst	*next;
	struct s_clst	*prev;
	int				nbr;
}	t_clst;

typedef struct s_stacks
{
	t_clst	**a;
	t_clst	**b;
	t_clst	*point_a;
	t_clst	*point_b;
	int		size_a;
	int		size_b;
}	t_stacks;

void	ft_clst_add(t_clst **lst, t_clst *new);
int		ft_clst_check_dup(t_clst **a);
void	ft_clst_free(t_clst **lst);
int		ft_clst_issorted(t_clst **lst);
t_clst	*ft_clst_new(int nbr);
void	ft_clst_print_stacks(t_stacks *ab);
int		ft_clst_size(t_clst **a);
int		ft_clst_value(t_clst *lst, int i);
void	ft_fill_b(t_stacks *ab);
void	ft_init(t_stacks *ab);
int		ft_int_arg(char *str, int *nbr);
void	ft_parse(int argc, char **argv, t_stacks *ab);
int		ft_pos_atob(t_stacks *ab, int value_a);
int		ft_pos_btoa(t_stacks *ab, int value_b);
void	ft_push_atob(t_stacks *ab, int index_a, int sign);
void	ft_push_btoa(t_stacks *ab, int index_b, int sign);
void	ft_refill_a(t_stacks *ab);
void	ft_sort_big(t_stacks *ab);
void	ft_sort_three(t_clst **lst, char ch);
int		ft_high_index_a(t_stacks *ab);
int		ft_high_index_b(t_stacks *ab);
int		ft_low_index_a(t_stacks *ab);
int		ft_low_index_b(t_stacks *ab);
void	ft_push(t_stacks *ab, char c);
void	ft_rotate(t_clst **lst, char c);
void	ft_rr(t_clst **a, t_clst **b);
void	ft_rrotate(t_clst **lst, char c);
void	ft_rrr(t_clst **a, t_clst **b);
void	ft_swap(t_clst **lst, char c);
void	ft_ss(t_clst **a, t_clst **b);

void	ft_fill_b(t_stacks *ab);

#endif
