CC = cc
CFLAGS = -Wall -Werror -Wextra
FT = ft_itoa.c \
	 ft_memcpy.c \
	 ft_memmove.c \
	 ft_strchr.c \
	 ft_strdup.c \
	 ft_strjoin.c \
	 ft_strlcat.c \
	 ft_strlcpy.c \
	 ft_strlen.c \
	 ft_strncmp.c \
	 ft_strnstr.c \
	 ft_substr.c \

OBJ = $(FT:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean