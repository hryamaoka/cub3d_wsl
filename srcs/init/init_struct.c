#include "cub3d.h"

void	init_parse(t_game *game)
{
	game->tex.no = NULL;
	game->tex.so = NULL;
	game->tex.we = NULL;
	game->tex.ea = NULL;
	game->floor.r = -1;
	game->floor.g = -1;
	game->floor.b = -1;
	game->ceiling.r = -1;
	game->ceiling.g = -1;
	game->ceiling.b = -1;
	game->map.grid = NULL;
	game->map.width = -1;
	game->map.height = -1;
	game->player.x = -1;
	game->player.y = -1;
	game->player.dir_x = -1;
	game->player.dir_y = -1;
	game->player.direction = '\0';
}

void	init_game(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	int i = 0;
	while (i < 4)
	{
		game->wall_tex[i].img = NULL;
		i++;
	}
	init_parse(game);
}
