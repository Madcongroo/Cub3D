/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:35:03 by proton            #+#    #+#             */
/*   Updated: 2024/10/09 15:37:19 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init_player_struct(t_player *player)
{
	player->plan_x = -1;
	player->plan_y = -1;
	player->speed = -1;
	player->x = -1;
	player->x_cam = -1;
	player->y = -1;
	player->y_cam = -1;
}

static void	init_raycast_struct(t_raycast *raycast)
{
	raycast->dist_x = -1;
	raycast->dist_y = -1;
	raycast->result = -1;
	raycast->side_dist_x = -1;
	raycast->side_dist_y = -1;
	raycast->step_x = -1;
	raycast->step_y = -1;
	raycast->touch_wall = -1;
}

static void	init_map_struct(t_map *map)
{
	t_rgb	*c_rgb;
	t_rgb	*f_rgb;
	
	c_rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!c_rgb)
		return ;
	f_rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!f_rgb)
		return ;
	map->map_array = NULL;
	map->ea = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->fd = -1;
	map->ceilling_color = c_rgb;
	map->floor_color = f_rgb;
	map->height = -1;
	map->width = -1;
}

void	init_struct(t_data *data)
{
	init_player_struct(data->player);
	init_raycast_struct(data->raycast);
	init_map_struct(data->map);
	if (!data->map->ceilling_color || !data->map->floor_color)
		return ;
	else
	{
		data->map->ceilling_color->r = -1;
		data->map->ceilling_color->g = -1;
		data->map->ceilling_color->b = -1;
		data->map->ceilling_color->r = -1;
		data->map->ceilling_color->g = -1;
		data->map->ceilling_color->b = -1;
	}
}
