#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yli <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 16:32:15 by yli               #+#    #+#              #
#    Updated: 2016/12/17 10:04:27 by nmayfiel         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= fillit
CC			= gcc
CFLAGS		=  -Wall -Wextra -Werror
LDFLAGS 	?= -Llibft/
LDLIBS		?= -lft
CFLAGS		+= -Ilibft/

FILENAMES	= main.c fillit.c verify_input.c errors.c get_pieces.c \
			  fix_piece_offset.c solve_fillit.c
OBJECTS 	= $(FILENAMES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	cd libft && make && make clean
	cd ../
	$(CC) $(LDFLAGS) $(LDLIBS) -o $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	cd libft && make fclean
	cd ../
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
