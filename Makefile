# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 17:35:19 by igvisera          #+#    #+#              #
#    Updated: 2024/03/18 19:43:43 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
# CFLAGS	=	-Wall -Wextra -g3 
# CFLAGS	=	-Wall -Wextra -Werror -g3 
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address
# CFLAGS	=	-Wall -Wextra -g3 -fsanitize=address

# STRUCT	=	-lmlx -framework OpenGL -framework AppKit
# STRUCT			= -lmlx -lXext -lX11 -lm
STRUCT			= -Imlx_linux -lXext -lX11 -lm -lz


UTILS_A		=	utils.a
UTILS_SRC 	=	./utils/
UTILS_OBJS	=	$(addprefix $(UTILS_SRC), *.o)
UTILS     	=	$(addprefix $(UTILS_SRC), $(UTILS_A))

MLX_A		=	libmlx.dylib
MLX_SRC 	=	./mlx/
MLX_OBJS	=	$(addprefix $(MLX_SRC), *.o)
MLX     	=	$(addprefix $(MLX_SRC), $(MLX_A))

SRCS	=	generate.c \
			draw_map_utils.c \
			params.c \
			draw_map.c \
			main.c \
			parsing.c \
			

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(UTILS) $(OBJS)
#  	gcc $(CFLAGS) $(OBJS)  $(UTILS) -o $(NAME)
# gcc $(CFLAGS) $(OBJS) -I ./fdf.h $(UTILS) $(STRUCT) -o $(NAME)
	gcc $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -I ./fdf.h $(UTILS) $(STRUCT) -o $(NAME)

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