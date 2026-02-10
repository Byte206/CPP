NAME = forms
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
INCLUDES = -I includes
SRCS = main.cpp srcs/Bureaucrat.cpp srcs/AForm.cpp \
       srcs/ShrubberyCreationForm.cpp srcs/RobotomyRequestForm.cpp \
       srcs/PresidentialPardonForm.cpp srcs/Intern.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
