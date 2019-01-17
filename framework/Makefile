# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 09:31:54 by jmartel           #+#    #+#              #
#    Updated: 2018/12/01 15:10:58 by jmartel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libunit.a

SRCS	= ./libunit.c ./libunit_display.c ./libunit_library.c
OBJ		= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRCS) $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)