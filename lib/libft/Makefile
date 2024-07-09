# # DIRECTORIES
SRC = ./src/string/ft_strchr.c \
			./src/string/ft_strdup.c \
			./src/string/ft_striteri.c \
			./src/string/ft_strjoin.c \
			./src/string/ft_strlcat.c \
			./src/string/ft_strlcpy.c \
			./src/string/ft_strlen.c \
			./src/string/ft_strmapi.c \
			./src/string/ft_strncmp.c \
			./src/string/ft_strnstr.c \
			./src/string/ft_strrchr.c \
			./src/string/ft_strtrim.c \
			./src/string/ft_atoi.c \
			./src/string/ft_itoa.c \
			./src/string/ft_substr.c \
			./src/string/ft_tolower.c \
			./src/string/ft_toupper.c \
			./src/string/ft_split.c \
			./src/list/ft_lstadd_back_bonus.c \
			./src/list/ft_lstadd_front_bonus.c \
			./src/list/ft_lstclear_bonus.c \
			./src/list/ft_lstdelone_bonus.c \
			./src/list/ft_lstiter_bonus.c \
			./src/list/ft_lstlast_bonus.c \
			./src/list/ft_lstmap_bonus.c \
			./src/list/ft_lstnew_bonus.c \
			./src/list/ft_lstsize_bonus.c \
			./src/checker/ft_isalpha.c \
			./src/checker/ft_isascii.c \
			./src/checker/ft_isdigit.c \
			./src/checker/ft_isprint.c \
			./src/checker/ft_isalnum.c \
			./src/memory/ft_memchr.c \
			./src/memory/ft_memcmp.c \
			./src/memory/ft_memcpy.c \
			./src/memory/ft_memmove.c \
			./src/memory/ft_memset.c \
			./src/memory/ft_bzero.c \
			./src/memory/ft_calloc.c \
			./src/print/ft_putendl_fd.c \
			./src/print/ft_putnbr_fd.c \
			./src/print/ft_putstr_fd.c \
			./src/print/ft_printf.c \
			./src/print/print_uint_base.c \
			./src/print/print_pointer.c \
			./src/print/print_int_base.c \
			./src/print/ft_putchar_fd.c \

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

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo "libft.a created"

all: $(NAME)


clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all


.PHONY: all clean fclean re
.DEFAULT_GOAL = all
