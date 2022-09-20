#include "../incs/so_long.h"

void	ft_free_2d_str(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	ft_free_list(t_str *str)
{
	t_str	*tmp;

	tmp = str;
	while (tmp)
	{
		tmp = tmp->next;
		free(str);
		str = tmp;
	}
}

void	ft_free_coord_list(t_pos *coord)
{
	t_pos	*tmp;

	tmp = coord;
	while (tmp)
	{
		tmp = tmp->next;
		free(coord);
		coord = tmp;
	}
}