# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mboughra <mboughra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 21:42:38 by mboughra          #+#    #+#              #
#    Updated: 2024/03/25 18:17:00 by mboughra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall

SRC = Mandatory/server.c Mandatory/client.c tools/ft_printf.c \
tools/ft_hexafunctions.c tools/ft_putfunctions.c

BSRC = Bonus/server.c Bonus/client.c tools/ft_printf.c \
tools/ft_hexafunctions.c tools/ft_putfunctions.c

OBJ = $(SRC:.c=.o)
BOBJ = $(SRC:.c=.o)
RM = rm -rf

all: server client
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

server: Mandatory/server.o tools/ft_printf.o tools/ft_hexafunctions.o \
		tools/ft_putfunctions.o
	$(CC) -o $@ $^ $(CFLAGS)

client: Mandatory/client.o tools/ft_printf.o tools/ft_hexafunctions.o \
		tools/ft_putfunctions.o
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) server client

re:	fclean all


# CC =  cc
# CFLAGS = -Wall -Werror -Wextra
# NAME = server
# SRCS = ft_hexafunctions.c ft_printf.c ft_putfunctions.c server.c
# OBJS = $(SRCS:.c=.o)
# HEADER = Minitalk.h
# all: $(NAME)
# %.o: %.c $(HEADER)
# 	$(CC) -Wall -Wextra -Werror -c $< -o $@
# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
# clean:
# 	rm -f $(OBJS)
# fclean: clean
# 	rm -f $(NAME)
# re: fclean all
# .PHONY: clean