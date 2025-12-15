#include "cub3d.h"
#include "parse.h"

int get_line_width(char *line)
{
    int width;
    
    width = 0;
    while(line[width] && line[width] != '\n')
        width++;
    return(width);
}

char **change_line_to_map(char **map, char *line, int height)
{
    char **new_map;
    int i;

    new_map = malloc(sizeof(char *) * (height + 2));
    if (!new_map)
        return(NULL); //error msg;

    i = 0;
    while (i < height)
    {
        new_map[i] = map[i];
        i++;
    }
    new_map[height] = line;
    new_map[height + 1] = NULL;

    if (map)
        free(map);
    return(new_map);
}

int parse_map(int fd, t_game *game)
{
    char *line;
    char **temp_map;
    int height;
    int max_width;
    int current_width;

    height = 0;
    max_width = 0;
    temp_map = NULL;
    while ((line = get_next_line(fd)))
    {
        if (is_empty_line(line))
        {
            free(line);
            continue;
        }
        current_width = get_line_width(line);
        if (max_width < current_width)
            max_width = current_width;
        temp_map = change_line_to_map(temp_map, line, height);
        if(!temp_map)
            return(0);
        height++;
    }
    game->map.grid = temp_map;
    game->map.height = height;
    game->map.width = max_width;
    return (1);
}
