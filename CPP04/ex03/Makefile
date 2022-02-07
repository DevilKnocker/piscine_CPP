CC = clang++

CFLAGS = -Wall -Wextra -Werror

HEADER = Cure.hpp AMateria.hpp ICharacter.hpp Character.hpp MateriaSource.hpp IMateriaSource.hpp Ice.hpp Linklist.hpp

INCLUDES = -I.

SRCS = main.cpp Cure.cpp AMateria.cpp Character.cpp MateriaSource.cpp Ice.cpp Linklist.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = materia

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
