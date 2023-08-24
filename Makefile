SRC = main.c parsing_stock.c parsing_utils.c check_map.c check_color_texture.c\
	mlx_utils.c data_init.c intersectionxy.c wall_projections.c player_moves.c texturs_utils.c\
	norm_util.c

BSRC =  bonus/_bonus_check_color_texture.c bonus/_bonus_data_init.c bonus/_bonus_main.c bonus/_bonus_parsing_stock.c\
			bonus/_bonus_texturs_utils.c bonus/_bonus_check_map.c bonus/_bonus_draw_mini_map.c bonus/_bonus_mlx_utils.c\
				bonus/_bonus_parsing_utils.c bonus/_bonus_wall_projections.c bonus/_bonus_intersectionxy.c\
					bonus/_bonus_player_moves.c bonus/_bonus_norm_utils.c
NAME = cub3D

BNAME = cub3d_bonus

PATH_OBJ = obj/

CC = cc

FLAGS = -Wall -Wextra -Werror -Imlx

OBJ = $(addprefix $(PATH_OBJ), $(SRC:.c=.o))

BOBJ = $(addprefix $(PATH_OBJ), $(BSRC:.c=.o))

$(NAME): $(OBJ) libft/libft.a
	$(CC) $(FLAGS) -o $(NAME) $(SRC) libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

$(BNAME): $(BOBJ) libft/libft.a
	$(CC) $(FLAGS) -o $(BNAME) $(BSRC) libft/libft.a -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

$(OBJ) : $(PATH_OBJ)%.o: %.c  cub3D.h
	@mkdir -p $(dir $@)
	${CC} ${FLAGS} -c $< -o $@

$(BOBJ) : $(PATH_OBJ)%.o: %.c  bonus/_bonus_cub3D.h
	@mkdir -p $(dir $@)
	${CC} ${FLAGS} -c $< -o $@

libft/libft.a:
	make -C Libft all

all: $(NAME)

bonus: $(BNAME)

clean:
	make -C libft fclean
	rm -rf $(PATH_OBJ)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf $(BNAME)

re: fclean all
