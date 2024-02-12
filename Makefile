# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 17:35:19 by igvisera          #+#    #+#              #
#    Updated: 2024/02/12 20:54:23 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
CFLAGS	=	-Wall -Wextra -Werror

UTILS_A		=	utils.a
UTILS_SRC 	=	./utils/
UTILS_OBJS	=	$(addprefix $(UTILS_SRC), *.o)
UTILSS     	=	$(addprefix $(UTILS_SRC), $(UTILS_A))

MLX_A		=	libmlx42.a
MLX_SRC 	=	./MLX42/build
MLXX     	=	$(addprefix $(UTILS_SRC), $(UTILS_A))


SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(UTILSS) $(MLX) $(OBJS) 
	gcc $(CFLAGS) $(OBJS) $(MLXX) -Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" ./fdf.h $(UTILSS) -framework Cocoa -framework OpenGL -framework IOKit -o $(NAME)

$(UTILSS):
	$(MAKE) -C $(UTILS_SRC)

$(MLX):
	@make -C $(MLX_SRC)

clean:
	rm -f $(OBJS) $(UTILS_OBJS)
	$(MAKE) -C $(UTILS_SRC) clean


fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(UTILS_SRC) fclean


re: fclean all

.PHONY: all clean fclean re