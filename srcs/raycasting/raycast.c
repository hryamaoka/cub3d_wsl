#include "cub3d.h"

static void	init_ray_step_x(t_game *game)
{
	if (game->ray.ray_dir_x < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->player.x - game->ray.map_x) * \
			game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.map_x + 1.0 - game->player.x) * \
			game->ray.delta_dist_x;
	}
}

static void	init_ray_step_y(t_game *game)
{
	if (game->ray.ray_dir_y < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->player.y - game->ray.map_y) * \
			game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.map_y + 1.0 - game->player.y) * \
			game->ray.delta_dist_y;
	}
}

void	init_ray(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)game->img.width - 1;
	game->ray.ray_dir_x = game->player.dir_x + game->player.plane_x * camera_x;
	game->ray.ray_dir_y = game->player.dir_y + game->player.plane_y * camera_x;
	game->ray.map_x = (int)game->player.x;
	game->ray.map_y = (int)game->player.y;
	game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x);
	game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y);
	game->ray.hit = 0;
	init_ray_step_x(game);
	init_ray_step_y(game);
}

static void	calc_wall_and_tex(t_game *game, int *draw, t_img **tex, int *tex_x)
{
	double	wall_x;

	if (game->ray.side == 0)
		game->ray.perp_wall_dist = (game->ray.map_x - game->player.x + \
			(1 - game->ray.step_x) / 2) / game->ray.ray_dir_x;
	else
		game->ray.perp_wall_dist = (game->ray.map_y - game->player.y + \
			(1 - game->ray.step_y) / 2) / game->ray.ray_dir_y;
	game->ray.line_height = (int)(game->img.height / game->ray.perp_wall_dist);
	draw[0] = -game->ray.line_height / 2 + game->img.height / 2;
	if (draw[0] < 0)
		draw[0] = 0;
	draw[1] = game->ray.line_height / 2 + game->img.height / 2;
	if (draw[1] >= game->img.height)
		draw[1] = game->img.height - 1;
	if (game->ray.side == 0)
		wall_x = game->player.y + game->ray.perp_wall_dist * game->ray.ray_dir_y;
	else
		wall_x = game->player.x + game->ray.perp_wall_dist * game->ray.ray_dir_x;
	wall_x -= floor(wall_x);
	select_texture(game, tex);
	*tex_x = (int)(wall_x * (double)(*tex)->width);
	if ((game->ray.side == 0 && game->ray.ray_dir_x > 0) || \
		(game->ray.side == 1 && game->ray.ray_dir_y < 0))
		*tex_x = (*tex)->width - *tex_x - 1;
}

void	raycast(t_game *game)
{
	int		x;
	t_img	*tex;
	int		tex_x;
	int		draw[2];

	x = 0;
	while (x < game->img.width)
	{
		init_ray(game, x);
		perform_dda(game);
		calc_wall_and_tex(game, draw, &tex, &tex_x);
		draw_floor_ceiling(game, x, draw[0], draw[1]);
		draw_textured_line(game, x, draw, tex, tex_x);
		x++;
	}
}
