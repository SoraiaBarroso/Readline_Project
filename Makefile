CC = gcc
CFLAGS += -Wall -Wextra -Werror
SRC = my_readline.c my_readline.h
TARGET = my_readline

all: $(TARGET)

$(TARGET) : $(SRC)
	gcc $(CFLAGS) -o $(TARGET) $(SRC) 

clean:
	rm -f *.o

fclean: clean
	rm -f $(TARGET)

re: fclean all