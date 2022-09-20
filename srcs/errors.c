#include "../incs/so_long.h"

void	ft_error_exit(int type)
{
	if (type == 1)
		printf("Wrong number of arguments.\n");
	if (type == 2)
		printf("No such file or directory\n");
	if (type == 3)
		printf("Invalid_map\n");
	if (type == 4)
		printf("Invalid Extension\n");
	if (type == 5)
		printf("Error at creating memory\n");
	exit(-1);
}