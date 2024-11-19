/*













*/

#include "../../include/cub3d.h"

void raycast_ray(t_data *data)
{
    t_raycast ray;
    float ray_dir_x = cos(data->player->angle); // init direction joueur
    float ray_dir_y = sin(data->player->angle);
    int map_x = (int)data->player->x; // Conversion pos joueur en entier pour le bien de l algo
    int map_y = (int)data->player->y;
    ray.delta_dist_x = fabs(1 / ray_dir_x);
    ray.delta_dist_y = fabs(1 / ray_dir_y);
    // Init les step_x et step_y (direction du rayon se deplace)
    // Et init les side_step (distance entre joueur et premiere ligne)
    if (ray_dir_x < 0)
    {
        ray.step_x = -1; // Vers la gauche
        ray.side_dist_x = (data->player->x - map_x) * ray.delta_dist_x; // distance joueur et premiere ligne
    }
    else
    {
        ray.step_x = 1; // Vers la droite
        ray.side_dist_x = (map_x + 1.0 - data->player->x) * ray.delta_dist_x;
    }
    if (ray_dir_y < 0)
    {
        ray.step_y = -1; // Vers le haut
        ray.side_dist_y = (data->player->y - map_y) * ray.delta_dist_y;
    }
    else
    {
        ray.step_y = 1; // Vers le bas
        ray.side_dist_y = (map_y + 1.0 - data->player->y) * ray.delta_dist_y;
    }
    // Boucle algo DDA
    ray.touch_wall = false; // Mur pas toucher
    int side = 0; // Type de mur toucher 0 mur vertical 1 mur horizontal
    while (!ray.touch_wall)
    {
        if (ray.side_dist_x < ray.delta_dist_y) 
        {
            ray.side_dist_x += ray.delta_dist_x; // Avance le delta anticipe d un case
            map_x += ray.step_x; // Avande le rayon d une case
            side = 0; // Mur toucher est une ligne verticale
        }
        else
        {
            ray.side_dist_y += ray.delta_dist_y;
            map_y += ray.step_y;
            side = 1; // Mur toucher est une ligne horizontal
        }
        if (data->map->map_array[map_y][map_x] == '1')
            ray.touch_wall = true;
    }
    float perp_wall_dist;
    // Calcule pour connaitre la ditance perpendiculaire entre le mur et le joueur 
    if (side == 0) // Mur toucher bordure verticale
        perp_wall_dist = (map_x - data->player->x + (1 - ray.step_x) / 2) / ray_dir_x;
    else if (side == 1) // Mur toucher bordure horizontal
        perp_wall_dist = (map_y - data->player->y + (1 - ray.step_y) / 2) / ray_dir_y;
    printf("Distance au mur: %f\n", perp_wall_dist);
}
