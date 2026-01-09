#include "cub3d_bonus.h"
#include "parse.h"

static int	is_valid_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'D')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	check_map_chars(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (!is_valid_char(game->map.grid[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	is_walkable(char c)
{
    // Return 1 if the character represents a walkable space or object inside the map
    // (Everything except Wall '1' and Space ' ')
    // Note: 'D' (Door) and '2' (Sprite) are considered "inside" content.
	if (c == '0' || c == '2' || c == 'D')
		return (1);
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	check_map_closed(t_game *game)
{
	int	y;
	int	x;
	char **grid;

	grid = game->map.grid;
	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (is_walkable(grid[y][x]))
			{
				// If a walkable cell is on the edge, map is open -> Error
				if (y == 0 || y == game->map.height - 1 || x == 0 || x == game->map.width - 1)
					return (0);
				// If a walkable cell is adjacent to a space, map is open -> Error
				if (grid[y - 1][x] == ' ' || grid[y + 1][x] == ' ' ||
					grid[y][x - 1] == ' ' || grid[y][x + 1] == ' ')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
