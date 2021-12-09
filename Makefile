CC := g++
RM = rm -rf
LDFLAGS += -Llib
CFLAGS += -Iinclude -Wall -Wextra -Werror -g
SRCS := $(wildcard *.cpp)
OBJS := $(SRCS:.cpp=.o)
NAME := lab3

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)
