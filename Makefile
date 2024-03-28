# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 21:42:38 by mboughra          #+#    #+#              #
#    Updated: 2024/03/28 15:53:01 by mboughra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: server client
bonus: server_bonus client_bonus
# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

server: Mandatory/server.c tools/ft_printf.c tools/ft_hexafunctions.c \
		tools/ft_putfunctions.c Minitalk.h
	$(CC) -o $@ Mandatory/server.c tools/ft_printf.c tools/ft_hexafunctions.c \
		tools/ft_putfunctions.c $(CFLAGS) 

client: Mandatory/client.c tools/ft_printf.c tools/ft_hexafunctions.c \
		tools/ft_putfunctions.c Minitalk.h
	$(CC) -o $@ Mandatory/client.c tools/ft_printf.c tools/ft_hexafunctions.c \
		tools/ft_putfunctions.c $(CFLAGS)
		
client_bonus: Bonus/client_bonus.c tools/ft_printf.c tools/ft_hexafunctions.c \
		tools/ft_putfunctions.c Minitalk.h
	$(CC) -o $@ Bonus/client_bonus.c tools/ft_printf.c tools/ft_hexafunctions.c \
		tools/ft_putfunctions.c tools/recieved.c $(CFLAGS)
		
server_bonus: Bonus/server_bonus.c tools/ft_printf.c tools/ft_hexafunctions.c \
		tools/ft_putfunctions.c Minitalk.h
	$(CC) -o $@ Bonus/server_bonus.c tools/ft_printf.c tools/ft_hexafunctions.c \
		tools/ft_putfunctions.c $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) server client server_bonus client_bonus

re:	fclean all
