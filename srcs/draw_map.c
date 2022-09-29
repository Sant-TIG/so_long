#include "../incs/so_long.h"

static void	ft_draw_background(t_game *game)
{
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

static void	ft_draw_walls(t_game *game)
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

static void	ft_draw_collectibles(t_game *game)
{
	t_pos	*tmp;

	tmp = game->collectibles_pos;
	while (tmp)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->collectible, tmp->x * game->resolution, tmp->y * game->resolution);
		tmp = tmp->next;
	}
}

static void	ft_draw_exits(t_game *game)
{
	t_pos	*tmp;

	tmp = game->exit_pos;
	while (tmp)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->imgs->exit, tmp->x * game->resolution, tmp->y * game->resolution);
		tmp = tmp->next;
	}
}

void	ft_draw_map(t_game *game)
{
	ft_draw_background(game);
	ft_draw_walls(game);
	ft_draw_collectibles(game);
	ft_draw_exits(game);
	mlx_put_image_to_window(game->mlx, game->window, game->imgs->player, game->player_pos->x * game->resolution, game->player_pos->y * game->resolution);
}