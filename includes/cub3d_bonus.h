#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"

# include <fcntl.h>
# include <math.h>

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
    double plane_x;
    double plane_y;
    char direction;
}   t_player;

typedef struct s_ray
{
    double      camera_x;
    double      ray_dir_x;
    double      ray_dir_y;
    int         map_x;
    int         map_y;
    double      side_dist_x;
    double      side_dist_y;
    double      delta_dist_x;
    double      delta_dist_y;
    double      perp_wall_dist;
    int         step_x;
    int         step_y;
    int         hit;
    int         side;
    int         line_height;
    int         draw_start;
    int         draw_end;
}   t_ray;


typedef struct s_img
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     width;
    int     height;
}   t_img;

typedef struct s_sprite
{
	double x;
	double y;
}	t_sprite;

typedef struct s_game
{
    void *mlx;
    void *win;
    
     
    t_img img;

    t_tex tex;
     
    t_img wall_tex[4];  
    t_img door_tex;
    t_img sprite_tex[2];  
    
    t_color floor;
    t_color ceiling;
    t_map map;
    t_player player;
    t_ray ray;

	 
	double *z_buffer;
	int num_sprites;
	t_sprite *sprites;
	int frame_count;
} t_game;

 //init_struct.c
void init_game(t_game *game);
void init_parse(t_game *game);

//check
int check_filename(char* filename);

//free
void free_split(char** split);
void free_all(t_game *game);

//error
void perror_and_exit(char *msg, t_game *game);

//parse
void parse(char *filename, t_game *game);
int check_map_chars(t_game *game);
int check_map_closed(t_game *game);

//init_window.c
int init_window(t_game *game);
int close_game(t_game *game);
int key_press(int keycode, t_game *game);
int mouse_handler(int x, int y, t_game *game);
void move_forward(t_game *game);
void move_backward(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);
void rotate_left(t_game *game);
void rotate_right(t_game *game);
void interact_door(t_game *game);

//render
int		render_frame(t_game *game);
void	draw_textured_line(t_game *game, int x, int *draw, t_img *tex, int tex_x);
void	draw_floor_ceiling(t_game *game, int x, int draw_start, int draw_end);
void	draw_minimap(t_game *game);

//raycast
void raycast(t_game *game);
void perform_dda(t_game *game);
void select_texture(t_game *game, t_img **tex);

//player
void init_player_dir(t_game *game);

//init_textures.c
int init_textures(t_game *game);
unsigned int get_texture_color(t_img *tex, int x, int y);

 
void init_sprites(t_game *game);
void draw_sprites(t_game *game);

#endif
