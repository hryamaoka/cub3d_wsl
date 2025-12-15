#ifndef PARSE_H
# define PARSE_H

//parse_map.c
int parse_map(int fd, t_game *game);

//parse_utili.c
int is_empty_line(char *line);

//parse_player
int find_player(t_game *game);

#endif