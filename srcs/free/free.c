#include "cub3d.h"

void free_split(char** split)
{
    int i;

    i = 0;
    if (!split)
        return;
    while (split[i])
        free(split[i++]);
    free(split);
}

void free_all(t_game *game)
{
    if (game->tex.no) free(game->tex.no);
    if (game->tex.so) free(game->tex.so);
    if (game->tex.we) free(game->tex.we);
    if (game->tex.ea) free(game->tex.ea);
    if (game->map.grid) free_split(game->map.grid);
	if (game->mlx)
	{
		if (game->img)
			mlx_destroy_image(game->mlx, game->img);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		// mlx_destroy_display(game->mlx);
        free(game->mlx);
	}
}
