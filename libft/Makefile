NAME 		=	libft.a
SRCDIR 	=	src
OBJDIR 	=	obj

SRCS 	=	ft_isalnum.c		ft_isascii.c	ft_isprint.c \
				ft_strlcat.c		ft_strlen.c		ft_toupper.c \
				ft_atoi.c			ft_isalpha.c	ft_isdigit.c \
				ft_tolower.c		ft_memset.c		ft_bzero.c \
				ft_memcpy.c			ft_memmove.c	ft_strchr.c \
				ft_strrchr.c		ft_strncmp.c	ft_memchr.c \
				ft_memcmp.c			ft_strnstr.c	ft_strlcat.c \
				ft_strlcpy.c		ft_strdup.c		ft_calloc.c \
				ft_substr.c			ft_strjoin.c	ft_strtrim.c \
				ft_putchar_fd.c		ft_putstr_fd.c	ft_putendl_fd.c \
				ft_putnbr_fd.c		ft_itoa.c		ft_strmapi.c \
				ft_lstsize.c		ft_lstnew.c		ft_lstadd_front.c\
				ft_lstadd_back.c	ft_lstiter.c	ft_lstlast.c\
				ft_lstdelone.c		ft_lstclear.c	ft_lstmap.c\
				ft_striteri.c		ft_split.c		ft_numlen.c

OBJS	=	$(patsubst %.c, obj/%.o, $(SRCS))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

all	:				$(NAME)

$(NAME)	:			$(OBJS)
				@ar rcs $@ $^

obj/%.o	:	$(SRCDIR)/%.c Makefile | obj
				@$(CC) $(CFLAGS) -I . -c $< -o $@

obj	:
				@mkdir -p $@

clean	:
				@rm -rf obj

fclean	:			clean
				@rm -f $(NAME)

re	:				fclean all

.PHONY	:			all clean fclean re
