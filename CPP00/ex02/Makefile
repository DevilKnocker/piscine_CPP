CC = clang++

CFLAGS = -Wall -Wextra -Werror

HEADER = Account.hpp

INCLUDES = -I.

SRCS = Account.cpp tests.cpp

OBJS = $(SRCS:.cpp=.o)

MAIN = account

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
