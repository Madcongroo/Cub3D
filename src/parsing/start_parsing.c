/*
HEADER










HEADER
*/

#include "../../include/cub3d.h"

static int	check_line(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i] != '\n' || buf[i])
	{
		if (buf[i] == '0' || buf[i] == '1')
			return (2);
		else if (buf[i] == 'N' || buf[i] == 'S' || buf[i] == 'E'
			|| buf[i] == 'W' || buf[i] == 'C' || buf[i] == 'F')
			return (1);
	}
	return (0);
}

static int	check_buffer(char *buf)
{
	int	i;
	int	textures_mark;
	int	map_mark;
	int	new_line;

	textures_mark = 0;
	map_mark = 0;
	new_line = 1;
	i = -1;
	while (buf[++i])
	{
		if (buf[i] == '\n')
			new_line = 1;
		if (new_line == 1)
		{
			if (check_line(buf + i) == 1)
				textures_mark++;
			else if (check_line(buf + i) == 2)
				map_mark++;
			new_line = 0;
		}
		if (textures_mark < 6 && map_mark == 1)
			return (-1);
	}
	return (0);
}

/*just for the norme*/
static char	**split_buff(char *buf)
{
	char	**map_array;

	if (check_buffer(buf) == -1)
	{
		free (buf);
		return (NULL);
	}
	map_array = ft_split(buf, '\n');
	if (!map_array)
	{
		free (buf);
		return (NULL);
	}
	free (buf);
	return (map_array);
}

/*reads from the given file and returns a splited array*/
static char	**read_map(char *file)
{
	int		fd;
	int		check;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	buf = (char *)ft_calloc(5000, sizeof(char));
	if (!buf)
		return (NULL);
	check = read(fd, buf, 5000);
	if (check == 0)
		buf[check] = '\0';
	else if (check < 0)
	{
		free (buf);
		return (NULL);
	}
	return (split_buff(buf));
}

int	start_parsing(t_data *data, char *file)
{
	char	**map;
	(void)data;

	map = NULL;
	map = read_map(file);
	if (!map)
		return (-1);
	if (check_basics(map) == -1)
		return (ft_free_array(map));
	// if (check_map(map) == -1)
	// 	return (ft_free_array(map));
	// texturs_paths(data, map);
	// color_floor(data, map);
	// color_ceiling(data, map);
	// fill_map_array(data, map);
	// print_map_info(data->map);
	// display_array(map);
	ft_free_array(map);
	return (0);
}
