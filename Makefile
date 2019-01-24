# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 09:31:54 by jmartel           #+#    #+#              #
#    Updated: 2019/01/24 12:30:48 by jmartel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBPATH	= .
LIBNAME	= libftprintf.a

NAME	= libunit-test

SRCS	+= ./main.c
SRCS	+= 	./di/00_launcher.c ./di/01_di_basic1.c ./di/02_di_basic2.c ./di/03_di_basic3.c ./di/04_di_basic4.c ./di/05_di_basic5.c ./di/06_di_cast1.c ./di/07_di_cast2.c ./di/08_di_cast3.c ./di/09_di_cast4.c ./di/10_di_hard1.c
SRCS	+=	./xX/00_launcher.c ./xX/01_basic1.c ./xX/02_basic2.c ./xX/03_basic3.c ./xX/04_basic4.c ./xX/05_cast1.c ./xX/06_cast2.c ./xX/07_cast3.c
SRCS	+=	./f/00_launcher.c ./f/01_basic1.c ./f/02_basic2.c ./f/03_basic3.c ./f/04_basic4.c ./f/05_basic5.c ./f/06_special1.c ./f/07_special2.c
SRCS	+= 	./c/00_launcher.c ./c/01_c_basic1.c ./c/02_c_basic2.c ./c/03_c_basic3.c ./c/04_percent.c
SRCS	+= ./prec/00_launcher.c ./prec/01_nullprec1.c ./prec/02_bigprec1.c ./prec/03_bigprec2.c ./prec/04_bigprec3.c ./prec/05_nullprec2.c ./prec/06_nullprec3.c ./prec/07_nullprec4.c ./prec/08_nullprec5.c
SRCS	+= 	./u/00_launcher.c ./u/01_u_basic1.c ./u/02_u_basic2.c ./u/03_u_basic3.c ./u/04_u_basic4.c ./u/05_u_basic5.c
SRCS	+= 	./o/00_launcher.c ./o/01_o_basic1.c ./o/02_o_basic2.c ./o/03_o_basic3.c ./o/04_o_basic4.c ./o/05_o_basic5.c
SRCS	+= 	./p/00_launcher.c ./p/01_p_basic1.c ./p/02_p_basic2.c ./p/03_p_basic3.c ./p/04_p_basic4.c ./p/05_p_basic5.c
SRCS	+= 	./s/00_launcher.c ./s/01_s_basic1.c ./s/02_s_basic2.c ./s/03_s_basic3.c ./s/04_s_basic4.c ./s/05_s_basic5.c
SRCS	+=	./segf/00_launcher.c ./segf/01_segf1.c ./segf/02_segf2.c ./segf/03_segf3.c ./segf/04_segf4.c ./segf/05_segf5.c
SRCS	+=	./return/00_launcher.c ./return/01_return1.c ./return/02_return2.c ./return/03_hard1.c
SRCS	+=	./multiargs/00_launcher.c ./multiargs/01_multiargs1.c ./multiargs/02_multiargs2.c

OBJ		= $(SRCS:.c=.o)

HEADER	= ./ft_printf_test.h

INCLUDES= -I ./ -I ./framework/

FRAMEW	= ./framework/libunit.a

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra $(INCLUDES)

.PHONY	: all clean fclean re test

all: cp $(NAME)

cp:
	@rm -f $(LIBNAME)
	@make -C $(LIBPATH) all
	@cp $(LIBPATH)$(LIBNAME) .
	@if [ -a $(LIBNAME) ]; then echo "\033[32mSuccessfully copied your $(LIBNAME) \033[0m"; else echo "\033[30mCannot copy your $(LIBNAME) check LIBPATH and LIBNAME variables\033[0m"; fi

$(NAME): $(OBJ) $(LIBNAME)
	@make -C ./framework all
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJ) $(FRAMEW) $(LIBNAME) && echo "\033[32mSuccessfully compiled $(NAME) \033[0m"

sanitize: $(OBJ) $(LIB)
	@for i in $(LIBDIR); do (make -C $$i all); done
	@$(CC) -o $(NAME) $(CFLAGS) -g3 -fsanitize=address  $(SRCS) $(LIBFLAG) libftprintf.a && echo "\033[32mSuccessfully compiled $(NAME) \033[0m"

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

frameworkre:
	make -C ./framework re

printfre:
	make -C $(LIBPATH) re

clean:
	@rm -f $(OBJ) && echo "\033[32mObjects files have been deleted\033[0m"

fclean: clean
	@rm -f $(NAME) && echo "\033[32m$(NAME) have been deleted\033[0m"
	@rm -f $(LIBNAME) && echo "\033[32m$(LIBNAME) have been deleted\033[0m"

re: fclean frameworkre printfre cp $(NAME)

test: all
	./$(NAME)
