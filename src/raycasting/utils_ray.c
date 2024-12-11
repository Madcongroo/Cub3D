/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartin2 <tmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:06:42 by tmartin2          #+#    #+#             */
/*   Updated: 2024/12/11 16:06:45 by tmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_pixel_put_rgb(t_data *data, int x, int y, t_rgb *color)
{
	unsigned int	color_transform;

	color_transform = (color->r << 16) | (color->g << 8) | color->b;
	my_pixel_put(data, x, y, color_transform);
}
