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
LIBFT_OBJS = \
	Libft/ft_atoi.c Libft/ft_bzero.c Libft/ft_calloc.c Libft/ft_isalnum.c \
	Libft/ft_isalpha.c Libft/ft_isascii.c Libft/ft_isdigit.c Libft/ft_isprint.c \
	Libft/ft_itoa.c Libft/ft_memchr.c Libft/ft_memcmp.c \
	Libft/ft_memcpy.c Libft/ft_memmove.c Libft/ft_memset.c Libft/ft_putchar_fd.c \
	Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c Libft/ft_putstr_fd.c Libft/ft_split.c \
	Libft/ft_strchr.c Libft/ft_strdup.c Libft/ft_strjoin.c Libft/ft_strlcat.c \
	Libft/ft_strlcpy.c Libft/ft_strlen.c Libft/ft_strmapi.c Libft/ft_strncmp.c \
	Libft/ft_strnstr.c Libft/ft_strrchr.c Libft/ft_strtrim.c Libft/ft_substr.c \
	Libft/ft_tolower.c Libft/ft_toupper.c Libft/ft_lstadd_back.c Libft/ft_lstadd_front.c \
	Libft/ft_lstclear.c Libft/ft_lstdelone.c Libft/ft_lstiter.c Libft/ft_lstlast.c \
	Libft/ft_lstmap.c Libft/ft_lstnew.c Libft/ft_lstsize.c 
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