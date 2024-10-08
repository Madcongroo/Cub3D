/*
HEADER










HEADER
*/

#include "../../include/cub3d.h"

char    **read_copy_map(t_data *data, char **array)
{
	int		fd;
	int		check;
	char    *buf;

	fd = open("../../Map.cub", O_RDONLY);
	if (fd = -1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * 5000);
	check = read(fd, buf, 5000);
	if (check == 0)
	{
		buf[check] = '\0';
		
	}
}

int	start_parsing(t_data *data)
{
	read_copy_map(data, data->map->map_array);
	if (!data->map->map_array)
		return (1);
}