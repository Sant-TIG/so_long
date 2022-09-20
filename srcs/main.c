#include "../incs/so_long.h"

/*
void	ft_treat_empty_map(t_map *map_utils)
{
	if (!*map_utils->map)
	{
		ft_free_list(map_utils);
		free(tmp_map);
		printf("Invalid map (Empty map)\n");
		exit (1);
	}
}*/

/*void	ft_get_images(t_game *game)
{
	mlx_xpm_file_to_image(mlxptr, imagedirectory, size, size);
}

void	ft_delete_images(t_game *game)
{
	mlx_destroy_image(mlxptr, imageptr);
}

void	ft_draw_exit(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_utils->map[++i])
	{
		j = -1;
		while (game->map_utils->map[i][++j])
		{
			if (game->map_utils->map[i][j] == 'E')
				mlx_put_image_to_window(mlxptr, winptr, exitptr, i * size, j*size);
		}
	}
}

void	ft_draw_player(t_game *game)
{
	mlx_put_image_to_window(mlxptr, winptr, playerptr, game->player_x * size, game->player_y*size);
}

void	ft_draw_collectibles(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_utils->map[++i])
	{
		j = -1;
		while (game->map_utils->map[i][++j])
		{
			if (game->map_utils->map[i][j] == 'C')
				mlx_put_image_to_window(mlxptr, winptr, collectibleptr, i * size, j*size);
		}
	}
}

void	ft_draw_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_utils->map[++i])
	{
		j = -1;
		while (game->map_utils->map[i][++j])
		{
			if (game->map_utils->map[i][j] == '1')
				mlx_put_image_to_window(mlxptr, winptr, wallptr, i * size, j * size);
		}
	}
}

void	ft_draw_background(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map_utils->map[++i])
	{
		j = -1;
		while (game->map_utils->map[i[++j]])
			mlx_put_image_to_window(punteromlx, punteroventana, punteroimagen, ubicacionpixelx * tamaño, ubicacionpixely * tamaño);
	}
}

void	ft_draw_map(t_game *game)
{
	ft_draw_background(game);
	ft_draw_walls(game);
	ft_draw_collectibles(game);
	ft_draw_exit(game);
	ft_draw_player(game);
}
*/



void	ft_init_game(t_game *game)
{
	//printf("INIT_GAME\n");
	game->map_utils = (t_map *)malloc(sizeof(t_map));
	if (!game->map_utils)
		ft_error_exit(INVALID_MAP);
	game->imgs = (t_imgs *)malloc(sizeof(t_imgs));
	if (!game->imgs)
		ft_error_exit(MALLOC_ERROR);
	game->player_pos = NULL;
	game->collectibles_pos = NULL;
	game->exit_pos = NULL;
	game->movements = 0;
	game->width = 0;
	game->height = 0;
	game->collectibles = 0;
	game->exits = 0;
	game->resolution = 64;

	game->back_draw_id = -1;
	game->coll_draw_id = -1;
	game->wall_draw_id = -1;
}
/*
void	ft_free_map_utils(t_game *game)
{

}*/

void	ft_general_free(t_game *game)
{
	/*if (game->map_utils)
		ft_free_map_utils(game->map_utils);*/
	if (game->player_pos)
		ft_free_coord_list(game->player_pos);
	if (game->collectibles_pos)
		ft_free_coord_list(game->collectibles_pos);
	if (game->exit_pos)
		ft_free_coord_list(game->exit_pos);
	ft_free_2d_str(game->map);
}

int	ft_end_game(t_game *game)
{
	ft_general_free(game);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	//free(game->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}
/*
void	ft_start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width * game->resolution, game->height * game->resolution, "so_long");
	mlx_hook(game->window, 17, 1L << 17, ft_end_game, &game);
	mlx_loop(game->mlx);
	//free(game->mlx);
	//ft_end_game(game);
	
}*/

void	ft_get_images(t_game *game)
{
	printf("GET IMAGES\n");
	game->imgs->background = mlx_xpm_file_to_image(game->mlx, "./imgs/background.xpm", &game->resolution, &game->resolution);
	if (!game->imgs->background)
	{
		printf("error at takes images\n");
		exit (-1);
	}
	printf("back direct = %p\n", game->imgs->background);
	game->imgs->collectible = mlx_xpm_file_to_image(game->mlx, "./imgs/coin.xpm", &game->resolution, &game->resolution);
	game->imgs->exit = mlx_xpm_file_to_image(game->mlx, "./imgs/exit.xpm", &game->resolution, &game->resolution);
	game->imgs->player = mlx_xpm_file_to_image(game->mlx, "./imgs/player.xpm", &game->resolution, &game->resolution);
	game->imgs->wall = mlx_xpm_file_to_image(game->mlx, "./imgs/wall.xpm", &game->resolution, &game->resolution);
}

void	ft_draw_background(t_game *game)
{
	printf("DRAW BACKGROUND\n");
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
			mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, j * game->resolution, i * game->resolution);
	}
}

void	ft_draw_walls(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->window, game->imgs->wall, j * game->resolution, i * game->resolution);

		}
	}
}

void	ft_draw_exit(t_game *game)
{
	int	i;
	t_pos	*tmp;

	i = -1;
	tmp = game->exit_pos;
	while (++i < game->exits && tmp)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->exit, tmp->coord[0] * game->resolution, tmp->coord[1] * game->resolution);
		tmp = tmp->next;
	}
}

void	ft_draw_collectible(t_game *game)
{
	int	i;
	t_pos	*tmp;

	i = -1;
	tmp = game->collectibles_pos;
	while (++i < game->collectibles && tmp)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->collectible, tmp->coord[0] * game->resolution, tmp->coord[1] * game->resolution);
		tmp = tmp->next;	
	}
}

void	ft_draw_map(t_game *game)
{
	ft_draw_background(game);
	ft_draw_walls(game);
	mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
	ft_draw_exit(game);
	ft_draw_collectible(game);
}

void	ft_delete_nth_node(t_pos **coord, int pos)
{
	t_pos	*tmp;
	t_pos	*prev;

	tmp = *coord;
	prev = *coord;
	if (pos == 1)
	{
		*coord = tmp->next;
		free(tmp);
	}
	while (tmp && --pos)
		tmp = tmp->next;
	while (prev->next != tmp)
		prev = prev->next;
	prev->next = tmp->next;
	free(tmp);
}

void	ft_search_collectible(t_game *game, int x, int y)
{
	t_pos	*tmp;
	int		pos;

	pos = -1;
	tmp = game->collectibles_pos;
	while (tmp && ++pos)
	{
		if (tmp->coord[0] == x && tmp->coord[1] == y)
			ft_delete_nth_node(&game->collectibles_pos, pos);
		else
			tmp = tmp->next;
	}

}

void	ft_move_up(t_game *game)
{
	char	next_pos;

	//game->player_pos->coord[0]++;
	next_pos = game->map[game->player_pos->coord[1] + 1][game->player_pos->coord[0]];
	if (next_pos == '1')
		return ;
	if (next_pos == '0')
	{
		game->movements++;
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->resolution * game->player_pos->coord[0], game->resolution * game->player_pos->coord[1]);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->resolution * game->player_pos->coord[0], game->resolution * --game->player_pos->coord[1]);
	}
	else if (next_pos == 'C' && --game->collectibles)
	{
		ft_search_collectible(game, game->player_pos->coord[0], game->player_pos->coord[1]);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->player_pos->coord[0] * game->resolution, --game->player_pos->coord[1] * game->resolution);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
	}
	else if (next_pos == 'E' && game->collectibles == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->player_pos->coord[0] * game->resolution, --game->player_pos->coord[1] * game->resolution);	
		game->movements++;
		ft_end_game(game);
	}
}

void	ft_move_left(t_game *game)
{
	char	next_pos;

	//game->player_pos->coord[0]++;
	next_pos = game->map[game->player_pos->coord[1]][game->player_pos->coord[0] - 1];
	if (next_pos == '1')
		return ;
	if (next_pos == '0')
	{
		game->movements++;
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->resolution * game->player_pos->coord[0], game->resolution * game->player_pos->coord[1]);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->resolution * --game->player_pos->coord[0], game->resolution * game->player_pos->coord[1]);
	}
	else if (next_pos == 'C' && --game->collectibles)
	{
		ft_search_collectible(game, game->player_pos->coord[0], game->player_pos->coord[1]);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, --game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
	}
	else if (next_pos == 'E' && game->collectibles == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, --game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);	
		game->movements++;
		ft_end_game(game);
	}
}

void	ft_move_down(t_game *game)
{
	char	next_pos;

	//game->player_pos->coord[0]++;
	next_pos = game->map[game->player_pos->coord[1] + 1][game->player_pos->coord[0]];
	if (next_pos == '1')
		return ;
	if (next_pos == '0')
	{
		game->movements++;
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->resolution * game->player_pos->coord[0], game->resolution * game->player_pos->coord[1]);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->resolution * game->player_pos->coord[0], game->resolution * ++game->player_pos->coord[1]);
	}
	else if (next_pos == 'C' && --game->collectibles)
	{
		ft_search_collectible(game, game->player_pos->coord[0], game->player_pos->coord[1]);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->player_pos->coord[0] * game->resolution, ++game->player_pos->coord[1] * game->resolution);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
	}
	else if (next_pos == 'E' && game->collectibles == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->player_pos->coord[0] * game->resolution, ++game->player_pos->coord[1] * game->resolution);	
		game->movements++;
		ft_end_game(game);
	}
}

void	ft_move_right(t_game *game)
{
	char	next_pos;

	//game->player_pos->coord[0]++;
	next_pos = game->map[game->player_pos->coord[1]][game->player_pos->coord[0] + 1];
	if (next_pos == '1')
		return ;
	if (next_pos == '0')
	{
		game->movements++;
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->resolution * game->player_pos->coord[0], game->resolution * game->player_pos->coord[1]);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->resolution * ++game->player_pos->coord[0], game->resolution * game->player_pos->coord[1]);
	}
	else if (next_pos == 'C' && --game->collectibles)
	{
		ft_search_collectible(game, game->player_pos->coord[0], game->player_pos->coord[1]);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->background, ++game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);
	}
	else if (next_pos == 'E' && game->collectibles == 0)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, ++game->player_pos->coord[0] * game->resolution, game->player_pos->coord[1] * game->resolution);	
		game->movements++;
		ft_end_game(game);
	}
}

int	ft_process_input(int keycode, t_game *game)
{
	if (keycode == 13 || keycode == 126)// W
		ft_move_up(game);
	if (keycode == 0 || keycode == 123) // A
		ft_move_left(game);
	if (keycode == 1 || keycode == 125) // S
		ft_move_down(game);
	if (keycode == 2 || keycode == 124) // D
		ft_move_right(game);
	if (keycode == 53) // ESC
		ft_end_game(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_init_game(&game);
	if (argc == 2)
	{
		ft_get_map(argv[1], &game);
		ft_check_map(&game);
		//printf("%zu y %zu\n", game.height, game.width);
		//ft_start_game(&game);
		game.mlx = mlx_init();
		game.window = mlx_new_window(game.mlx, game.width * game.resolution, game.height * game.resolution, "so_long");
		ft_get_images(&game);
		ft_draw_map(&game);
		mlx_hook(game.window, 2, 1L << 0, ft_process_input, &game);
		mlx_hook(game.window, 17, 1L << 17, ft_end_game, &game);
		mlx_loop(game.mlx);
		//ft_general_free(&game);
		//mlx_hook(game.window, 17, 1L << 17, ft_end_game, &game);
		//ft_print_coord_list(game.player_pos);
		//ft_print_coord_list(game.collectibles_pos);
		//ft_print_coord_list(game.exit_pos);
		//ft_end_game(&game);
		//ft_start_game(game.map_utils.map, &game);
		//mlx_hook(winptr, type1, type2, function, atrribute);4
		return (0);
	}
	ft_error_exit(INVALID_ARGUMENTS);
}