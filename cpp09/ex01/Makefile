NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp RPN.cpp
OBJS = main.o RPN.o
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

main.o: main.cpp RPN.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

RPN.o: RPN.cpp RPN.hpp
	$(CXX) $(CXXFLAGS) -c RPN.cpp -o RPN.o

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
