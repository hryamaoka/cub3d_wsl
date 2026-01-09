#ifndef PARSE_H
# define PARSE_H

 
int parse_map(int fd, t_game *game);

 
int is_empty_line(char *line);

 
int parse_texture(char *line, t_game *game);
int parse_color(char *line, t_game *game);

 
int find_player(t_game *game);

int check_map_chars(t_game *game);
int check_map_closed(t_game *game);

#endif