SRC = $(wildcard ./src/*.c)

OBJ = $(SRC:.c=.o)

# VARIABLES
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
NAME = libft.a
RM = rm -f

# RULES


%.o: %.c
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

