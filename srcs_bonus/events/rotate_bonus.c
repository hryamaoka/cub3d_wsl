#include "cub3d_bonus.h"

#define ROT_SPEED 0.05

void	rotate_player(t_game *game, double angle)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player.dir_x;
	old_plane_x = game->player.plane_x;
	game->player.dir_x = game->player.dir_x * cos(angle) - game->player.dir_y * sin(angle);
	game->player.dir_y = old_dir_x * sin(angle) + game->player.dir_y * cos(angle);
	game->player.plane_x = game->player.plane_x * cos(angle) - game->player.plane_y * sin(angle);
	game->player.plane_y = old_plane_x * sin(angle) + game->player.plane_y * cos(angle);
}

void	rotate_left(t_game *game)
{
	rotate_player(game, -ROT_SPEED);
}

void	rotate_right(t_game *game)
{
	rotate_player(game, ROT_SPEED);
}

int	mouse_handler(int x, int y, t_game *game)
{
	int		center_x;
	int		delta_x;
	double	rot_speed;

	(void)y;
	center_x = game->img.width / 2;
	delta_x = x - center_x;
	if (delta_x == 0)
		return (0);
	rot_speed = delta_x * 0.002;
	rotate_player(game, rot_speed);
	mlx_mouse_move(game->mlx, game->win, center_x, game->img.height / 2);
	return (0);
}
