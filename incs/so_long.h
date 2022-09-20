#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>


# define INVALID_ARGUMENTS 1
# define INVALID_FILE 2
# define INVALID_MAP 3
# define INVALID_EXTENSION 4
# define MALLOC_ERROR 5
# define READ_ERROR 6

# include "../mlx_linux/mlx.h"

typedef	struct	s_pos
{
	int				id;
	int				coord[2];
	struct s_pos	*next;
}	t_pos;

typedef struct	s_str
{
	char			c;
	struct s_str	*next;
}	t_str;

typedef struct	s_map
{
	t_str	*str;
	t_str	*tmp;
	char	c;
	int		fd;
	char	*tmp_map;
}	t_map;

typedef struct	s_imgs
{
	void	*background;
	void	*player;
	void	*collectible;
	void	*exit;
	void	*wall;
}	t_imgs;

typedef struct	s_game
{	
	void			*mlx;
	void			*window;

	unsigned int	movements;

	int				resolution;
	int				collectibles;
	int				exits;

	size_t			width;
	size_t			height;

	char			**map;
	
	t_map			*map_utils;
	t_pos			*player_pos;
	t_pos			*collectibles_pos;
	t_pos			*exit_pos;
	t_imgs			*imgs;

	ssize_t			back_draw_id;
	ssize_t			wall_draw_id;
	ssize_t			coll_draw_id;
}	t_game;

/* UTILS FUNCTIONS */

char	*ft_strstr(const char *haystack, const char *needle);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char *str);
char	**ft_split(const char *str, char c);
void	ft_get_map(char *map, t_game *game);
size_t	ft_get_height(char **map);
int		ft_strrnchr(const char *str, int c, size_t len);
int		ft_strnchr(const char *str, int c, size_t len);

/* LINKED FUNCTIONS */

void	ft_insert_end_coord(int x, int y, t_pos **pos, int id);
void	ft_insert_end_char(char c, t_str **str);

/* CHECK FUNCTIONS */

void	ft_check_map(t_game *game);

/* FREE FUNCTIONS */

void	ft_free_list(t_str *str);
void	ft_free_2d_str(char **str);
void	ft_free_coord_list(t_pos *coord);

/* PRINT FUNCTIONS */

void	ft_print_char_list(t_str *str);
void	ft_print2d_str(char	**str);
void	ft_print_coord_list(t_pos *coord);

/* ERROR FUNCTIONS */

void	ft_error_exit(int type);


#endif