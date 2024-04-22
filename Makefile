NAME = cub3d
SRCDIR = src
OBJDIR = obj

RM = rm -rf
CC = cc
MLdir_x = ./mlx
SRCS = $(addprefix $(SRCDIR)/, check_map.c	drawing.c	init.c	parsing.c	utils.c\
								color_utils.c	error.c	is_enclosed_nswe.c	raycast.c	utils_p.c\
								game.c	main.c	texture_color_checks.c floor_ceiling.c orient.c	move_rotate.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft
LIBFTA = $(LIBFT)/libft.a
LIBS = -L$(LIBFT) -lft
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -L$(MLdir_x)
HEADER = $(SRCDIR)/cub3d.h

MLX		=	$(MLdir_x)libmlx.a
MLdir_x =	./mlx/
MLX_HEADERS = $(MLdir_x)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS) $(LIBFTA) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

$(MLX):
	$(MAKE) -sC $(MLdir_x)

$(LIBFTA):
	@$(MAKE) -C $(LIBFT)

clean:
	$(RM) $(OBJS)
	$(RM) $(OBJDIR)
	@$(MAKE) -sC $(MLdir_x) clean
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	$(RM) $(MLX)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re