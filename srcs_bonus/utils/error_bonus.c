#include "cub3d_bonus.h"

void perror_and_exit(char *msg, t_game *game)
{
    ft_putendl_fd(msg, STDERR_FILENO);
    if(game != NULL)
        free_all(game);
    exit(1);
}