# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rrakman <rrakman@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 18:40:15 by rrakman           #+#    #+#              #
#    Updated: 2023/05/22 16:18:40 by rrakman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean all re fclean
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SRC = *.c

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "all done"
	
$(NAME):
	@$(CC)  $(CFLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) deleted"

re: fclean all
