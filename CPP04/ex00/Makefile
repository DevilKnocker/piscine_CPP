CC = clang++

CFLAGS = -Wall -Wextra -Werror

HEADER = Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp

INCLUDES = -I.

SRCS = main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = animal

RM = rm -rf

all:	$(MAIN)

$(MAIN): $(OBJS)
		$(CC) $(CFLAGS) -o $(MAIN) $(OBJS)

%.o: %.cpp $(HEADER)
		$(CC) $(CFLAGS) -c $<  -o $@ $(INCLUDES)

clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(MAIN)

re: fclean all

.PHONY: all clean fclean re
