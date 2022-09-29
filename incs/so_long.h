#ifndef SO_LONG_H

# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define INVALID_ARGUMENTS 1
# define INVALID_FILE 2
# define INVALID_MAP 3
# define INVALID_EXTENSION 4
# define MALLOC_ERROR 5
# define READ_ERROR 6
# define EMPTY_MAP 7
# define PLAYER_ERROR 8
# define WALL_ERROR 9
# define IMAGE_ERROR 10

typedef	struct	s_pos
{
	int	x;
	int	y;
	struct s_pos	*next;
}	t_pos;

typedef struct	s_str
{
	char			c;
	struct s_str	*next;
	struct s_str	*prev;
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
	int				players;
	int				exits;
	size_t			width;
	size_t			height;
	char			**map;	
	t_map			*map_utils;
	t_pos			*player_pos;
	t_pos			*collectibles_pos;
	t_pos			*exit_pos;
	t_imgs			*imgs;
}	t_game;

/* SO_LONG FUNCTIONS */

void	ft_get_map(char *map, t_game *game);
int		ft_end_game(t_game *game);
void	ft_check_map(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_start_game(t_game *game);
void	ft_move_left(t_game **game);
void	ft_move_up(t_game **game);
void	ft_move_down(t_game **game);
void	ft_move_right(t_game **game);
void	ft_search_collectible(t_game *game, int x, int y);
void	ft_delete_nth_node(t_pos **coord, int pos);
void	ft_get_images(t_game *game);

/* UTILS FUNCTIONS */

void	ft_error_exit(int type, t_game *game);
void	ft_putunbr(int n);
int		ft_putstr(const char *str);
int		ft_putchar(int c);
int		ft_isdigit(int c);
char	**ft_split(const char *str, char c);
int		ft_strnchr(const char *str, int c, size_t len);
int		ft_strrnchr(const char *str, int c, size_t len);
size_t	ft_get_height(char **map);
size_t	ft_strlen(const char *str);

/* LINKED FUNCTIONS */

void	ft_insert_end_char(char c, t_str **str);
void	ft_insert_end_coord(int x, int y, t_pos **pos, t_game *game);

/* FREE FUNCTIONS */

void	ft_general_free(t_game *game);

/* PRINT FUNCTIONS */

void	ft_print_char_list(t_str *str);
void	ft_print2d_str(char	**str);
void	ft_print_coord_list(t_pos *coord);

#endif