/*
HEADER










HEADER
*/

#include "../../include/cub3d.h"

static char	**read_map(void)
{
	int		fd;
	int		check;
	char	*buf;
	char	**map_arr;

	fd = open("../../map/Map.cub", O_RDONLY);
	if (fd = -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * 5000);
	check = read(fd, buf, 5000);
	if (check == 0)
		buf[check] = '\0';
	else if (check < 0)
	{
		free (buf);
		return (-1);
	}
	map_arr = ft_split(buf, "\n");
	if (!map_arr)
	{
		free (buf);
		return (-1);
	}
	free (buf);
	return (map_arr);
}

int	fill_struct(t_data *data, char **map)
{
}

int	clean_map_array(char **array)
{
	
}

int	start_parsing(t_data *data)
{
	char	**map;

	map = read_map();
	if (!map)
		return (-1);
	if (clean_map_array(map) == -1)
	{
		ft_free_array(map);
		return (-1);
	}
	if (fill_struct(data, map) == -1)
	{
		ft_free_array(map);
		return (-1);
	}
	
}
