/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:44:57 by proton            #+#    #+#             */
/*   Updated: 2024/12/05 11:16:18 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_direction(t_data *data, char c)
{
	if (c == 'N')
		data->player->angle = 3 * M_PI / 2;
	else if (c == 'S')
		data->player->angle = M_PI / 2;
	else if (c == 'E')
		data->player->angle = 0;
	else
		data->player->angle = M_PI;
	data->player->x_cam = cos(data->player->angle);
	data->player->y_cam = sin(data->player->angle);
	data->player->plan_x = -PLANE_LENGHT * data->player->y_cam;
	data->player->plan_y = PLANE_LENGHT * data->player->x_cam;
}

/* Fonction qui check les chiffre recu depuis le fichier*/
int	check_color_number(t_data *data)
{
	if (data->map->floor_color->r < 0 || data->map->floor_color->r > 255
		|| data->map->floor_color->g < 0 || data->map->floor_color->g > 255
		|| data->map->floor_color->b < 0 || data->map->floor_color->b > 255)
		return (-1);
	if (data->map->ceilling_color->r < 0 || data->map->ceilling_color->r > 255
		|| data->map->ceilling_color->g < 0
		|| data->map->ceilling_color->g > 255
		|| data->map->ceilling_color->b < 0
		|| data->map->ceilling_color->b > 255)
		return (-1);
	return (0);
}

/*checks each line to differentiate which line 
	is for the entries or the map*/
/*check toutes les lignes une par une pour differencier les entree
	de la map*/
int	check_line(char *buf)
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

int	check_file_name(char *file)
{
	int	i;

	i = -1;
	if (file[0] == '.')
		return (-1);
	while (file[++i])
	{
		if (file[i] == '.')
			break ;
	}
	if (file[i] == '.')
	{
		if (ft_strcmp(file + i, ".cub") == 0)
			return (0);
	}
	return (-1);
}
