# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gnaida <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/16 13:16:43 by gnaida            #+#    #+#              #
#    Updated: 2021/06/16 13:17:07 by gnaida           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = 		ft_printf.c\
			parse_flags_1.c\
			parse_flags_2.c\
			process_types_ft_1.c\
			process_types_ft_2.c\
			process_char_str_perc.c\
			process_ptr.c\
			process_ints.c\
			process_hexs.c

LIST_B = 

FLAGS = -Wall -Wextra -Werror -include ft_printf.h

OBJ	= ${LIST:.c=.o}

OBJ_B = ${LIST_B:.c=.o}

all: $(NAME)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	ar rcs $(NAME) $(OBJ) $(OBJ_B)

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean: 
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY: all clean fclean re bomus
