/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:12:47 by tafocked          #+#    #+#             */
/*   Updated: 2023/12/04 18:10:22 by tafocked         ###   ########.fr       */
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
	long			nbr;
	long			index;
}	t_clst;

t_clst	*ft_clst_new(int nbr);
void	ft_clst_add(t_clst **lst, t_clst *new);
void	ft_clst_free(t_clst **lst);
void	ft_clst_print(t_clst **lst);
int	parse(int argc, char **argv, t_clst **a);


#endif
