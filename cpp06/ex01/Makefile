NAME = Serializer

CPP = c++

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

HEADER = Serializer.hpp \
		Data.hpp \

SRCS =  main.cpp \
		Serializer.cpp \
		Data.cpp \

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