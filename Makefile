CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = push_swap.c utils.c rules.c sort.c
LIB = LIBFT

OBJ = $(SRC:.c=.o)

all: $(NAME)
	@echo "all done"

$(NAME): $(OBJ)
	@make -C $(LIB)
	@$(CC) $(CFLAGS) $(OBJ) -L$(LIB) -lft -o $(NAME)
	
$(OBJ):
	@$(CC) $(CFLAGS) -c $(SRC)

clean:
	@rm -rf $(OBJ)
	@make clean -C $(LIB)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB)
	@echo "$(NAME) deleted"

re: fclean all
.PHONY: clean all re fclean