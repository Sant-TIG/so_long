#include "../incs/so_long.h"

void	ft_move_up(t_game **game)
{
	char	next_pos;

	next_pos = (*game)->map[(*game)->player_pos->y - 1][(*game)->player_pos->x];
	if (next_pos != '1' && next_pos != 'E')
	{
		(*game)->player_pos->y--;
		(*game)->movements++;
		ft_putunbr((*game)->movements);
		if (next_pos == '0')
		{
			mlx_clear_window((*game)->mlx, (*game)->window);
			ft_draw_map(*game);
		}
		else if (next_pos == 'C' && (*game)->collectibles--)
		{
			ft_search_collectible(*game, (*game)->player_pos->x, (*game)->player_pos->y);
			mlx_clear_window((*game)->mlx, (*game)->window);
			ft_draw_map(*game);
		}
	}
	else if (next_pos == 'E' && (*game)->collectibles == 0)
	{
		mlx_clear_window((*game)->mlx, (*game)->window);
		ft_draw_map(*game);
		ft_end_game(*game);
	}
}

void	ft_move_left(t_game **game)
{
	char	next_pos;

	ft_print2d_str((*game)->map);
	next_pos = (*game)->map[(*game)->player_pos->y][(*game)->player_pos->x - 1];
	if (next_pos != '1' && next_pos != 'E')
	{
		(*game)->player_pos->x--;
		(*game)->movements++;
		ft_putunbr((*game)->movements);
		if (next_pos == '0')
		{
			mlx_clear_window((*game)->mlx, (*game)->window);
			ft_draw_map(*game);
		}
		else if (next_pos == 'C' && (*game)->collectibles--)
		{
			ft_search_collectible(*game, (*game)->player_pos->x, (*game)->player_pos->y);
			mlx_clear_window((*game)->mlx, (*game)->window);
			ft_draw_map(*game);
		}
	}
	else if (next_pos == 'E' && (*game)->collectibles == 0)
	{
		mlx_clear_window((*game)->mlx, (*game)->window);
		ft_draw_map(*game);
		ft_end_game(*game);
	}
}

void	ft_move_down(t_game **game)
{
	char	next_pos;

	next_pos = (*game)->map[(*game)->player_pos->y + 1][(*game)->player_pos->x];
	if (next_pos != '1' && next_pos != 'E')
	{
		(*game)->player_pos->y++;
		(*game)->movements++;
		ft_putunbr((*game)->movements);
		if (next_pos == '0')
		{
			mlx_clear_window((*game)->mlx, (*game)->window);
			ft_draw_map(*game);
		}
		else if (next_pos == 'C' && (*game)->collectibles--)
		{
			ft_search_collectible(*game, (*game)->player_pos->x, (*game)->player_pos->y);
			mlx_clear_window((*game)->mlx, (*game)->window);
			ft_draw_map(*game);
		}
	}
	else if (next_pos == 'E' && (*game)->collectibles == 0)
	{
		mlx_clear_window((*game)->mlx, (*game)->window);
		ft_draw_map(*game);
		ft_end_game(*game);
	}
}

void	ft_move_right(t_game **game)
{
	char	next_pos;

	next_pos = (*game)->map[(*game)->player_pos->y][(*game)->player_pos->x + 1];
	if (next_pos != '1' && next_pos != 'E')
	{
		(*game)->player_pos->x++;
		(*game)->movements++;
		ft_putunbr((*game)->movements);
		if (next_pos == '0')
		{
			mlx_clear_window((*game)->mlx, (*game)->window);
			ft_draw_map(*game);
		}
		else if (next_pos == 'C' && (*game)->collectibles--)
		{
			ft_search_collectible(*game, (*game)->player_pos->x, (*game)->player_pos->y);
			mlx_clear_window((*game)->mlx, (*game)->window);
			ft_draw_map(*game);
		}
	}
	else if (next_pos == 'E' && (*game)->collectibles == 0)
	{
		mlx_clear_window((*game)->mlx, (*game)->window);
		ft_draw_map(*game);
		ft_end_game(*game);
	}
}