/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartin2 <tmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:08:14 by tmartin2          #+#    #+#             */
/*   Updated: 2024/12/11 16:08:18 by tmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define RED_RUSH 0x880000
# define GRAY 0xD3D3D3
# define BLUE 0x0000FF
# define SQUARE_SIZE 32
# define PLAYER_SIZE 16
# define ROT_SPEED 0.05
# define PLANE_LENGHT 0.66f
# define BUFFER_SIZE 10

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

typedef struct s_mini_map
{
	int	mini_width;
	int	mini_height;
	int	mini_size;
	int	offset_x;
	int	offset_y;
	int	color;
	int	player_x;
	int	player_y;
}	t_mini_map;

typedef struct s_wall
{
	int		line_height;
	int		draw_start;
	int		draw_end;
	float	wall_x;
}	t_wall;

typedef struct s_player
{
	float		x;
	float		y;
	int			old_x;
	int			old_y;
	float		x_cam;
	float		y_cam;
	int			speed;
	float		plan_x;
	float		plan_y;
	float		angle;
	int			key_pressed[6];
}	t_player;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_textures
{
	char	*addr;
	void	*img;
	int		endian;
	int		line_len;
	int		bits_p_pix;
	int		width;
	int		height;
}	t_textures;

typedef struct s_map
{
	char		**map_array;
	int			width;
	int			height;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_rgb		*floor_color;
	t_rgb		*ceilling_color;
	int			fd;
}	t_map;

typedef struct s_raycast
{
	bool	touch_wall;
	float	delta_dist_x;
	float	delta_dist_y;
	float	side_dist_x;
	float	side_dist_y;
	int		step_x;
	int		step_y;
	float	perp_wall_dist;
	float	ray_dir_x;
	float	ray_dir_y;
	int		map_x;
	int		map_y;
	int		side;
	t_wall	wall;
}	t_raycast;

typedef struct s_data
{
	t_player	*player;
	t_map		*map;
	t_raycast	*raycast;
	t_mini_map	*mini_map;
	t_textures	*textures;
	void		*win;
	void		*text;
	void		*mlx;
	void		*img;
	char		*address;
	int			which_texture;
	int			bits_p_pix;
	int			line_len;
	int			endian;
	int			win_width;
	int			keys[65536];
	int			win_height;
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
int		error_msg(char *error_msg);

// src/start_parsing.c
int		check_basics(char **array);
int		start_parsing(t_data *data, char *file);

// src/parsing/texturs_map
int		parse_all(t_data *data, char **map);
int		texturs_paths_no_so(t_data *data, char **map);
int		texturs_paths_we_ea(t_data *data, char **map);
int		color_floor(t_data *data, char **map);
int		color_ceiling(t_data *data, char **map);

// src/parsing/check_map.c
int		check_map(t_data *data, char **map);
int		is_map_wall_surrounded(t_data *data, char **map);
int		should_it_be_checked(t_data *data, char **map, int y, int x);

// src/parsing/fill_map_array.c
int		fill_map_array(t_data *data, char **map);
void	copy_map_array(t_data *data, char **map, int map_start, int map_height);
int		get_map_start(char **map);
int		get_map_height(char **map, int map_start);

/*tous les checks entries de la map*/
int		check_map(t_data *data, char **map);

// src/gnl
char	*get_next_line(int fd);
char	*read_function(char *remind, int fd);
char	*ft_duporjoin(char *remind, char *buffer);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
int		check_if_n(char *remind);
char	*copy_whats_left(char *remind);
char	*transfer_to_n(char *remind);
char	*ft_strdup(const char *s);

// src/parsing/count_file_caracters.c
int		count_file_chars(char *file);
size_t	find_end(const char *s, const char *set);
int		check_rgb_trimmed(char *value);
int		check_rgb_values(char **values);

/*init les structs*/
int		init_struct(t_data *data);

// src/parsing/utils.c
char	*remove_sup_space(char *str);
char	*skip_space(char *str);
int		good_char(char c);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t size);

// src/parsing/parsing_utils2
void	set_direction(t_data *data, char c);
int		check_line(char *buf);
int		control_line(char *buf, int *map_mark, int *text_mark);
int		check_file_name(char *file);
int		check_color_number(t_data *data);

// src/map_2d/start_map_2d
int		start_map_2d(t_data *data);
void	loop_square_size(t_data *data, int x, int y, int color);
void	my_pixel_put(t_data *data, int x, int y, int color);
void	map_img_output(t_data *data, char **map, int turn);

// src/map_2d/games_loop.c
void	games_loop(t_data *data);
int		close_window(t_data *data);
void	draw_square(t_data *data, int x, int y, int color);

// src/map_2d/render_games.c
int		render_game(t_data *data);
void	draw_player(t_data *data);
void	process_movement(t_data *data);
void	rotate_player(t_player *player, float angle);

// src/map_2d/key.c
void	key_w_and_key_s(t_data *data, float *new_x, float *new_y);
void	key_a_and_key_d(t_data *data, float *new_x, float *new_y);
int		handle_keypress_on(int keycode, t_data *data);
int		handle_keypress_off(int keycode, t_data *data);

// src/map_2d/utils_2d.c
int		get_real_line(char *line);
void	calculate_map_dimensions(t_map *map);
int		is_player(char c);
void	initialize_keys(int keys[], int size);

// src/raycasting/raycast.c
void	raycast_ray(t_data *data);
void	init_ray(t_raycast *ray);
void	draw_ceilling(t_data *data);
void	draw_floor(t_data *data);

// src/raycasting/play_3d
void	init_ray_and_cam(t_data *data, t_raycast *ray, int x);
void	calculate_steps_and_sides(t_data *data, t_raycast *ray);
void	algo_dda(t_data *data, t_raycast *ray);
void	calculate_projection(t_data *data, t_raycast *ray);
void	draw_wall(t_data *data, int x, t_textures *text, t_raycast *ray);

// src/raycasting/utils_rat.c
void	my_pixel_put_rgb(t_data *data, int x, int y, t_rgb *color);

// src/raycasting/textures.c
int		init_textures(t_data *data);
int		get_color_pixel(t_textures *text, int x, int y);

// src/raycasting/touch_wall.c
int		control_touch_wall(t_data *data, float new_x, float new_y);

// src/bonus/mini_map.c
void	mini_map(t_data *data);
void	set_mini_map_color(t_data *data, int map_x, int map_y);

#endif