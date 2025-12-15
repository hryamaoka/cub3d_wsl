#include "cub3d.h"
#include "parse.h"

void set_direction(t_game *game)
{
    if (game->player.direction == 'N')
    {
        game->player.dir_x = 0;
        game->player.dir_y = -1;        
    }
    else if (game->player.direction == 'S')
    {
        game->player.dir_x = 0;
        game->player.dir_y = 1;        
    }
    else if (game->player.direction == 'W')
    {
        game->player.dir_x = -1;
        game->player.dir_y = 0;        
    }
    else if (game->player.direction == 'E')
    {
        game->player.dir_x = 1;
        game->player.dir_y = 0;        
    }
    else
        return;
}

int find_player(t_game *game)
{
    int y;
    int x;
    char **grid;
    int count;

    grid = game->map.grid;
    count = 0;
    y = 0;
    while (grid[y])
    {
        x = 0;
        while (grid[y][x])
        {
            if(grid[y][x] == 'N' || grid[y][x] == 'S' || 
            grid[y][x] == 'W' || grid[y][x] == 'E')
            {
                count++;
                game->player.x = x + 0.5;
                game->player.y = y + 0.5;
                game->player.direction = grid[y][x];
                set_direction(game);
            }
            x++;
        }
        y++;
    }
    if (count != 1)
        return (0);
    return (1);
}
