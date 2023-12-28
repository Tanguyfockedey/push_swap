# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 18:09:37 by tafocked          #+#    #+#              #
#    Updated: 2023/12/28 22:00:55 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

FILES	= source/ft_clst_add.c \
			source/ft_clst_check_dup.c \
			source/ft_clst_free.c \
			source/ft_clst_issorted.c \
			source/ft_clst_new.c \
			source/ft_clst_size.c \
			source/ft_clst_value.c \
			source/ft_fill_b.c \
			source/ft_init.c \
			source/ft_int_arg.c \
			source/ft_parse.c \
			source/ft_pos_atob.c \
			source/ft_pos_btoa.c \
			source/ft_push_atob.c \
			source/ft_push_btoa.c \
			source/ft_refill_a.c \
			source/ft_sort_big.c \
			source/ft_sort_three.c \
			source/high_low_index.c \
			source/push_swap.c \
			source/push.c \
			source/rotate.c \
			source/swap.c \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
LDLIBS	= includes/libft_updated/libft.a
OBJ		= $(FILES:.c=.o)

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@ $(MAKE) -C includes/libft_updated
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C includes/libft_updated

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C includes/libft_updated

.PHONY: all re clean fclean