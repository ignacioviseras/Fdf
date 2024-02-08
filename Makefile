# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/04 17:35:19 by igvisera          #+#    #+#              #
#    Updated: 2024/02/08 21:15:59 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf
CFLAGS	=	-Wall -Wextra -Werror

UTILS_A		=	utils.a
UTILS_SRC 	=	./utils/
UTILS_OBJS	=	$(addprefix $(UTILS_SRC), *.o)
UTILSS     	=	$(addprefix $(UTILS_SRC), $(UTILS_A))

SRCS	=	main.c

OBJS	=	${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) $(UTILS)
		gcc $(CFLAGS) $(OBJS) -I ./fdf.h $(UTILSS) -framework OpenGL -framework AppKit -o $(NAME)

$(UTILS):
	$(MAKE) -C $(UTILS_SRC)

clean:
	rm -f $(OBJS) $(UTILS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re