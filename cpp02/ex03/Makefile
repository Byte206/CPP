NAME		= bsp

CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJ			= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp Fixed.hpp Point.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re