#target
NAME = test

#compiler
CXX = c++
#comlile option
CXXFLAGS = -Wall -Wextra -Werror -pedantic -g -std=c++98
#includes
INCDIR = -I.
#srcs
SRCS = main.cpp Bureaucrat.cpp AForm.cpp  ShrubberyCreationForm.cpp GradeExceptions.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp
#objs
OBJS=$(SRCS:.cpp=.o)

.PHONY: all clean fclean re
all: $(NAME)
clean:
	rm -f $(OBJS)
fclean:
	rm -fr $(OBJS) $(NAME)
re: fclean all

$(NAME): $(OBJS)
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCDIR) -c $< -o $@