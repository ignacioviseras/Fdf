# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 17:35:19 by igvisera          #+#    #+#              #
#    Updated: 2024/05/08 20:45:49 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

#laptop
# CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -O3
# STRUCT			= -Imlx_linux -lXext -lX11 -lm -lz

#42 linux
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address -O3 -fPIE 
STRUCT			= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

UTILS_A		=	utils.a
UTILS_SRC 	=	./utils/
UTILS_OBJS	=	$(addprefix $(UTILS_SRC), *.o)
UTILS     	=	$(addprefix $(UTILS_SRC), $(UTILS_A))


SRCS	=	draw_map_utils.c \
			params.c \
			draw_map.c \
			main.c \
			map_actions.c \

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

#laptop
# $(NAME): $(UTILS) $(OBJS)
# gcc $(CFLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -I ./fdf.h $(UTILS) $(STRUCT) -o $(NAME)

#42 linux
$(NAME): $(UTILS) $(OBJS)
	gcc $(CFLAGS) $(OBJS)  $(UTILS) -o $(NAME) $(STRUCT) -I ./fdf.h

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