#include "../incs/so_long.h"

int	ft_putstr(const char *str)
{
	return (write(1, str, ft_strlen(str)));
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

size_t	ft_get_height(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
		i++;
	return  (i);
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
		if (tmp->x == x && tmp->y == y)
			ft_delete_nth_node(&game->collectibles_pos, pos);
		else
			tmp = tmp->next;
	}
}