NAME = cub3D
SRC =	cub3d.c \
		srcs/parse/ft_parse.c \
		srcs/parse/ft_utils.c \
		srcs/parse/ft_utils_free.c \
		srcs/parse/get_next_line.c \
		srcs/parse/parse_param.c \
		srcs/parse/check_path.c \
		srcs/parse/check_color.c \
		srcs/parse/parse_map.c \
		srcs/parse/check_map.c \
		srcs/mlx/ft_mlx.c \
		srcs/mlx/xpm_to_image.c \
		srcs/mlx/ft_dda.c \
		srcs/mlx/ft_controls.c \
		srcs/mlx/ft_camera.c \
		srcs/mlx/drawing.c \
		srcs/mlx/ft_mlx_utils.c
BONUS_SRC = bonus/cub3d_bonus.c \
		bonus/parse_bonus/ft_parse_bonus.c \
		bonus/parse_bonus/ft_utils_bonus.c \
		bonus/parse_bonus/ft_utils_free_bonus.c \
		bonus/parse_bonus/get_next_line_bonus.c \
		bonus/parse_bonus/parse_param_bonus.c \
		bonus/parse_bonus/check_path_bonus.c \
		bonus/parse_bonus/check_color_bonus.c \
		bonus/parse_bonus/parse_map_bonus.c \
		bonus/parse_bonus/check_map_bonus.c \
		bonus/mlx_bonus/ft_mlx_bonus.c \
		bonus/mlx_bonus/xpm_to_image_bonus.c \
		bonus/mlx_bonus/ft_dda_bonus.c \
		bonus/mlx_bonus/ft_controls_bonus.c \
		bonus/mlx_bonus/ft_camera_bonus.c \
		bonus/mlx_bonus/drawing_bonus.c \
		bonus/mlx_bonus/ft_mlx_utils_bonus.c

LIBFT = ./libft/libft.a
CFLAGS = -Wall -Werror -Wextra -O3
OBJ = $(SRC:.c =.o)

ifdef WITH_BONUS
	OBJ = $(BONUS_SRC:.c=.o)
else
	OBJ = $(SRC:.c=.o)
endif

$(NAME): $(OBJ)
		@$(MAKE) -s --no-print-directory -C ./libft
		gcc $(CFLAGS) $(LIBFT) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: 	$(NAME)

clean :
		@$(MAKE) -s --no-print-directory -C ./libft clean
		rm -rf */*/*.o */*.o *.o

fclean :
		@$(MAKE) -s --no-print-directory -C ./libft fclean
		rm -rf */*/*.o */*.o *.o $(NAME)

re : fclean all

bonus :
	@make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus