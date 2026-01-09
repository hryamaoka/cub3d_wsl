#include "cub3d.h"

int close_game(t_game *game)
{
     
     
     
    free_all(game);
    exit(0);
    return (0);
}



int init_window(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return (0);

     
     
    int screen_w = 1024;
    int screen_h = 768;
    
    game->win = mlx_new_window(game->mlx, screen_w, screen_h, "cub3D");
    if (!game->win)
        return (0);
        
    game->img.img = mlx_new_image(game->mlx, screen_w, screen_h);
    game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
    game->img.width = screen_w;
    game->img.height = screen_h;
    
	// z_buffer moved to bonus part

    mlx_hook(game->win, 2, 1L<<0, key_press, game);
    mlx_hook(game->win, 17, 0, close_game, game);
    mlx_loop_hook(game->mlx, render_frame, game);
    
    return (1);
}
