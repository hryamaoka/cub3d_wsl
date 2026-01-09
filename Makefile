NAME = cub3D
CC = cc
CFLAGS = -Wextra -Wall -Werror -g
RM = rm -rf

SRCS_DIR = ./srcs
INC_DIR = ./includes
LIB_DIR = ./libft


SRCS = $(shell find srcs -type f -name "*.c")
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = $(shell find srcs_bonus -type f -name "*_bonus.c")
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = $(LIB_DIR)/libft.a

UNAME := $(shell uname)

ifneq ($(UNAME), Darwin)
    # Linux
    MLX_DIR = ./minilibx-linux
    MLX = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
    # MacOS (Fallback)
    MLX_DIR = ./minilibx_opengl_20191021
    MLX = $(MLX_DIR)/libmlx.a
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
endif

INCLUDES = -I$(INC_DIR) -I$(LIB_DIR)/includes -I$(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: $(OBJS_BONUS) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
