//
//
//
//
//
//
//
//
//
//
//
//

# ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>


typedef struct s_player
{
	int	x;
	int	y;
	int	x_cam;
	int	y_cam;
	int	speed;
	int	plan_x;
	int	plan_y;
}	t_player;

typedef struct	s_rgb 
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct	s_map
{
	char	**map_array;
	int		width;
	int		height;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	t_rgb	floor_color;
	t_rgb	ceilling_color;
	int		fd;
}	t_map;

typedef struct	s_raycast
{
	bool	touch_wall;
	double	dist_x;
	double	dist_y;
	int		result;
	double	side_dist_x;
	double	side_dist_y;
	int		step_x;
	int		step_y; 
}	t_raycast;

typedef struct	s_game
{
	t_player	*player;
	t_map		*map;
	t_raycast	*raycast;
	void		*win; // Pointeur sur la fenetre mlx
	void		*text; // Pointeur pour les texture du jeux 
}	t_game;
# endif