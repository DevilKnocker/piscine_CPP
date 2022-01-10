CC					=	clang++
NAME				=	megaphone
SRCS				=	megaphone.cpp
OBJS				=	$(SRCS:.cpp=.o)	
CFLAGS				=	-Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^
	echo $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
