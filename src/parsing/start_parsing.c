/*
HEADER










HEADER
*/

#include "../../include/cub3d.h"

static char	*add_0(char *buf, char *new_buf)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (buf[++i])
	{
		if (i != 0  && (buf[i] == '\n' && buf[i - 1] == '\n'))
			new_buf[j++] = '0';
		new_buf[j++] = buf[i];
	}
	new_buf[j] = '\0';
	return (new_buf);
}

/*count how many eccess '\n' there is. Retruns a function that
	adds a 0 before every eccess '\n'*/
static char	*new_buf(char *buf)
{
	int		i;
	int		only_n;
	char	*new_buf;

	i = -1;
	only_n = 0;
	while (buf[++i])
	{
		while (buf[i] == '\n' && buf[i + 1] == '\n')
		{
			i++;
			only_n++;
		}
	}
	new_buf = (char *)ft_calloc((i + only_n) + 1, sizeof(char));
	if (!new_buf)
		return (NULL);
	return (add_0(buf, new_buf));
}

/*just for the norme*/
static char	**split_buff(char *buf)
{
	char	**map_array;
	char	*modified_buf;

	modified_buf = new_buf(buf);
	if (!modified_buf)
	{
		free (buf);
		return (NULL);
	}
	free (buf);
	map_array = ft_split(modified_buf, '\n');
	if (!map_array)
	{
		free (modified_buf);
		return (NULL);
	}
	free (modified_buf);
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
	// texturs_paths(data, map);
	// color_floor(data, map);
	// color_ceiling(data, map);
	// fill_map_array(data, map);
	// print_map_info(data->map);
	// display_array(map);
	ft_free_array(map);
	return (0);
}
