NAME = cub3D
CC = cc
CFLAGS = -Wextra -Wall -Werror 

RM = rm -rf

SRCS_DIR = ./srcs
INC_DIR = ./includes

LIB_DIR = ./libft
LIB = $(LIB_DIR)/libft.a

# SRCS = $(addprefix $(SRCS_DIR)/, \
# 		main.c \
# 		parse/parse.c \
# 		parse/parse_texture.c \
# 		parse/parse_color.c \
# 		parse/parse_map.c \
# 		utils/error.c \
# 		) \

SRCS = $(shell find $(SRCS_DIR) -name "*.c")

OBJS = $(SRCS:.c=.o)

INCLUDES = -I $(INC_DIR) -I $(LIB_DIR)/includes

UNAME := $(shell uname)

ifeq ($(UNAME), Darwin)
    # macOS
    MLX_DIR = minilibx_opengl_20191021
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit
else
    # Linux
    MLX_DIR = minilibx-linux
    MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
endif

INCLUDES += -I $(MLX_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIB)
		$(MAKE) -C $(MLX_DIR)
		$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX_FLAGS) -o $(NAME)

$(LIB):
		$(MAKE) -C $(LIB_DIR)

%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
		$(RM) $(OBJS)
		$(MAKE) -C $(MLX_DIR) clean
		$(MAKE) -C $(LIB_DIR) clean

fclean: clean
		$(RM) $(NAME)
		$(MAKE) -C $(LIB_DIR) fclean

re:		fclean all

.PHONY	: all clean fclean re
