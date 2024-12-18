/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartin2 <tmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:06:19 by tmartin2          #+#    #+#             */
/*   Updated: 2024/12/11 16:06:21 by tmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_ray(t_raycast *ray)
{
	ray->touch_wall = false;
	ray->delta_dist_x = 0.0;
	ray->delta_dist_y = 0.0;
	ray->side_dist_x = 0.0;
	ray->side_dist_y = 0.0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->perp_wall_dist = 0.0;
	ray->ray_dir_x = 0.0;
	ray->ray_dir_y = 0.0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->side = 0;
}

void	draw_ceilling(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->win_height / 2)
	{
		x = 0;
		while (x < data->win_width)
		{
			my_pixel_put_rgb(data, x, y, data->map->ceilling_color);
			x++;
		}
		y++;
	}
}

void	draw_floor(t_data *data)
{
	int	x;
	int	y;

	y = data->win_height / 2;
	while (y < data->win_height)
	{
		x = 0;
		while (x < data->win_width)
		{
			my_pixel_put_rgb(data, x, y, data->map->floor_color);
			x++;
		}
		y++;
	}
}

void	raycast_ray(t_data *data)
{
	int			x;
	t_raycast	ray;
	int			text;

	draw_ceilling(data);
	draw_floor(data);
	x = 0;
	while (x < data->win_width)
	{
		init_ray_and_cam(data, &ray, x);
		calculate_steps_and_sides(data, &ray);
		algo_dda(data, &ray);
		calculate_projection(data, &ray);
		if (ray.side == 0 && ray.ray_dir_x > 0)
			text = 2;
		else if (ray.side == 0 && ray.ray_dir_x < 0)
			text = 3;
		else if (ray.side == 1 && ray.ray_dir_y > 0)
			text = 1;
		else
			text = 0;
		draw_wall(data, x, &data->textures[text], &ray);
		x++;
	}
}
