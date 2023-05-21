CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRC = push_swap.c utils.c rules.c rules2.c rules3.c sort.c sort2.c sort3.c 
LIB = LIBFT
HEADER = push_swap.h

all: $(NAME)

$(NAME):${SRC} ${HEADER}
	@make -C $(LIB)
	@$(CC) $(CFLAGS) ${SRC} -L$(LIB) -lft -o $(NAME)
	
clean:
	@make clean -C $(LIB)
	@echo "OBJ deleted"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB)
	@echo "$(NAME) deleted"

re: fclean all
.PHONY: clean all re fclean