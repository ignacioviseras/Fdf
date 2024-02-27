# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 17:35:19 by igvisera          #+#    #+#              #
#    Updated: 2024/02/27 20:52:52 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
# CFLAGS	=	-Wall -Wextra -g3 
# CFLAGS	=	-Wall -Wextra -Werror -g3 
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS	=	-Wall -Wextra -g3 -fsanitize=address

#STRUCT	=	-lmlx -framework OpenGL -framework AppKit

UTILS_A		=	utils.a
UTILS_SRC 	=	./utils/
UTILS_OBJS	=	$(addprefix $(UTILS_SRC), *.o)
UTILS     	=	$(addprefix $(UTILS_SRC), $(UTILS_A))

MLX_A		=	libmlx.dylib
MLX_SRC 	=	./mlx/
MLX_OBJS	=	$(addprefix $(MLX_SRC), *.o)
MLX     	=	$(addprefix $(MLX_SRC), $(MLX_A))

SRCS	=	generate.c \
			parsing.c \
			params.c \
			

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(UTILS) $(OBJS)
	 gcc $(CFLAGS) $(OBJS)  $(UTILS) -o $(NAME)
#	gcc $(CFLAGS) $(OBJS) -I ./fdf.h $(UTILS) $(STRUCT) -o $(NAME)

$(UTILS):
	$(MAKE) -C $(UTILS_SRC)

clean:
	rm -f $(OBJS) $(UTILS_OBJS)
	$(MAKE) -C $(UTILS_SRC) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(UTILS_SRC) fclean

re: fclean all

.PHONY: all clean fclean re