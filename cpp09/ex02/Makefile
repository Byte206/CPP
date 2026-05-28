
TARGET = PmergeMe
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PmergeMe.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

