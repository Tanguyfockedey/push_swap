# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tafocked <tafocked@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 18:09:37 by tafocked          #+#    #+#              #
#    Updated: 2023/12/05 18:01:48 by tafocked         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

FILES	= source/ft_clst_add.c \
			source/ft_clst_free.c \
			source/ft_clst_new.c \
			source/ft_clst_print.c \
			source/ft_clst_size.c \
			source/ft_parse.c \
			source/ft_valid_arg.c \
			source/main.c \

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g
LDLIBS	= includes/libft_updated/libft.a
OBJ		= $(FILES:.c=.o)

all: libs $(NAME)

re: fclean all

$(NAME):  $(OBJ)
	$(CC) $(CFLAGS) $(LDLIBS) $(OBJ) -o $(NAME)

libs:
	@ $(MAKE) -C includes/libft_updated

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C includes/libft_updated

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C includes/libft_updated

.PHONY: all re clean fclean