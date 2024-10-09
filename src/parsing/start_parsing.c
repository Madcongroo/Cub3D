/*
HEADER










HEADER
*/

#include "../../include/cub3d.h"

/*just for the norme*/
static char	**split_buff(char *buf)
{
	char	**map_array;

	map_array = ft_split(buf, "\n");
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
	if (fd = -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * 5000);
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

int	fill_struct(t_data *data, char **map)
{
}

/*cleans the map, takes out spaces, checks if the map is surrounded by walls,
	checks if it follows the guideline etc.*/
int	clean_map_array(char **array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		
	}
}

int	start_parsing(t_data *data, char *file)
{
	char	**map;

	map = read_map(file);
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
