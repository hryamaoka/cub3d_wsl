#ifndef CUB3D_H
# define CUB3D_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

#include <fcntl.h>

typedef struct s_tex
{
    char *no;
    char *so;
    char *we;
    char *ea;
}   t_tex;

typedef struct s_color
{
    int r;
    int g;
    int b;
}   t_color;

typedef struct s_map
{
    char **grid;
    int width;
    int height;
}   t_map;

typedef struct s_player
{
    double x;
    double y;
    double dir_x;
    double dir_y;
    char direction;
}   t_player;

typedef struct s_game
{
    void *mlx;
    void *win;
    void *img; 

    t_tex tex;
    t_color floor;
    t_color ceiling;
    t_map map;
    t_player player;
} t_game;

//check
int check_filename(char* filename);

//free
void free_split(char** split);
void free_all(t_game *game);

//error
void perror_and_exit(char *msg, t_game *game);

//parse
void parse(char *filename, t_game *game);

#endif
