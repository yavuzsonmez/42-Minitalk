# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ysonmez <ysonmez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/19 11:02:47 by ysonmez           #+#    #+#              #
#    Updated: 2021/08/20 14:57:47 by ysonmez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=		minitalk

CLIENT			=		client

SERVER			=		server

SRCS_SERVER		=		srcs_server/server.c \
						srcs_server/smessages.c \

SRCS_CLIENT		=		srcs_client/client.c \

OBJS_SERVER		=		$(SRCS_SERVER:.c=.o)

OBJS_CLIENT		=		$(SRCS_CLIENT:.c=.o)

CC				=		gcc

CFLAGS			=		-Wall -Wextra -Werror

RM				=		rm -f

$(NAME): 	$(OBJS_CLIENT) $(OBJS_SERVER)
			make bonus -C ./libft
			$(CC) $(CFLAGS) $(OBJS_CLIENT) libft/libft.a -o $(CLIENT)
			$(CC) $(CFLAGS) $(OBJS_SERVER) libft/libft.a -o $(SERVER)

server:		$(OBJS_SERVER)
			make bonus -C ./libft
			$(CC) $(CFLAGS) $(OBJS_SERVER) libft/libft.a -o $(SERVER)

client:		$(OBJS_CLIENT)
			make bonus -C ./libft
			$(CC) $(CFLAGS) $(OBJS_CLIENT) libft/libft.a -o $(CLIENT)

bonus:		all

clean:
			$(RM) $(OBJS_CLIENT)
			$(RM) $(OBJS_SERVER)

fclean:		clean
			$(RM) $(CLIENT)
			$(RM) $(SERVER)
			cd ./libft && make fclean

all:		$(NAME)

re:			fclean all

.PHONY:		clean fclean all re bonus
