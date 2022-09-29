#include "../incs/so_long.h"

void	ft_print_char_list(t_str *str)
{
	while (str)
	{
		printf("%c\n", str->c);
		str = str->next;
	}
}

void	ft_print2d_str(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("%s\n", str[i]);
}

void	ft_print_coord_list(t_pos *coord)
{
	t_pos	*tmp;

	tmp = coord;
	while (tmp != NULL)
	{
		printf("x = %d y = %d\n", tmp->x, tmp->y);
		tmp = tmp->next;
	}
}