#include "../incs/so_long.h"

void	ft_error_exit(int type, t_game *game)
{
	if (type == 1)
		printf("Wrong number of arguments.\n");
	else if (type == INVALID_FILE)
		ft_putstr("Error\nNo such file or directory\n");
	else if (type == INVALID_MAP)
		ft_putstr("Error\nInvalid map.Make sure the map is rectangle and is formed only by: '0', '1', 'E', 'P' and 'C'\n");
	else if (type == INVALID_EXTENSION)
		ft_putstr("Error.\nInvalid file extension. Make sure it is '.ber'.\n");
	else if (type == MALLOC_ERROR)
		ft_putstr("Error.\nFailed to allocate memory.\n");
	else if (type == EMPTY_MAP)
		ft_putstr("Error.\nThe file is empty.\n");
	else if (type == PLAYER_ERROR)
		ft_putstr("Error.\nThere are two or more player positions.\n");
	else if (type == WALL_ERROR)
		ft_putstr("Error\nThe map is no closed by '1'.\n");
	else if (type == IMAGE_ERROR)
		ft_putstr("Error.\nThe image is not xpm.\n");
	ft_general_free(game);
	exit(-1);
}