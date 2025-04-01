CC = c++
CPPFILES = main.cpp\
	ScalarConverter.cpp
OFILES = $(CPPFILES:.cpp=.o)
FLAGS = -Wall -Werror -Wextra -std=c++17
NAME = convert

$(NAME) : $(OFILES)
	$(CC) $(FLAGS) $(OFILES) -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OFILES)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean