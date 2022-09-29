#include "../incs/so_long.h"

int	ft_end_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->imgs->background);
	mlx_destroy_image(game->mlx, game->imgs->collectible);
	mlx_destroy_image(game->mlx, game->imgs->wall);
	mlx_destroy_image(game->mlx, game->imgs->exit);
	mlx_destroy_image(game->mlx, game->imgs->player);
	mlx_clear_window(game->mlx, game->window);
	mlx_destroy_window(game->mlx, game->window);
	ft_general_free(game);
	free(game->imgs);
	exit (1);
}

static int	ft_process_keycode(int keycode, t_game *game)
{
	//ft_print2d_str(game->map);
	if (keycode == 13 || keycode == 126)// W
		ft_move_up(&game);
	if (keycode == 0 || keycode == 123) // A
		ft_move_left(&game);
	if (keycode == 1 || keycode == 125) // S
		ft_move_down(&game);
	if (keycode == 2 || keycode == 124) // D
		ft_move_right(&game);
	if (keycode == 53) // ESC
		ft_end_game(game);
	return (0);
}

static void	ft_mlx_xpm_file_to_img(void	**ptr, char *dir, t_game *game)
{
	*ptr = mlx_xpm_file_to_image(game->mlx, dir, &game->resolution, &game->resolution);
	if (!*ptr)
		ft_error_exit(IMAGE_ERROR, game);
}

void	ft_get_images(t_game *game)
{
	//game->imgs->background = mlx_xpm_file_to_image(game->mlx, "./imgs/background.xpm", &game->resolution, &game->resolution);
	ft_mlx_xpm_file_to_img(&game->imgs->background, "./imgs/background.xpm", game);
	ft_mlx_xpm_file_to_img(&game->imgs->collectible, "./imgs/collectible.xpm", game);
	ft_mlx_xpm_file_to_img(&game->imgs->exit, "./imgs/exit.xpm", game);
	ft_mlx_xpm_file_to_img(&game->imgs->player, "./imgs/player.xpm", game);
	ft_mlx_xpm_file_to_img(&game->imgs->wall, "./imgs/wall.xpm", game);
}

void	ft_start_game(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width * game->resolution, game->height * game->resolution, "so_long");
	ft_get_images(game);
	ft_draw_map(game);
	ft_print2d_str(game->map);
	mlx_hook(game->window, 2, 1L << 0, ft_process_keycode, game);
	mlx_hook(game->window, 17, 1L << 17, ft_end_game, game);
	mlx_loop(game->mlx);
}
