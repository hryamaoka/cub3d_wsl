#include "cub3d.h"

static void	draw_ceiling(t_game *game, int x, int draw_start)
{
	int	y;
	int	pixel;

	y = 0;
	while (y < draw_start)
	{
		pixel = (y * game->img.line_length) + (x * (game->img.bits_per_pixel / 8));
		game->img.addr[pixel] = game->ceiling.b;
		game->img.addr[pixel + 1] = game->ceiling.g;
		game->img.addr[pixel + 2] = game->ceiling.r;
		y++;
	}
}

static void	draw_floor(t_game *game, int x, int draw_end)
{
	int	y;
	int	pixel;

	y = draw_end;
	while (y < game->img.height)
	{
		pixel = (y * game->img.line_length) + (x * (game->img.bits_per_pixel / 8));
		game->img.addr[pixel] = game->floor.b;
		game->img.addr[pixel + 1] = game->floor.g;
		game->img.addr[pixel + 2] = game->floor.r;
		y++;
	}
}

void	draw_floor_ceiling(t_game *game, int x, int draw_start, int draw_end)
{
	draw_ceiling(game, x, draw_start);
	draw_floor(game, x, draw_end);
}

void	draw_textured_line(t_game *game, int x, int *draw, t_img *tex, int tex_x)
{
	int				y;
	int				tex_y;
	double			step;
	double			tex_pos;
	int				idx;

	step = 1.0 * tex->height / game->ray.line_height;
	tex_pos = (draw[0] - game->img.height / 2 + game->ray.line_height / 2) * step;
	y = draw[0];
	while (y < draw[1])
	{
		tex_y = (int)tex_pos & (tex->height - 1);
		tex_pos += step;
		idx = (y * game->img.line_length) + (x * (game->img.bits_per_pixel / 8));
		if (idx >= 0 && idx < game->img.line_length * game->img.height)
		{
			game->img.addr[idx] = get_texture_color(tex, tex_x, tex_y) & 0xFF;
			game->img.addr[idx + 1] = (get_texture_color(tex, tex_x, tex_y) >> 8) & 0xFF;
			game->img.addr[idx + 2] = (get_texture_color(tex, tex_x, tex_y) >> 16) & 0xFF;
		}
		y++;
	}
}

int	render_frame(t_game *game)
{
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
