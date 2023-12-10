NAME = Brain

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Animal.hpp \
		Cat.hpp \
		Dog.hpp \
		WrongAnimal.hpp \
		WrongCat.hpp \
		Brain.hpp \

SRCS =  main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		WrongAnimal.cpp \
		WrongCat.cpp \
		Brain.cpp \

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