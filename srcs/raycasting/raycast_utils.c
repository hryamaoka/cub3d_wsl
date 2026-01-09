#include "cub3d.h"

void	perform_dda(t_game *game)
{
	while (game->ray.hit == 0)
	{
		if (game->ray.side_dist_x < game->ray.side_dist_y)
		{
			game->ray.side_dist_x += game->ray.delta_dist_x;
			game->ray.map_x += game->ray.step_x;
			game->ray.side = 0;
		}
		else
		{
			game->ray.side_dist_y += game->ray.delta_dist_y;
			game->ray.map_y += game->ray.step_y;
			game->ray.side = 1;
		}
		if (game->ray.map_x < 0 || game->ray.map_x >= game->map.width || \
			game->ray.map_y < 0 || game->ray.map_y >= game->map.height)
		{
			game->ray.hit = 1;
			break ;
		}
		if (game->map.grid[game->ray.map_y][game->ray.map_x] == '1')
			game->ray.hit = 1;
	}
}

void	select_texture(t_game *game, t_img **tex)
{
	if (game->ray.side == 0)
	{
		if (game->ray.ray_dir_x > 0)
			*tex = &game->wall_tex[3];
		else
			*tex = &game->wall_tex[2];
	}
	else
	{
		if (game->ray.ray_dir_y > 0)
			*tex = &game->wall_tex[1];
		else
			*tex = &game->wall_tex[0];
	}
}
