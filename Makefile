# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 11:02:47 by ysonmez           #+#    #+#              #
#    Updated: 2021/08/19 19:29:59 by ysonmez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			=		client

SERVER			=		server

SRCS_SERVER		=		server.c \

SRCS_CLIENT		=		client.c \

OBJS_SERVER		=		$(SRCS_SERVER:.c=.o)

OBJS_CLIENT		=		$(SRCS_CLIENT:.c=.o)

CC				=		gcc

CFLAGS			=		-Wall -Wextra -Werror

RM				=		rm -f

$(CLIENT) $(SERVER):
			make bonus -C ./libft
			$(CC) $(CFLAGS) -c $(SRCS_SERVER)
			$(CC) $(CFLAGS) -c $(SRCS_CLIENT)
			$(CC) $(CFLAGS) $(OBJS_CLIENT) libft/libft.a -o $(CLIENT)
			$(CC) $(CFLAGS) $(OBJS_SERVER) libft/libft.a -o $(SERVER)

bonus:		all

clean:
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)

fclean:		clean
			$(RM) $(CLIENT)
			$(RM) $(SERVER)
			cd ./libft && make fclean

all:		$(CLIENT) $(SERVER)

re:			fclean all

.PHONY:		clean fclean all re bonus
