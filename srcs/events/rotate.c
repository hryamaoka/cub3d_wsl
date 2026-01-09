#include "cub3d.h"

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

// mouse_handler removed for mandatory part
