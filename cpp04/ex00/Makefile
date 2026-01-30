# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::   #
#    Makefile                                           :+:      :+:    :+:   #
#                                                     +:+ +:+         +:+     #
#                                                 +#+  +:+       +#+          #
#                                             +#+#+#+#+#+   +#+               #
#                                                  #+#    #+#                 #
#                                                 ###   ########.fr          #
#                                                                              #
# **************************************************************************** #

NAME		= animal

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS_DIR	= srcs
INCS_DIR	= includes
OBJS_DIR	= objs

SRCS		= main.cpp \
			  Animal.cpp \
			  Dog.cpp \
			  Cat.cpp \
			  WrongAnimal.cpp \
			  WrongCat.cpp

OBJS		= $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.cpp
			@mkdir -p $(OBJS_DIR)
			$(CXX) $(CXXFLAGS) -I$(INCS_DIR) -c $< -o $@

clean:
			rm -rf $(OBJS_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
