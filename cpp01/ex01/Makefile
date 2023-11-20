NAME = ZombieHorde

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =	Zombie.hpp \

SRCS =  main.cpp \
		Zombie.cpp \
		zombieHorde.cpp \

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