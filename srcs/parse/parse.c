#include "cub3d.h"
#include "parse.h"

int parse_texture(char *line, t_game *game)
{
    char **split;
    char *newline;

    split = ft_split(line,' ');
    if(!split || !split[0] || !split[1])
    {
        free_split(split);
        return(0);
    }
    newline = ft_strchr(split[1], '\n');
    if (newline)
        *newline = '\0';
    if (!ft_strncmp("NO",split[0],2) && !game->tex.no)
        game->tex.no = ft_strdup(split[1]);
    else if (!ft_strncmp("SO",split[0],2) && !game->tex.so)
        game->tex.so = ft_strdup(split[1]);
    else if (!ft_strncmp("WE",split[0],2) && !game->tex.we)
        game->tex.we = ft_strdup(split[1]);
    else if (!ft_strncmp("EA",split[0],2) && !game->tex.ea)
        game->tex.ea = ft_strdup(split[1]);
    else
    {
        free_split(split);
        return (0);
    }
    free_split(split);
    return(1);
}

int parse_color(char *line, t_game *game)
{
    char **split;
    char **param;

    param = NULL;
    split = ft_split(line,' ');
    if(!split || !split[0] || !split[1])
    {
        free_split(split);
        return(0);
    }

    if (!ft_strncmp("F",split[0],1))
    {
        if (game->floor.r < 0 || game->floor.g < 0 || game->floor.b < 0)
        {
            param = ft_split(split[1],',');
            if (!param || !param[0]|| !param[1]|| !param[2])
            {
                free_split(split);
                free_split(param);
                return (0);
            }
            game->floor.r = ft_atoi(param[0]);
            game->floor.g = ft_atoi(param[1]);
            game->floor.b = ft_atoi(param[2]);
        }
        else
            return (free_split(split), 0);
    }
    else if (!ft_strncmp("C",split[0],1))
    {
        if (game->ceiling.r < 0 || game->ceiling.g < 0 || game->ceiling.b < 0)
        {
            param = ft_split(split[1],',');
            if (!param || !param[0]|| !param[1]|| !param[2])
            {
                free_split(split);
                free_split(param);
                return (0);
            }
            game->ceiling.r = ft_atoi(param[0]);
            game->ceiling.g = ft_atoi(param[1]);
            game->ceiling.b = ft_atoi(param[2]);
        }
        else
            return (free_split(split), 0);
    }
    free_split(split);
    if (param)
        free_split(param);
    return(1);
}

int parse_elem(int fd, t_game *game)
{
    char *line;
    int elem_count;

    elem_count = 0;
    while(elem_count < 6)
    {
        line = get_next_line(fd);
        if (!line)
            return(0); //error;
        if (is_empty_line(line))
        {
            free(line);
            continue;
        }
        if (parse_texture(line, game))
            elem_count++;
        else if(parse_color(line, game))
            elem_count++;
        else
            return (free(line), 0);
        free(line);
    }
    return (1);
}

void parse(char *filename, t_game *game)
{
    int fd;
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        return; //need Error msg;
    }
    if (!parse_elem(fd, game))
    {
        return; //Error msg;
    }
    if (!parse_map(fd, game))
    {
        return;
    }
    if (!find_player(game))
    {
        return;
    }
}