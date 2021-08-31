SRC_LIB		=	./libft
LIBFT		=	libft.a

NAME 	= 	pipex

HD		=	pipex.h

FLAGS	= 	-Wall -Werror -Wextra

SRS		= 	pipex.c		main.c

OBJS	=	$(SRS:.c=.o)

all : 		$(NAME)

%.o :		%.c $(HD)
			gcc $(FLAGS) -c $< -o $@ -I $(HD)

$(NAME)	: 	$(OBJS)
			$(MAKE) -C $(SRC_LIB)
			gcc $(FLAGS) $(OBJS) $(SRC_LIB)/$(LIBFT) -o $(NAME)

clean :
			$(MAKE) clean -C $(SRC_LIB)
			rm -f $(OBJS)

fclean : 	clean
			$(MAKE) clean -C $(SRC_LIB)
			rm -f $(NAME)

re :		fclean all

.PHONY: all clean fclean re
