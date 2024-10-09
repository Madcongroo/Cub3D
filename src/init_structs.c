/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:35:03 by proton            #+#    #+#             */
/*   Updated: 2024/10/09 18:11:39 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_player	*init_player_struct()
{
	t_player	*new_player;

	new_player = (t_player *)malloc(sizeof(t_player));
	if (!new_player)
		return NULL;
	new_player->plan_x = -1;
	new_player->plan_y = -1;
	new_player->speed = -1;
	new_player->x = -1;
	new_player->x_cam = -1;
	new_player->y = -1;
	new_player->y_cam = -1;
	return (new_player);
}

static t_raycast	*init_raycast_struct()
{
	t_raycast	*raycast;
	
	raycast = (t_raycast *)malloc(sizeof(t_raycast));
	if (!raycast)
		return (NULL);
	raycast->dist_x = -1;
	raycast->dist_y = -1;
	raycast->result = -1;
	raycast->side_dist_x = -1;
	raycast->side_dist_y = -1;
	raycast->step_x = -1;
	raycast->step_y = -1;
	raycast->touch_wall = -1;
	return (raycast);

}

static t_rgb	*get_rgb_struct()
{
	t_rgb	*new_rgb;

	new_rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (!new_rgb)
		return (NULL);
	new_rgb->b = -1;
	new_rgb->g = -1;
	new_rgb->r = -1;
	return (new_rgb);
}

static t_map	*init_map_struct()
{
	t_map	*map;
	
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map_array = NULL;
	map->ea = NULL;
	map->no = NULL;
	map->so = NULL;
	map->we = NULL;
	map->fd = -1;
	map->ceilling_color = get_rgb_struct();
	if (!map->ceilling_color)
		return (NULL);
	map->floor_color = get_rgb_struct();
	if (!map->floor_color)
		return (NULL);
	map->height = -1;
	map->width = -1;
	return (map);
}

int	init_struct(t_data *data)
{
	data->player = init_player_struct(data->player);
	if (!data->player)
		return (-1);
	data->raycast = init_raycast_struct();
	if (!data->raycast)
		return (-1);
	data->map = init_map_struct(data->map);
	if (!data->map->ceilling_color || !data->map->floor_color || !data->map)
		return (-1);
	data->text = NULL;
	data->win = NULL;
	return (0);
}
