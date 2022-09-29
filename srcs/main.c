#include "../incs/so_long.h"

static void	ft_init(t_game *game)
{
	game->map_utils = (t_map *)malloc(sizeof(t_map));
	if (!game->map_utils)
		ft_error_exit(MALLOC_ERROR, game);
	game->imgs = (t_imgs *)malloc(sizeof(t_imgs));
	if (!game->imgs)
		ft_error_exit(MALLOC_ERROR, game);
	game->map_utils->str = NULL;
	game->map_utils->tmp_map = NULL;
	game->map = NULL;
	game->width = 0;
	game->height = 0;
	game->players = 0;
	game->collectibles = 0;
	game->exits = 0;
	game->player_pos = NULL;
	game->collectibles_pos = NULL;
	game->exit_pos = NULL;
	game->movements = 0;
	game->resolution = 64;
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_init(&game);
	if (argc == 2)
	{
		ft_get_map(argv[1], &game);
		ft_check_map(&game);
		ft_start_game(&game);
		return (0);
	}
	ft_general_free(&game);
	ft_putstr("Error.\nInvalid number of arguments.\n");
	return (0);
}