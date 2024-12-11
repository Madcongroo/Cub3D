/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartin2 <tmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:07:59 by tmartin2          #+#    #+#             */
/*   Updated: 2024/12/11 16:08:01 by tmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_image(data->mlx, data->textures[0].img);
	mlx_destroy_image(data->mlx, data->textures[1].img);
	mlx_destroy_image(data->mlx, data->textures[2].img);
	mlx_destroy_image(data->mlx, data->textures[3].img);
	mlx_destroy_display(data->mlx);
	free (data->mlx);
	free_all(data);
	exit(0);
	return (0);
}

// Fonction pour afficher la fenetre et gestion des evenement dans une boucle
void	games_loop(t_data *data)
{
	mlx_hook(data->win, 17, 0, close_window, data);
	mlx_hook(data->win, 2, 1L << 0, handle_keypress_on, data);
	mlx_hook(data->win, 3, 1L << 1, handle_keypress_off, data);
	mlx_loop_hook(data->mlx, render_game, data);
	mlx_loop(data->mlx);
}

/* Fonction qui recois les differente taille de 
 draw_grid pour dessiner chaque pixel*/
void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < SQUARE_SIZE)
	{
		j = 0;
		while (j < SQUARE_SIZE)
		{
			mlx_pixel_put(data->mlx, data->win, x + j, y + i, color);
			j++;
		}
		i++;
	}
}
