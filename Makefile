
SFLAGS = -lmlx -framework OpenGL -framework Appkit
CFLAGS = -Wall -Wextra -Werror
file = so_long.c \
	   utils/parse_map.c \
	   utils/parse_map_utils.c \
	   utils/so_long_clean.c \
	   utils/init_game.c \
	   utils/game_move.c \
	   utils/valid_path.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c

Bfile = so_long_bonus.c \
	   bonus_utils/parse_map_bonus.c \
	   bonus_utils/parse_map_utils_bonus.c \
	   bonus_utils/so_long_clean_bonus.c \
	   bonus_utils/init_game_bonus.c \
	   bonus_utils/game_move_bonus.c \
	   bonus_utils/valid_path_bonus.c \
	   bonus_utils/enemy_move_bonus.c \
	   bonus_utils/enemy_move_utils_bonus.c \
	   get_next_line/get_next_line.c \
	   get_next_line/get_next_line_utils.c

OBJ = $(file:.c=.o)
BOBJ = $(Bfile:.c=.o)
NAME = so_long

all: $(NAME)
	
$(NAME): $(OBJ) so_long.h libft/libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h
	@make -s -C libft
	@make -s -C ft_printf
	cc $(CFLAGS) $(SFLAGS) $(OBJ) libft/libft.a ft_printf/libftprintf.a -o $(NAME)

bonus: $(NAME)_bonus 

$(NAME)_bonus: $(BOBJ) so_long_bonus.h libft/libft.h ft_printf/ft_printf.h get_next_line/get_next_line.h
	@make -s -C libft
	@make -s -C ft_printf
	cc $(FLAGS) $(SFLAGS) $(BOBJ) libft/libft.a ft_printf/libftprintf.a -o $(NAME)_bonus

%.o: %.c
	cc $(CFLAGS) -c $< -o $@ 
get_next_line/%.o:get_next_line/%.c get_next_line/get_next_line.h
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(BOBJ)
	@make clean -s -C libft 
	@make clean -s -C ft_printf

fclean: clean
	rm -f $(NAME) $(NAME)_bonus
	@make fclean -s -C libft 
	@make fclean -s -C ft_printf

re: fclean all

.PHONY : clean