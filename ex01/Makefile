NAME = exec

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++17 -fsanitize=address

DEBUG = -g

SRCS = Bureaucrat.cpp main.cpp Form.cpp

OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	$(CC) $(DEBUG) $(CFLAGS) $^ -o $@

%.cpp:%.o
	$(CC) $(DEBUG) $(CFLAGS) -c $< -o $@

all : $(NAME)
# @echo g++ --version

clean :
	@echo Deleting objects...
	rm -f $(OBJS)

fclean : clean
	@echo Deleting executable...
	rm -f $(NAME)

superclean : fclean
	@rm -f *.txt

re : fclean all

.PHONY= all clean fclean re superclean