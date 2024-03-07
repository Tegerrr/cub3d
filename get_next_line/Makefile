NAME = gnl.a
CFLAGS = -Wall -Werror -Wextra
HEADER = get_next_line.h
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:%.c=%.o)

%.o : %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@ 

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ) 

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re