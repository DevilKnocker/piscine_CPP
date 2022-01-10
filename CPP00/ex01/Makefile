CC = clang++

CFLAGS = -Wall -Wextra -Werror

HEADER = PhoneBook.class.hpp

INCLUDES = -I.

SRCS = PhoneBook.class.cpp Contact.class.cpp annuaire.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = annuaire

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
