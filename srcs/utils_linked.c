#include "../incs/so_long.h"

static void	ft_insert_empty_char(char c, t_str **str)
{
	t_str	*new;

	new = (t_str *)malloc(sizeof(t_str));
	if (!new)
		return ;
	new->c = c;
	new->next = NULL;
	new->prev = NULL;
	*str = new;
}

void	ft_insert_end_char(char c, t_str **str)
{
	t_str	*tmp;
	t_str	*new;

	tmp = *str;
	if (!*str)
	{
		ft_insert_empty_char(c, str);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = (t_str *)malloc(sizeof(t_str));
	if (!new)
		return ;
	new->c = c;
	new->next = NULL;
	new->prev = tmp;
	(*str)->prev = new;
	tmp->next = new;
}

static void	ft_insert_empty_coord(int x, int y, t_pos **pos, t_game *game)
{
	t_pos	*new;

	new = (t_pos *)malloc(sizeof(t_pos));
	if (!new)
		ft_error_exit(MALLOC_ERROR, game);
	new->x = x;
	new->y = y;
	new->next = NULL;
	*pos = new;
}

void	ft_insert_end_coord(int x, int y, t_pos **pos, t_game *game)
{
	t_pos	*tmp;
	t_pos	*new;

	tmp = *pos;
	if (!*pos)
		ft_insert_empty_coord(x, y, pos, game);
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		new = (t_pos *)malloc(sizeof(t_pos));
		if (!new)
			ft_error_exit(MALLOC_ERROR, game);
		new->x = x;
		new->y = y;
		new->next = NULL;
		tmp->next = new;
	}
}