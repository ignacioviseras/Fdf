# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igvisera <igvisera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/08 19:57:48 by igvisera          #+#    #+#              #
#    Updated: 2024/02/13 20:56:21 by igvisera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	utils.a

#laptop
# CFLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address

#42 linux
CFLAGS			=	-Wall -Wextra -Werror -g3 -fsanitize=address -fPIE

PATH_BASICS 	=	./basics/
PATH_PRINTF 	=	./printf/
BASICS   	  	=	$(addprefix $(PATH_BASICS), $(BASICS_SRC))
PRINTF	     	=	$(addprefix $(PATH_PRINTF), $(PRINTF_SRC))

SRCS			=	get_next_line.c \
					load_map.c \

BASICS_SRC		=	free_all.c \
					ft_atoi.c \
					ft_bzero.c \
					ft_calloc.c \
					ft_memcpy.c \
					ft_memset.c \
					ft_realloc.c \
					ft_split.c \
					ft_strchr.c \
					ft_strdup.c \
					ft_strjoin.c \
					ft_strlcat.c \
					ft_strlcpy.c \
					ft_strlen.c \
					ft_substr.c \
					ft_strcmp.c \
					atoi_base.c \
					map_realloc.c \

PRINTF_SRC		=	ft_printf.c \
					ft_printNumbers.c \
					ft_printText.c


OBJS			=	${BASICS:.c=.o} \
					${PRINTF:.c=.o} \
					${SRCS:.c=.o} \

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re