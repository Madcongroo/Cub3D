/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartin2 <tmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:07:30 by tmartin2          #+#    #+#             */
/*   Updated: 2024/12/11 16:07:33 by tmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_player(char c)
{
	if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
		return (1);
	return (0);
}

int	get_real_line(char *line)
{
	int	len;

	len = ft_strlen(line);
	while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\n'))
		len--;
	return (len);
}

// Fonction pour mettre la taille de la map dans t_map
void	calculate_map_dimensions(t_map *map)
{
	int	height;
	int	max_width;
	int	current_width;

	height = 0;
	max_width = 0;
	current_width = 0;
	while (map->map_array[height] != NULL)
	{
		current_width = ft_strlen(map->map_array[height]);
		if (current_width > max_width)
			max_width = current_width;
		height++;
	}
	map->height = height;
	map->width = max_width + 1;
}

void	initialize_keys(int keys[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		keys[i] = 0;
		i++;
	}
}
