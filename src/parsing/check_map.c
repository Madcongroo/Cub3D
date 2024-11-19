/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:16:39 by proton            #+#    #+#             */
/*   Updated: 2024/11/12 15:08:16 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_edge_cases(t_data *data, char **map, int y, int x)
{
	if (y == 0 || y == data->map->height || x == 0
		|| x == data->map->width)
		return (1);
	else if (!map[y + 1][x] || !map[y][x - 1] || !map[y - 1][x]
		|| !map[y][x + 1])
		return (1);
	return (0);
}

int	should_it_be_checked(t_data *data, char **map, int y, int x)
{
	if (check_edge_cases(data, map, y, x) == 1)
		return (1);
	if (map[y][x + 1])
	{
		if (ft_is_whitespace(map[y][x + 1]))
			return (1);
	}
	if (map[y][x - 1])
	{
		if (ft_is_whitespace(map[y][x - 1]))
			return (1);
	}
	if (map[y + 1])
	{
		if (ft_is_whitespace(map[y + 1][x]))
			return (1);
	}
	if (map[y - 1])
	{
		if (ft_is_whitespace(map[y - 1][x]))
			return (1);
	}
	return (0);
}

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
	// /* TEMPORAIRE */
	// // Imprimer les valeurs des vecteurs (avec %f qui attend un float/double)
    // printf("Angle : %.2f radians\n", data->player->angle);
    // printf("Vecteur de direction : (x_cam : %.2f, y_cam : %.2f)\n", data->player->x_cam, data->player->y_cam);
    // printf("Vecteur du plan de la caméra : (plan_x : %.2f, plan_y : %.2f)\n", data->player->plan_x, data->player->plan_y);

    // // Calculer et imprimer la longueur des vecteurs
    // float dir_length = sqrtf(data->player->x_cam * data->player->x_cam + data->player->y_cam * data->player->y_cam);
    // float plane_length = sqrtf(data->player->plan_x * data->player->plan_x + data->player->plan_y * data->player->plan_y);

    // printf("Longueur du vecteur de direction : %.2f\n", dir_length);
    // printf("Longueur du vecteur du plan de la caméra : %.2f\n", plane_length);
}

/*fonction to check if the map is surrounded by walls
	each time the pos is '0', checks all pos + 1/ -1.
		if the pos +/- is a whitespace or nothing returns -1*/
/*fonction qui cherche un '0', regarded si pos + 1/-1
	si la pos +/- est un whitespace ou rien retourn -1*/
static int	is_map_wall_surrounded(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0')
			{
				if (should_it_be_checked(data, map, i, j))
					return (-1);
			}
			if (is_player(map[i][j]))
			{
				set_direction(data, map[i][j]);
			}
		}
	}
	return (0);
}

static int	return_for_norm(t_data *data, char **map)
{
	if (!data->player->y && !data->player->x)
		return (error_msg("Error\nPlayer not found\n"));
	if (is_map_wall_surrounded(data, map) == -1)
		return (error_msg("Error\nMap unclosed\n"));
	return (0);
}

/*loops the map to scan all the infos
	boucle sur la map check toutes les infos*/
int	check_map(t_data *data, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (good_char(map[i][j]))
				return (error_msg("Error\nUnknown caracter\n"));
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E'
				|| map[i][j] == 'W')
			{
				if (should_it_be_checked(data, map, i, j))
					return (error_msg("Error\nPlayer outside the map\n"));
				if (data->player->y && data->player->x)
					return (error_msg("Error\nMore than 1 player\n"));
				data->player->y = i;
				data->player->x = j;
			}
		}
	}
	return (return_for_norm(data, map));
}
