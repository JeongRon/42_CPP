NAME = Intern

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Bureaucrat.hpp \
		AForm.hpp \
		ShrubberyCreationForm.hpp \
		RobotomyRequestForm.hpp \
		PresidentialPardonForm.hpp \
		Intern.hpp \

SRCS =  main.cpp \
		Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp \
		PresidentialPardonForm.cpp \
		Intern.cpp \

OBJS = $(SRCS:%.cpp=%.o)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@
	
$(NAME): $(OBJS) $(HEADER)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

.PHONY: clean fclean all re