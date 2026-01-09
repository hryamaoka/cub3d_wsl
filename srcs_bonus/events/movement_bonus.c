#include "cub3d_bonus.h"

#define MOVE_SPEED 0.1
#define COLLISION_BUFFER 0.2

void	move_forward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = game->player.x + game->player.dir_x * MOVE_SPEED;
	new_y = game->player.y + game->player.dir_y * MOVE_SPEED;
	if (game->player.dir_x > 0)
		check_x = new_x + COLLISION_BUFFER;
	else
		check_x = new_x - COLLISION_BUFFER;
	if (game->player.dir_y > 0)
		check_y = new_y + COLLISION_BUFFER;
	else
		check_y = new_y - COLLISION_BUFFER;
	if (new_x >= 0 && new_x < game->map.width && \
		game->map.grid[(int)game->player.y][(int)check_x] != '1' && \
		game->map.grid[(int)game->player.y][(int)check_x] != 'D')
		game->player.x = new_x;
	if (new_y >= 0 && new_y < game->map.height && \
		game->map.grid[(int)check_y][(int)game->player.x] != '1' && \
		game->map.grid[(int)check_y][(int)game->player.x] != 'D')
		game->player.y = new_y;
}

void	move_backward(t_game *game)
{
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	new_x = game->player.x - game->player.dir_x * MOVE_SPEED;
	new_y = game->player.y - game->player.dir_y * MOVE_SPEED;
	if (-game->player.dir_x > 0)
		check_x = new_x + COLLISION_BUFFER;
	else
		check_x = new_x - COLLISION_BUFFER;
	if (-game->player.dir_y > 0)
		check_y = new_y + COLLISION_BUFFER;
	else
		check_y = new_y - COLLISION_BUFFER;
	if (new_x >= 0 && new_x < game->map.width && \
		game->map.grid[(int)game->player.y][(int)check_x] != '1' && \
		game->map.grid[(int)game->player.y][(int)check_x] != 'D')
		game->player.x = new_x;
	if (new_y >= 0 && new_y < game->map.height && \
		game->map.grid[(int)check_y][(int)game->player.x] != '1' && \
		game->map.grid[(int)check_y][(int)game->player.x] != 'D')
		game->player.y = new_y;
}

void	move_left(t_game *game)
{
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	dx = game->player.dir_y;
	dy = -game->player.dir_x;
	new_x = game->player.x + dx * MOVE_SPEED;
	new_y = game->player.y + dy * MOVE_SPEED;
	if (dx > 0)
		check_x = new_x + COLLISION_BUFFER;
	else
		check_x = new_x - COLLISION_BUFFER;
	if (dy > 0)
		check_y = new_y + COLLISION_BUFFER;
	else
		check_y = new_y - COLLISION_BUFFER;
	if (new_x >= 0 && new_x < game->map.width && \
		game->map.grid[(int)game->player.y][(int)check_x] != '1' && \
		game->map.grid[(int)game->player.y][(int)check_x] != 'D')
		game->player.x = new_x;
	if (new_y >= 0 && new_y < game->map.height && \
		game->map.grid[(int)check_y][(int)game->player.x] != '1' && \
		game->map.grid[(int)check_y][(int)game->player.x] != 'D')
		game->player.y = new_y;
}

void	move_right(t_game *game)
{
	double	dx;
	double	dy;
	double	new_x;
	double	new_y;
	double	check_x;
	double	check_y;

	dx = -game->player.dir_y;
	dy = game->player.dir_x;
	new_x = game->player.x + dx * MOVE_SPEED;
	new_y = game->player.y + dy * MOVE_SPEED;
	if (dx > 0)
		check_x = new_x + COLLISION_BUFFER;
	else
		check_x = new_x - COLLISION_BUFFER;
	if (dy > 0)
		check_y = new_y + COLLISION_BUFFER;
	else
		check_y = new_y - COLLISION_BUFFER;
	if (new_x >= 0 && new_x < game->map.width && \
		game->map.grid[(int)game->player.y][(int)check_x] != '1' && \
		game->map.grid[(int)game->player.y][(int)check_x] != 'D')
		game->player.x = new_x;
	if (new_y >= 0 && new_y < game->map.height && \
		game->map.grid[(int)check_y][(int)game->player.x] != '1' && \
		game->map.grid[(int)check_y][(int)game->player.x] != 'D')
		game->player.y = new_y;
}
