#include "cub3d_bonus.h"

#define MM_SCALE 12
#define MM_COLOR_WALL 0xFFFFFF
#define MM_COLOR_PLAYER 0xFF0000
#define MM_COLOR_FLOOR 0x000000
#define MM_OFFSET_X 10
#define MM_OFFSET_Y 10

static void	draw_rect(t_game *game, int x, int y, int size, int color)
{
	int	i;
	int	j;
	int	pixel;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (x + j < 0 || x + j >= game->img.width || y + i < 0 || y + i >= game->img.height)
			{
				j++;
				continue;
			}
			pixel = ((y + i) * game->img.line_length) + \
				((x + j) * (game->img.bits_per_pixel / 8));
			if (pixel >= 0 && pixel < game->img.line_length * game->img.height - 4)  
			{
				game->img.addr[pixel] = color & 0xFF;
				game->img.addr[pixel + 1] = (color >> 8) & 0xFF;
				game->img.addr[pixel + 2] = (color >> 16) & 0xFF;
			}
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	map_y;
	int	map_x;
	int	draw_x;
	int	draw_y;

	 
	map_y = 0;
	while (map_y < game->map.height)
	{
		map_x = 0;
		while (map_x < game->map.width)
		{
			draw_x = MM_OFFSET_X + map_x * MM_SCALE;
			draw_y = MM_OFFSET_Y + map_y * MM_SCALE;
			
			 
			if (!game->map.grid[map_y]) {
				 
				break; 
			}

			if (map_x < (int)ft_strlen(game->map.grid[map_y]))
			{
				if (game->map.grid[map_y][map_x] == '1')
					draw_rect(game, draw_x, draw_y, MM_SCALE, MM_COLOR_WALL);
				else if (game->map.grid[map_y][map_x] != ' ')
					draw_rect(game, draw_x, draw_y, MM_SCALE, MM_COLOR_FLOOR);
			}
			map_x++;
		}
		map_y++;
	}
	 
	int player_size = MM_SCALE / 2;
	int px = MM_OFFSET_X + (int)(game->player.x * MM_SCALE) - player_size / 2;
	int py = MM_OFFSET_Y + (int)(game->player.y * MM_SCALE) - player_size / 2;
	
	draw_rect(game, px, py, player_size, MM_COLOR_PLAYER);
}
