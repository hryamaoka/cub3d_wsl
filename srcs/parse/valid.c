#include "cub3d.h"
#include "parse.h"

int valid_color(t_game *game)
{
    if(game->ceiling.r <= 0 || game->ceiling.r >= 255)
        return (0);
    if(game->ceiling.g <= 0 || game->ceiling.g >= 255)
        return (0);
    if(game->ceiling.b <= 0 || game->ceiling.b >= 255)
        return (0);
    if(game->floor.r <= 0 || game->floor.r >= 255)
        return (0);
    if(game->floor.g <= 0 || game->floor.g >= 255)
        return (0);
    if(game->floor.b <= 0 || game->floor.b >= 255)
        return (0);
    return (1);
}

// int valid_texture(t_game *game)
// {

// }

// int valid_map(t_game *game)
// {

// }