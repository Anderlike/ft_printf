# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaleixo- <aaleixo-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 11:29:01 by aaleixo-          #+#    #+#              #
#    Updated: 2024/06/03 19:33:57 by aaleixo-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = \
	ft_printf.c ft_putnbr.c ft_ptr.c
BSOURCES = 
LIBFT_OBJS = $(shell for obj in `ar -t Libft/libft.a`; do echo Libft/$$obj; done)
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS) libft.a
	$(AR) -r $@ $(OBJECTS) $(LIBFT_OBJS)

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -r $(NAME) $?

libft.a:
	make -C ./Libft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean: cleanlib
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f $(NAME)

cleanlib:
	make clean -C ./Libft

re: fclean all

.PHONY: all bonus clean fclean re