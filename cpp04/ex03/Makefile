NAME = Recap

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER =	AMateria.hpp \
			Cure.hpp \
			Ice.hpp \
			Character.hpp \
			ICharacter.hpp \
			IMateriaSource.hpp \
			MateriaSource.hpp \

SRCS =  main.cpp \
		AMateria.cpp \
		Cure.cpp \
		Ice.cpp \
		Character.cpp \
		MateriaSource.cpp \

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