#include "../incs/so_long.h"

static void	ft_check_conditions(t_game *game)
{
	//printf("CHECK CONDITIONS\n");
	size_t	i;
	int		j;
	int		e;
	int		p;

	i = 0;
	e = 0;
	p = 0;
	while (*(game->map + ++i) && game->height - 1 > i)
	{
		j = -1;
		while (*(*(game->map + i) + ++j))
		{
			if (*(*(game->map + i) + j) != '0' && *(*(game->map + i) + j) != '1' && *(*(game->map + i) + j) != 'C' && *(*(game->map + i) + j) != 'E' && *(*(game->map + i) + j) != 'P')
				ft_error_exit(INVALID_MAP);
			if (*(*(game->map + i) + j) == 'C' && ++game->collectibles > 0)
				ft_insert_end_coord(j, i, &game->collectibles_pos, game->collectibles);
			else if (*(*(game->map + i) + j) == 'E' && ++game->exits > 0)
				ft_insert_end_coord(j, i, &game->exit_pos, e);
			else if (*(*(game->map + i) + j)== 'P' && ++p > 0)
				ft_insert_end_coord(j, i, &game->player_pos, p);
		}
	}
	if (p > 1)
			ft_error_exit(INVALID_MAP);
	if (game->collectibles == 0 || game->exits == 0 || p == 0)
			ft_error_exit(INVALID_MAP);
}


static void	ft_check_walls(t_game *game)
{
	//printf("CHECK WALLS\n");
	int		i;
	int		j;

	i = 0;
	j = -1;
	game->height = ft_get_height(game->map);
	//printf("%c\n", *(*(game->map + i) + ++j));
	while (*(*(game->map + i) + ++j))
	{
		if (*(*(game->map + i) + j) != '1' && *(*(game->map + i) + j) != '\0')
			ft_error_exit(INVALID_MAP);
	}
	while (game->height - 1 > (size_t)++i)
	{
		if (ft_strnchr(*(game->map + i), '1', 1) == 0)
			ft_error_exit(INVALID_MAP);
		if (ft_strrnchr(*(game->map + i), '1', 1) == 0)
			ft_error_exit(INVALID_MAP);
	}
	j = -1;
	while (*(*(game->map + i) + ++j))
	{
		if (*(*(game->map + i) + j) != '\0' && *(*(game->map + i) + j) != '1')
			ft_error_exit(INVALID_MAP);
	}
}

static void	ft_check_rectangle(t_game *game)
{
	//printf("CHECK RECTANGLE\n");
	size_t	line_len;
	int		i;

	i = -1;
	game->width = ft_strlen(*(game->map + ++i));
	line_len = ft_strlen(*(game->map + ++i));
	while (*(game->map + ++i) && game->width == line_len)
		line_len = ft_strlen(*(game->map + i));
	if (*(game->map + i) != NULL || game->width != line_len)
		ft_error_exit(INVALID_MAP);
}

void	ft_check_map(t_game *game)
{
	ft_check_rectangle(game);
	//ft_print2d_str(map);
	ft_check_walls(game);
	ft_check_conditions(game);
}