#include "cub3d.h"

void init_parse(t_game *game)
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

void init_game(t_game *game)
{
    game->mlx = NULL;
    game->win = NULL;
    game->img = NULL;
    init_parse(game);
}

int main (int argc, char* argv[])
{
    t_game game;

    if (argc != 2)
        perror_and_exit("Error: usage: ./cub3d file.cub3d", NULL);
    
    if (!check_filename(argv[1]))
         perror_and_exit("Error: usage: ./cub3d file.cub3d", NULL);
    
    init_game(&game);
    parse(argv[1],&game);


    //printf test
    //textureが入ってるか
    printf("%s\n", game.tex.no);
    printf("%s\n", game.tex.so);
    printf("%s\n", game.tex.we);
    printf("%s\n", game.tex.ea);
    //floor color
    printf("%d,%d,%d\n", game.floor.r, game.floor.g, game.floor.b);
    //ceiling color
    printf("%d,%d,%d\n", game.ceiling.r, game.ceiling.g, game.ceiling.b);
    //map grid
    int i = 0; 
    while(i < game.map.height)
    {
        printf("%s", game.map.grid[i++]);
    }
    printf("\n %f,%f,%f,%f,%c\n", game.player.x, game.player.y, game.player.dir_x, game.player.dir_y, game.player.direction);
}