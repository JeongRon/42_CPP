NAME = PhoneBook

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =	PhoneBook.hpp \
 			Contact.hpp \

SRCS =  main.cpp \
		Contact.cpp \
		PhoneBook.cpp \
		Command.cpp \

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