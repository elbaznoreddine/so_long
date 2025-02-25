CC = cc
CFLAGS = -Wall -Wextra -Werror
FT = ft_putstrc.c \
	 ft_putnbrc.c \
	 ft_putcharc.c \
	 ft_printf.c \
	 ft_print_p.c \
	 ft_print_hex_dig.c \
	 ft_show.c

OBJ = $(FT:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : clean