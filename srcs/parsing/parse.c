#include "cub3d.h"
#include "parse.h"

#include "cub3d.h"
#include "parse.h"

int	process_elem_line(char *line, t_game *game, int *count)
{
	if (is_empty_line(line))
	{
		free(line);
		return (1);
	}
	if (parse_texture(line, game))
		(*count)++;
	else if (parse_color(line, game))
		(*count)++;
	else
	{
		free(line);
		return (0);
	}
	free(line);
	return (1);
}

int	parse_elem(int fd, t_game *game)
{
	char	*line;
	int		elem_count;

	elem_count = 0;
	while (elem_count < 6)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		if (!process_elem_line(line, game, &elem_count))
			return (0);
	}
	return (1);
}

void	parse(char *filename, t_game *game)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror_and_exit("Error: Could not open file", game);
		return ;
	}
	if (!parse_elem(fd, game))
	{
		perror_and_exit("Error: Invalid elements", game);
		return ;
	}
	if (!parse_map(fd, game))
		perror_and_exit("Error: Invalid map", game);
	if (!check_map_chars(game))
		perror_and_exit("Error: Invalid map characters", game);
	if (!check_map_closed(game))
		perror_and_exit("Error: Map is not closed", game);
	if (!find_player(game))
		perror_and_exit("Error: Invalid player", game);
}