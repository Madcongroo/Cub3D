/*
HEADER










HEADER
*/

#include "../../include/cub3d.h"

/*checks each line to differentiate which line 
	is for the entries or the map*/
/*check toutes les lignes une par une pour differencier les entree
	de la map*/
static int	check_line(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i] != '\n' && buf[i])
	{
		if (buf[i] == 'N' || buf[i] == 'S' || buf[i] == 'E'
			|| buf[i] == 'W' || buf[i] == 'C' || buf[i] == 'F')
			return (1);
		else if (buf[i] == '0' || buf[i] == '1')
			return (2);
	}
	return (0);
}

int	control_line(char *buf, int *map_mark, int *text_mark)
{
	int			ret;

	ret = check_line(buf);
	if (ret == 1)
		*text_mark += 1;
	else if (ret == 2)
		*map_mark += 1;
	return (ret);
}

/*reads the buffer and checks if the map is at the end of the file*/
/*lis le buffer et regarde si la map est a la fin du fichier*/
static int	check_buffer(char *buf)
{
	int	i;
	int	new_line;
	int	map_mark;
	int	text_mark;

	map_mark = 0;
	text_mark = 0;
	i = -1;
	new_line = 1;
	while (buf[++i])
	{
		if (new_line == 1)
		{
			control_line(buf + i, &map_mark, &text_mark);
			new_line = 0;
		}
		if (buf[i] == '\n')
			new_line = 1;
		if (map_mark > 0 && text_mark < 6)
			return (error_msg("Error\nMap not at the end\n"));
	}
	if (map_mark < 1 || text_mark != 6)
		return (error_msg("Error\nMap not found or too much arguments\n"));
	return (0);
}

/*just for the norme*/
/*juste pour la norme*/
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
		error_msg("Error\nSplit error\n");
		return (NULL);
	}
	free (buf);
	return (map_array);
}

/*reads from the given file and returns a splited array*/
/*lis du fichier et retourne un tableau*/
static char	**read_map(char *file)
{
	int		fd;
	int		check;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		error_msg("Error\nOpen error\n");
		return (NULL);
	}
	buf = (char *)ft_calloc(2000, sizeof(char));
	if (!buf)
		return (NULL);
	check = read(fd, buf, 2000);
	if (check < 0)
	{
		free (buf);
		error_msg("Error\nRead error\n");
		return (NULL);
	}
	else if (check == 0)
		buf[check] = '\0';
	return (split_buff(buf));
}

int	start_parsing(t_data *data, char *file)
{
	char	**map;

	map = read_map(file);
	if (!map)
		return (-1);
	if (check_basics(map) == -1)
		return (ft_free_array(map));
	if (parse_all(data, map) == -1)
		return (ft_free_array(map));
	if (check_map(data, data->map->map_array) == -1)
		return (ft_free_array(map));
	ft_free_array(map);
	return (0);
}
