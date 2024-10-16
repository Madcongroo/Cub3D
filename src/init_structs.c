/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bproton <bproton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 13:35:03 by proton            #+#    #+#             */
/*   Updated: 2024/10/16 15:23:59 by bproton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static t_player	*init_player_struct(void)
{
	t_player	*new_player;

	new_player = (t_player *)ft_calloc(1, sizeof(t_player));
	if (!new_player)
		return NULL;
	return (new_player);
}

static t_raycast	*init_raycast_struct(void)
{
	t_raycast	*raycast;
	
	raycast = (t_raycast *)ft_calloc(1, sizeof(t_raycast));
	if (!raycast)
		return (NULL);
	return (raycast);

}

static t_rgb	*get_rgb_struct(void)
{
	t_rgb	*new_rgb;

	new_rgb = (t_rgb *)ft_calloc(1, sizeof(t_rgb));
	if (!new_rgb)
		return (NULL);
	return (new_rgb);
}

static t_map	*init_map_struct(void)
{
	t_map	*map;
	
	map = (t_map *)ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->ceilling_color = get_rgb_struct();
	if (!map->ceilling_color)
		return (NULL);
	map->floor_color = get_rgb_struct();
	if (!map->floor_color)
		return (NULL);
	return (map);
}

int	init_struct(t_data *data)
{
	data->player = init_player_struct();
	if (!data->player)
		return (-1);
	data->raycast = init_raycast_struct();
	if (!data->raycast)
		return (-1);
	data->map = init_map_struct();
	if (!data->map->ceilling_color || !data->map->floor_color || !data->map)
		return (-1);
	data->text = NULL;
	data->win = NULL;
	return (0);
}
