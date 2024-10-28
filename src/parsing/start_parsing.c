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
	int			ret_value;

	ret_value = check_line(buf);
	if (ret_value == 1)
		*text_mark += 1;
	else if (ret_value == 2)
		*map_mark += 1;
	return (ret_value);
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

char	*ft_strndup(const char *s, size_t n)
{
	size_t		i;
	char	*str;

	i = 0;
	if (!s || !n)
		return (NULL);
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (n)
	{
		str[i] = s[i];
		i++;
		n--;
	}
	str[i] = '\n';
	return (str);
}

/*cuts the buffer if the map is separated by only \n*/
/*decoupe le buffer si la map est separees par des \n*/
static char	*cut_map_if_needed(char *buf)
{
	int		i;
	char	*n_buf;
	int		map_mark;

	i = -1;
	map_mark = 0;
	while (buf[++i])
	{
		if (buf[i] == '0' || buf[i] == '1')
			map_mark = 1;
		if (buf[i] == 'C' || buf[i] == 'F')
		{
			while (buf[i] != '\n')
				i++;
			continue ;
		}
		if (map_mark == 1 && (buf[i] == '\n' && buf[i - 1] == '\n'))
			break ;
	}
	n_buf = ft_strndup(buf, (size_t)i);
	if (!n_buf)
		return (NULL);
	free (buf);
	return (n_buf);
}

/*just for the norme*/
/*juste pour la norme*/
static char	**split_buff(char *buf)
{
	char	**map_array;
	char	*new_buf;

	if (check_buffer(buf) == -1)
	{
		free (buf);
		return (NULL);
	}
	new_buf = cut_map_if_needed(buf);
	if (!new_buf)
	{
		free (buf);
		error_msg("Error\nNew buffer error\n");
		return (NULL);
	}
	map_array = ft_split(new_buf, '\n');
	if (!map_array)
	{
		free (buf);
		error_msg("Error\nSplit error\n");
		return (NULL);
	}
	free (new_buf);
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
	// display_array(data->map->map_array);
	ft_free_array(map);
	return (0);
}
