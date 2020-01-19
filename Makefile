# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpieri <cpieri@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 12:43:54 by cpieri            #+#    #+#              #
#    Updated: 2020/01/19 19:21:54 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

# ***************************************** #
#			Ouput Name of Makefile			#
# ***************************************** #

NAME		=	ft_retro

# ***************************************** #
#	Path for Sources, Objects and Includes	#
# ***************************************** #

PATH_SRCS	=	srcs

PATH_OBJS	=	objs
PATH_INCS	=	includes

# ***************************************** #
#	Names of Sources, Objects and Includes	#
# ***************************************** #

NAME_SRCS	=	main.cpp			\
				GameEntity.cpp			\
				Person.cpp			\
				Decore.cpp			\
				Player.cpp			\
				Enemy.cpp			\
				Missile.cpp			\
				window/Window.cpp

NAME_OBJS	=	$(NAME_SRCS:.cpp=.o)

NAME_INCS	=	ft_retro.hpp	\
				Decore.hpp			\
				Enemy.hpp			\
				Decore.hpp			\
				Player.hpp			\
				Person.hpp			\
				Missile.hpp			\
				window/Window.hpp

NAME_DEPS	=	$(NAME_SRCS:.cpp=.d)

SRCS		=	$(addprefix $(PATH_SRCS)/,$(NAME_SRCS))

OBJS		=	$(addprefix $(PATH_OBJS)/,$(NAME_OBJS))

INCS		=	$(addprefix $(PATH_INCS)/,$(NAME_INCS))

DEPS		=	Makefile $(INCS)

# ***************************************** #
#			Flags for compile		 		#
# ***************************************** #

CC				=	clang++

FLAGS_INCS		=	-I./$(PATH_INCS)

FSANITIZE		=	-fsanitize=address -fno-omit-frame-pointer

NCURSE			=	-lncurses

override ERROR	+=	-g3

override FLAGS	+=	-Wall -Wextra -Werror


# ***************************************** #
#					Color					#
# ***************************************** #

NONE	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m
MAGENTA	=	\033[35m
CYAN	=	\033[36m
PINK	=	\033[38;5;206m

# ***************************************** #
#					Rules					#
# ***************************************** #

.PHONY: all clean fclean re echo

all:		$(NAME)

$(NAME):	echo $(OBJS)
			@$(CC) $(FLAGS) $(NCURSE) -o $(NAME) $(OBJS)
			@echo "\n$(GREEN)$(NAME) is ready !$(NONE)"

echo:
			@echo "$(YELLOW)Start of Compilation...$(NONE)"
			@echo "$(PINK)---------------------------$(CYAN)"
			@echo -n In progress

$(PATH_OBJS)/%.o: $(PATH_SRCS)/%.cpp $(DEPS)
			@mkdir $(dir $@) 2> /dev/null || true
			$(CC) $(FLAGS) $(FLAGS_INCS) -c $< -o $@
			@echo -n .

clean:
			@echo "$(YELLOW)Start of Cleaning...$(NONE)"
			@echo "$(PINK)---------------------------$(NONE)"
			@echo "$(CYAN)Deleting all objects files...$(NONE)"
			@/bin/rm -f $(OBJS)
			@/bin/rm -rf $(PATH_OBJS) 2> /dev/null || true
			@echo "$(GREEN)Objects files have been deleted !\n$(NONE)"

fclean:		clean
			@echo "$(CYAN)Deleting all binary files...$(NONE)"
			@/bin/rm -f $(NAME)
			@echo "$(GREEN)Binary files have been deleted !\n$(NONE)"

re:			fclean all
