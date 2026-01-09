#include "cub3d_bonus.h"

int	load_texture(t_game *game, int idx, char *path)
{
	t_img	*tex;

	if (idx == -1)  
		tex = &game->door_tex;
	else if (idx == -2)
		tex = &game->sprite_tex[0];
	else if (idx == -3)
		tex = &game->sprite_tex[1];
	else
		tex = &game->wall_tex[idx];

	tex->img = mlx_xpm_file_to_image(game->mlx, path, &tex->width, &tex->height);
	if (!tex->img)
		return (0);
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel, \
		&tex->line_length, &tex->endian);
	return (1);
}

int	init_textures(t_game *game)
{
	if (!load_texture(game, 0, game->tex.no))
		return (0);
	if (!load_texture(game, 1, game->tex.so))
		return (0);
	if (!load_texture(game, 2, game->tex.we))
		return (0);
	if (!load_texture(game, 3, game->tex.ea))
		return (0);
	
	 
	if (!load_texture(game, -1, "./assets/textures/door.xpm")) 
	 
		return (0);

	if (!load_texture(game, -2, "./assets/textures/sprite1.xpm"))  
		return (0);
	if (!load_texture(game, -3, "./assets/textures/sprite2.xpm"))  
		return (0);

	return (1);
}

unsigned int	get_texture_color(t_img *tex, int x, int y)
{
	char	*dst;

	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->height)
		y = tex->height - 1;
	dst = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}
