#include "cub3d_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (argc != 2)
		perror_and_exit("Error: usage: ./cub3d file.cub3d", NULL);
	if (!check_filename(argv[1]))
		perror_and_exit("Error: usage: ./cub3d file.cub3d", NULL);
	init_game(&game);
	parse(argv[1], &game);
	if (!init_window(&game))
		perror_and_exit("Error: Could not initialize window", &game);
	if (!init_textures(&game))
		perror_and_exit("Error: Could not load textures", &game);
	init_sprites(&game);
	mlx_loop(game.mlx);
}