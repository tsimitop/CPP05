NAME = exec

CC = c++

CFLAGS = -Wall -Werror -Wextra -std=c++17

DEBUG = -g

SRCS = Bureaucrat.cpp main.cpp AForm.cpp PresidentialPardonForm.cpp \
		RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

OBJ_DIR = objects
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

$(NAME): $(OBJS)
	@echo Compiling...
	@$(CC) $(DEBUG) $(CFLAGS) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(DEBUG) $(CFLAGS) -c $< -o $@

all: $(NAME)
#	@g++ --version

clean:
	@echo Deleting objects...
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo Deleting executable...
	@rm -f $(NAME)

superclean: fclean
	@rm -f *.txt
	@rm -f *_shrubbery

re: fclean all

.PHONY: all clean fclean re