#include "cub3d_bonus.h"

void	init_sprites(t_game *game)
{
	int		y;
	int		x;
	int		i;

	game->num_sprites = 0;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == '2')
				game->num_sprites++;
			x++;
		}
		y++;
	}
	if (game->num_sprites > 0)
	{
		game->sprites = malloc(sizeof(t_sprite) * game->num_sprites);
		if (!game->sprites)
			perror_and_exit("Error: Malloc failed", game);
		y = 0;
		i = 0;
		while (y < game->map.height)
		{
			x = 0;
			while (x < game->map.width)
			{
				if (game->map.grid[y][x] == '2')
				{
					game->sprites[i].x = x + 0.5;
					game->sprites[i].y = y + 0.5;
					game->map.grid[y][x] = '0';  
					i++;
				}
				x++;
			}
			y++;
		}
	}
	else
		game->sprites = NULL;
}

static void	sort_sprites(int *order, double *dist, int amount)
{
	int		i;
	int		j;
	double	tmp_dist;
	int		tmp_order;

	i = 0;
	while (i < amount - 1)
	{
		j = 0;
		while (j < amount - i - 1)
		{
			if (dist[j] < dist[j + 1])
			{
				tmp_dist = dist[j];
				dist[j] = dist[j + 1];
				dist[j + 1] = tmp_dist;
				tmp_order = order[j];
				order[j] = order[j + 1];
				order[j + 1] = tmp_order;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprites(t_game *game)
{
	int		i;
	int		*sprite_order;
	double	*sprite_distance;
	
	if (game->num_sprites == 0)
		return ;

	sprite_order = malloc(sizeof(int) * game->num_sprites);
	sprite_distance = malloc(sizeof(double) * game->num_sprites);

	i = 0;
	while (i < game->num_sprites)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((game->player.x - game->sprites[i].x) * (game->player.x - game->sprites[i].x) + \
			(game->player.y - game->sprites[i].y) * (game->player.y - game->sprites[i].y));
		i++;
	}
	sort_sprites(sprite_order, sprite_distance, game->num_sprites);

	 
	int frame = (game->frame_count / 10) % 2;  
	t_img *tex = &game->sprite_tex[frame];

	i = 0;
	while (i < game->num_sprites)
	{
		 
		double sprite_x = game->sprites[sprite_order[i]].x - game->player.x;
		double sprite_y = game->sprites[sprite_order[i]].y - game->player.y;

		 
		 
		 
		 

		double inv_det = 1.0 / (game->player.plane_x * game->player.dir_y - game->player.dir_x * game->player.plane_y);
		double transform_x = inv_det * (game->player.dir_y * sprite_x - game->player.dir_x * sprite_y);
		double transform_y = inv_det * (-game->player.plane_y * sprite_x + game->player.plane_x * sprite_y);

		int sprite_screen_x = (int)((game->img.width / 2) * (1 + transform_x / transform_y));

		 
		int sprite_height = abs((int)(game->img.height / (transform_y)));  
		
		int draw_start_y = -sprite_height / 2 + game->img.height / 2;
		if (draw_start_y < 0) draw_start_y = 0;
		int draw_end_y = sprite_height / 2 + game->img.height / 2;
		if (draw_end_y >= game->img.height) draw_end_y = game->img.height - 1;

		 
		int sprite_width = abs((int)(game->img.height / (transform_y)));
		int draw_start_x = -sprite_width / 2 + sprite_screen_x;
		if (draw_start_x < 0) draw_start_x = 0;
		int draw_end_x = sprite_width / 2 + sprite_screen_x;
		if (draw_end_x >= game->img.width) draw_end_x = game->img.width - 1;

		 
		int stripe;
		for (stripe = draw_start_x; stripe < draw_end_x; stripe++)
		{
			int tex_x = (int)(256 * (stripe - (-sprite_width / 2 + sprite_screen_x)) * tex->width / sprite_width) / 256;
			
			if (transform_y > 0 && stripe > 0 && stripe < game->img.width && transform_y < game->z_buffer[stripe])
			{
				for (int y = draw_start_y; y < draw_end_y; y++)
				{
					int d = (y) * 256 - game->img.height * 128 + sprite_height * 128;
					int tex_y = ((d * tex->height) / sprite_height) / 256;
					unsigned int color = get_texture_color(tex, tex_x, tex_y);
					if ((color & 0x00FFFFFF) != 0)  
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					 
					if (color != 0xFF000000 && color != 0)  
					 
					{
						int pixel = (y * game->img.line_length) + (stripe * (game->img.bits_per_pixel / 8));
						game->img.addr[pixel] = color & 0xFF;
						game->img.addr[pixel + 1] = (color >> 8) & 0xFF;
						game->img.addr[pixel + 2] = (color >> 16) & 0xFF;
					}
				}
			}
		}
		i++;
	}
	free(sprite_order);
	free(sprite_distance);
}
