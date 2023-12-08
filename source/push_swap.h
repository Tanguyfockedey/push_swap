/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/08 17:58:27 by tafocked         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
 #define PUSH_SWAP_H

# include "../includes/libft_updated/libft/libft.h"
# include "../includes/libft_updated/printf/ft_printf.h"

typedef struct s_clst
{
	struct s_clst	*next;
	struct s_clst	*prev;
	int				nbr;
	int				index;
}	t_clst;

void	ft_clst_add(t_clst **lst, t_clst *new);
int		ft_clst_check_dup(t_clst **a);
void	ft_clst_free(t_clst **lst);
int		ft_clst_issorted(t_clst **lst);
t_clst	*ft_clst_new(int nbr);
void	ft_clst_print(t_clst **lst);
int		ft_clst_size(t_clst **a);
int		ft_int_arg(char *str, int *nbr);
int		ft_parse(int argc, char **argv, t_clst **a);


#endif
