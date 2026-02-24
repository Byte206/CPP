NAME = convert

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: $(NAME)
	@echo "=== Testing char literals ==="
	@./$(NAME) 'a'
	@echo ""
	@./$(NAME) 'z'
	@echo ""
	@echo "=== Testing int literals ==="
	@./$(NAME) 0
	@echo ""
	@./$(NAME) 42
	@echo ""
	@./$(NAME) -42
	@echo ""
	@echo "=== Testing float literals ==="
	@./$(NAME) 0.0f
	@echo ""
	@./$(NAME) 4.2f
	@echo ""
	@./$(NAME) -4.2f
	@echo ""
	@echo "=== Testing double literals ==="
	@./$(NAME) 0.0
	@echo ""
	@./$(NAME) 4.2
	@echo ""
	@./$(NAME) -4.2
	@echo ""
	@echo "=== Testing pseudo-literals (float) ==="
	@./$(NAME) nanf
	@echo ""
	@./$(NAME) inff
	@echo ""
	@./$(NAME) -inff
	@echo ""
	@echo "=== Testing pseudo-literals (double) ==="
	@./$(NAME) nan
	@echo ""
	@./$(NAME) inf
	@echo ""
	@./$(NAME) -inf
	@echo ""
	@echo "=== Testing edge cases ==="
	@./$(NAME) 127
	@echo ""
	@./$(NAME) 128
	@echo ""
	@echo "=== Testing invalid input ==="
	@./$(NAME) abc123
	@echo ""

.PHONY: all clean fclean re test
