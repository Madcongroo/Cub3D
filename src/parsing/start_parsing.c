/*
HEADER










HEADER
*/

#include "../../include/cub3d.h"

/*just for the norme*/
static char	**split_buff(char *buf)
{
	char	**map_array;

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
	buf = (char *)malloc(sizeof(char) * 10000);
	if (!buf)
		return (NULL);
	check = read(fd, buf, 10000);
	if (check == 0)
		buf[check] = '\0';
	else if (check < 0)
	{
		free (buf);
		return (NULL);
	}
	return (split_buff(buf));
}

// int	fill_struct(t_data *data, char **map)
// {
// }

/*checks if all the textures are on the map.
	If the map is at the bottom of the file / is on the file*/
int	first_map_check(char **array)
{
	int	i;
	int	textures_mark;
	int	map_mark;

	textures_mark = 0;
	map_mark = 0;
	i = -1;
	while (array[++i])
	{
		if ((map_mark == 1 && textures_mark != 6) || textures_mark > 6)
			return (-1);
		if ((array[i][0] == 'N' || array[i][0] == 'S' || array[i][0] == 'E'
			|| array[i][0] == 'W' || array[i][0] == 'C' || array[i][0] == 'F')
				&& map_mark == 0)
			textures_mark++;
		if (array[i][0] == '0' || array[i][0] == '1')
			map_mark = 1;
	}
	if (textures_mark < 6 || !map_mark)
		return (-1);
	return (0);
}

int	start_parsing(t_data *data, char *file)
{
	char	**map;
	(void)data;

	map = read_map(file);
	if (!map)
		return (-1);
	if (first_map_check(map) == -1)
	{
		ft_free_array(map);
		return (-1);
	}
	texturs_paths(data, map);
	color_floor(data, map);
	color_ceiling(data, map);
	fill_map_array(data, map);
	// if (fill_struct(data, map) == -1)
	// {
	// 	ft_free_array(map);
	// 	return (-1);
	// }
	display_array(map);
	return (0);
	
}
