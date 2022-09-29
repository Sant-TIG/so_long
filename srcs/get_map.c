#include "../incs/so_long.h"

static ssize_t	ft_read(int fd, char *c, int buffer, t_game *game)
{
	//printf("READ\n");
	ssize_t	bytes;

	/*if (game->map_utils->str != NULL)
		ft_print_char_list(game->map_utils->str);*/
	
	bytes = read(fd, c, buffer);
	if (bytes == 0)
		return (0);
	else if (bytes == -1)
		ft_error_exit(READ_ERROR, game);
	if (*c == '\n' && !ft_isdigit(game->map_utils->str->prev->c))//no copia los saltos de linea del mapa
	{
		printf("JN SNJNSA\n");
		ft_error_exit(INVALID_MAP, game);
	}
	else if (bytes == -1)
		ft_error_exit(READ_ERROR, game);
	return (1);
}

static void	ft_read_map(t_map *map_utils, t_game *game)
{
	size_t	len;
	int		i;

	len = 0;
	i = -1;
	while (ft_read(map_utils->fd, &map_utils->c, 1, game) != 0 && ++len)
		ft_insert_end_char(map_utils->c, &map_utils->str);
	map_utils->tmp_map = (char *)malloc(sizeof(char) * len + 1);
	if (!map_utils->tmp_map)
		ft_error_exit(MALLOC_ERROR, game);
	map_utils->tmp = map_utils->str;
	while (map_utils->tmp)
	{
		*(map_utils->tmp_map + ++i) = map_utils->tmp->c;
		map_utils->tmp = map_utils->tmp->next;
	}
	*(map_utils->tmp_map + ++i) = '\0';
	if (i == 0)
		ft_error_exit(EMPTY_MAP, game);
}

static void	ft_check_extension(const char *file, const char *extension, t_game *game)
{
	size_t	len;

	if (!file || !extension)
		ft_error_exit(INVALID_EXTENSION, game);
	if (*extension != '.')
		ft_error_exit(INVALID_EXTENSION, game);
	len = ft_strlen(file) - ft_strlen(extension);
	while(*(file + len) && *extension)
	{
		if (*(file + len) != *extension)
			ft_error_exit(INVALID_EXTENSION, game);
		len++;
		extension++;
	}
}

void	ft_get_map(char *map, t_game *game)
{
	ft_check_extension(map, ".ber", game);
	game->map_utils->fd = open(map, O_RDONLY);
	if (game->map_utils->fd == -1)
		ft_error_exit(INVALID_FILE, game);//checkear perror
	ft_read_map(game->map_utils, game);
	game->map = ft_split(game->map_utils->tmp_map, '\n');
}