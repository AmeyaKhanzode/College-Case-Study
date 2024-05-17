CC = gcc

CFLAGS = -Wall -Wextra -std=c99 
SRCS = functions.c main.c
OBJS = $(SRCS:.c=.o)

TARGET = program

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -f $(OBJS) $(TARGET)

