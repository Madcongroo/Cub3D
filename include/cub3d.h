/*
HEADER










HEADER
*/

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

# define WHITE 0xFFFFFF
# define ORANGE 0xF99a0B
# define BLACK 0x000000
# define RED 0xFF0000
# define SQUARE_SIZE 32
# define PLAYER_SIZE 14
# define ROT_SPEED 0.1f // environ 5.7 degres

typedef enum e_keys
{
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_ESC = 65307,
	KEY_LEFT = 65361,
	KEY_RIGHT = 65363
}	t_keys;


typedef struct s_player
{
	float		x;
	float		y;
	int		old_x;
	int		old_y;
	float	x_cam;
	float	y_cam;
	int		speed;
	int		plan_x;
	int		plan_y;
	float	angle;
}	t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_map
{
	char	**map_array;
	int		width;
	int		height;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	*floor_color;
	t_rgb	*ceilling_color;
	int		fd;
}	t_map;

typedef struct s_raycast
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

typedef struct s_data
{
	t_player	*player;
	t_map		*map;
	t_raycast	*raycast;
	void		*win;
	void		*text;
	void		*mlx;
	void		*img;
	char		*address;
	int			bits_p_pix;
	int			line_len;
	int			endian;
	int			win_width;
	int			win_height;
	int			keys[65536];
}	t_data;

typedef struct s_check
{
	int	n;
	int	s;
	int	e;
	int	w;
	int	f;
	int	c;
}	t_check;

// src/error_gestion.c
int		free_all(t_data *data);
int		ft_free_array(char **array);

// src/start_parsing.c
int		check_basics(char **array);
int		start_parsing(t_data *data, char *file);

/*re alloc map*/
int		re_alloc_map(t_data *data);

/*temporaire pour les tests comme afficher la map etc*/
void	display_array(char **map);
void	print_map_info(t_map *map);

// src/parsing/texturs_map
int		parse_all(t_data *data, char **map);
int		texturs_paths_no_so(t_data *data, char **map);
int		texturs_paths_we_ea(t_data *data, char **map);
void	color_floor(t_data *data, char **map);
void	color_ceiling(t_data *data, char **map);
int		check_color_number(t_data *data);

// src/parsing/fill_map_array.c
int		fill_map_array(t_data *data, char **map);
void	copy_map_array(t_data *data, char **map, int map_start, int map_height);
int		get_map_start(char **map);
int		get_map_height(char **map, int map_start);

/*tous les checks entries de la map*/
int		check_map(t_data *data, char **map);

/*init les structs*/
int		init_struct(t_data *data);

// src/parsing/utils.c
char	*remove_sup_space(char *str);
char	*skip_space(char *str);
char	*jump_space(char *str);
int		error_msg(char *error_msg);
int		good_char(char c);
int		should_it_be_checked(t_data *data, char **map, int y, int x);

// src/map_2d/start_map_2d
int		start_map_2d(t_data *data);
void	loop_square_size(t_data *data, int x, int y, int color);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	map_img_output(t_data *data, char **map, int turn);


// src/map_2d/games_loop.c
void	games_loop(t_data *data);
int		close_window(t_data *data);
void	draw_square(t_data *data, int x, int y, int color);

// src/map_2d/draw_grid.c
void	draw_grid(t_data *data);
void	draw_vertical_line(t_data *data, int x, int y, int length);
void	draw_horizontal_line(t_data *data, int x, int y, int length);

// src/map_2d/render_games.c
int		render_game(t_data *data);
void	draw_player(t_data *data);
int handle_keypress(int keycode, t_data *data);
void rotate_player(t_player *player, float angle);

// src/map_2d/utils_2d.c
int		get_real_line(char *line);
void	calculate_map_dimensions(t_map *map);
int		is_player(char c);
int handle_keypress_on(int keycode, t_data *data);
int handle_keypress_off(int keycode, t_data *data);



#endif