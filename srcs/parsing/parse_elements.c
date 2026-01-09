#include "cub3d.h"
#include "parse.h"

static int	set_texture(char **texture, char *path)
{
	size_t	len;

	if (*texture)
		return (0);
	len = ft_strlen(path);
	while (len > 0 && (path[len - 1] == '\n' || path[len - 1] == '\r' || \
		path[len - 1] == ' ' || path[len - 1] == '\t'))
	{
		path[len - 1] = '\0';
		len--;
	}
	*texture = ft_strdup(path);
	return (1);
}

int	parse_texture(char *line, t_game *game)
{
	char	**split;
	int		ret;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1])
	{
		free_split(split);
		return (0);
	}
	ret = 0;
	if (!ft_strncmp("NO", split[0], 2))
		ret = set_texture(&game->tex.no, split[1]);
	else if (!ft_strncmp("SO", split[0], 2))
		ret = set_texture(&game->tex.so, split[1]);
	else if (!ft_strncmp("WE", split[0], 2))
		ret = set_texture(&game->tex.we, split[1]);
	else if (!ft_strncmp("EA", split[0], 2))
		ret = set_texture(&game->tex.ea, split[1]);
	free_split(split);
	return (ret);
}

static int	set_rgb(t_color *color, char **param)
{
	if (!param || !param[0] || !param[1] || !param[2])
		return (0);
	color->r = ft_atoi(param[0]);
	color->g = ft_atoi(param[1]);
	color->b = ft_atoi(param[2]);
	if (color->r < 0 || color->r > 255 || \
		color->g < 0 || color->g > 255 || \
		color->b < 0 || color->b > 255)
		return (0);
	return (1);
}

static int	parse_rgb_line(char *line, t_color *color)
{
	char	**param;
	int		ret;

	if (color->r != -1)
		return (0);
	param = ft_split(line, ',');
	ret = set_rgb(color, param);
	free_split(param);
	return (ret);
}

int	parse_color(char *line, t_game *game)
{
	char	**split;
	int		ret;

	split = ft_split(line, ' ');
	if (!split || !split[0] || !split[1])
	{
		free_split(split);
		return (0);
	}
	ret = 0;
	if (!ft_strncmp("F", split[0], 1))
		ret = parse_rgb_line(split[1], &game->floor);
	else if (!ft_strncmp("C", split[0], 1))
		ret = parse_rgb_line(split[1], &game->ceiling);
	free_split(split);
	return (ret);
}
