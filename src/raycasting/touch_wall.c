/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartin2 <tmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:06:34 by tmartin2          #+#    #+#             */
/*   Updated: 2024/12/11 16:06:38 by tmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	control_touch_wall(t_data *data, float new_x, float new_y)
{
	int	player_x;
	int	player_y;

	player_x = (float)new_x;
	player_y = (float)new_y;
	if (data->map->map_array[player_y][player_x] == '1')
		return (1);
	return (0);
}
