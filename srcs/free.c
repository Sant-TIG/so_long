#include "../incs/so_long.h"

static void	ft_free_2d_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

static void	ft_free_coord_list(t_pos *coord)
{
	t_pos	*tmp;

	tmp = coord;
	while (tmp)
	{
		coord = coord->next;
		free(tmp);
		tmp = coord;
	}
	coord = NULL;

}

static void	ft_free_char_list(t_str *str)
{
	t_str	*tmp;

	tmp = str;
	while (str)
	{
		str = str->next;
		free(tmp);
		tmp = str;
	}
	str = NULL;
}

static void	ft_free_map_utils(t_map *map_utils)
{
	if (map_utils->tmp_map)
		free(map_utils->tmp_map);
	if (map_utils->str)
		ft_free_char_list(map_utils->str);
	if (map_utils)
		free(map_utils);
}

void	ft_general_free(t_game *game)
{
	if (game->map_utils)
		ft_free_map_utils(game->map_utils);
	if (game->map)
		ft_free_2d_str(game->map);
	if (game->player_pos)
		ft_free_coord_list(game->player_pos);
	if (game->collectibles_pos)
		ft_free_coord_list(game->collectibles_pos);
	if (game->exit_pos)
		ft_free_coord_list(game->exit_pos);
}