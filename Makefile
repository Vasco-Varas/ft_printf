# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vascovaras <vascovaras@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/03 22:30:54 by bsouchet          #+#    #+#              #
#    Updated: 2019/03/16 12:42:30 by vascovaras       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -O3 -Wall -Werror -Wextra
AR = ar rc
NAME = libftprintf.a
HEADER = libftprintf.h
FILES = sp.c fo.c helpers.c d_ex.c xx.c x.c b.c pers.c u.c d.c pf_helper1.c pf_helper2.c pf_helper3.c pf_helper4.c pf_helper5.c pf_helper6.c pf_helper7.c pf_helper8.c pf_helper9.c ft_specifier_helper.c ft_atoi.c ft_bzero.c ft_isdigit.c ft_memset.c ft_printf.c ft_strlen.c ft_strncmpcolor.c fconv.c ft_strncmp.c ft_colors.c ft_specifier.c ft_itoa.c ft_strdup.c vextra.c ft_memalloc.c ft_strcpy.c c.c fconvextra.c fconvextra2.c fconvextra3.c fconvextra4.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) :
	@echo Compiling: $(NAME)
	@echo "\t"- Compiler: $(CC)
	@echo "\t"- Flags: $(FLAGS)
	@$(CC) $(FLAGS) -c $(FILES) 
	@$(AR) $(NAME) $(OBJ)
	@ranlib $(NAME)

clean :
	@echo clean:"\n\tTemporary and binary files deteleted"
	@rm -f *.o

fclean : clean
	@echo fclean:"\n\t" $(NAME) deleted
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
