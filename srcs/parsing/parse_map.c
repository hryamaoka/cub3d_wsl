#include "cub3d.h"
#include "parse.h"



char **change_line_to_map(char **map, char *line, int height)
{
    char **new_map;
    int i;

    new_map = malloc(sizeof(char *) * (height + 2));
    if (!new_map)
        return(NULL);  

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

static int	process_map_line(char *line, char ***temp_map, int *height, int *max_width)
{
	int	current_width;

	char *newline;

	if (is_empty_line(line))
	{
		free(line);
		return (1);
	}
	 
	newline = ft_strchr(line, '\n');
	if (newline) *newline = '\0';
	newline = ft_strchr(line, '\r');
	if (newline) *newline = '\0';

	current_width = ft_strlen(line);  
	if (*max_width < current_width)
		*max_width = current_width;
	*temp_map = change_line_to_map(*temp_map, line, *height);
	if (!*temp_map)
		return (0);
	(*height)++;
	return (1);
}

int	parse_map(int fd, t_game *game)
{
	char	*line;
	char	**temp_map;
	int		height;
	int		max_width;

	height = 0;
	max_width = 0;
	temp_map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!process_map_line(line, &temp_map, &height, &max_width))
			return (0);
	}
	game->map.height = height;
	game->map.width = max_width;

	 
	int i = 0;
	while (i < height)
	{
		int len = ft_strlen(temp_map[i]);
		// Always normalize to max_width to ensure clean memory and consistent shape
		char *new_row = malloc(max_width + 1);
		if (!new_row) return (0);
		ft_memset(new_row, ' ', max_width);
		new_row[max_width] = '\0';
		ft_memcpy(new_row, temp_map[i], len);
		free(temp_map[i]);
		temp_map[i] = new_row;
		i++;
	}
	game->map.grid = temp_map;
	return (1);
}
