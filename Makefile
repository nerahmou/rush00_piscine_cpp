# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerahmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:17:07 by nerahmou          #+#    #+#              #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re
.SUFFIXES:

NAME := ft_retro
CC := clang++
CFLAGS := -Wall -Wextra -Werror
RM := rm -rf

#******************************************************************************#
#                                    LIBFT                                     #
#******************************************************************************#

SRCS_DIR=srcs/
INCS_DIR=includes/

SRC = $(addprefix $(SRCS_DIR), main.cpp)
INC = $(addprefix $(INCS_DIR), ft_retro.hpp)
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lncurses $^ -o $@

$(SRCS_DIR)%.o: $(SRCS_DIR)%.cpp  $(INC)
	$(CC) $(CFLAGS) -I $(INCS_DIR) -c $< -o $@

clean:
	$(RM) $(OBJ)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all
