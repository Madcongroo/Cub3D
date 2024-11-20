/*













*/

#include "../../include/cub3d.h"
void init_ray(t_raycast *ray)
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

void raycast_ray(t_data *data)
{
    int x;
    t_raycast ray;
    float camera_x;
    int line_height;

    x = 0;
    while (x < data->win_width)
    {
        init_ray(&ray);
        // Calcule chaque postion de chaque rayon dans le FOV
        camera_x = 2 * x / (float)data->win_width - 1;
        // Calcule la direction de rayon grace a direction de la cam
        ray.ray_dir_x = data->player->x_cam + data->player->plan_x * camera_x;
        ray.ray_dir_y = data->player->y_cam + data->player->plan_y * camera_x;
        // Transforme la pos joueur de pixel a case sur map
        ray.map_x = (int)data->player->x;
        ray.map_y = (int)data->player->y;
        // Calcule la distance jusqu a la prochaine ligne depuis joueur(delta)
        ray.delta_dist_x = fabs(1 / ray.ray_dir_x);
        ray.delta_dist_y = fabs(1 / ray.ray_dir_y);
        // Calcule step et side
        if (ray.ray_dir_x < 0)
        {
            ray.step_x = -1; // Ce deplace vers la gauche
            ray.side_dist_x = (data->player->x - ray.map_x) * ray.delta_dist_x; // distance entre joueur et prochaine ligne verticale a gauche
        }
        else
        {
            ray.step_x = 1; // Ce deplace vers la droite
            ray.side_dist_x = (ray.map_x + 1.0 - data->player->x) * ray.delta_dist_x;
        }
        if (ray.ray_dir_y < 0)
        {
            ray.step_y = -1; // Ce deplace vers le haut
            ray.side_dist_y = (data->player->y - ray.map_y) * ray.delta_dist_y;
        }
        else
        {
            ray.step_y = 1; // Ce deplace vers le bas
            ray.side_dist_y = (ray.map_y + 1.0 - data->player->y) * ray.delta_dist_y;
        }
        // Algo DDA
        while (!ray.touch_wall)
        {
            // Croise une ligne verticale car dist x plus petit
            if (ray.side_dist_x < ray.side_dist_y)
            {
                ray.side_dist_x += ray.delta_dist_x; // on ajoute a side la distance de la case
                ray.map_x += ray.step_x; // Avance le rayon dans la direction de dir_x actuel
                ray.side = 0; // mur verticale
            }
            else // Croise une ligne horizontal car dist y plus petit
            {
                ray.side_dist_y += ray.delta_dist_y;
                ray.map_y += ray.step_y;
                ray.side = 1; // Mur horizontal
            }
            if (data->map->map_array[ray.map_y][ray.map_x] == '1')
                ray.touch_wall = true;
        }
        // Calculer la distance perpendiculaire au mur
        if (ray.side == 0)
            ray.perp_wall_dist = (ray.map_x - data->player->x + (1 - ray.step_x) / 2) / ray.ray_dir_x;
        else
            ray.perp_wall_dist = (ray.map_y - data->player->y + (1 - ray.step_y) / 2) / ray.ray_dir_y;
        // Calcule la hauteur de la ligne pour le rayon
        line_height = (int)(data->win_height / ray.perp_wall_dist);
        // Calculer les coordonnées de début et de fin de la ligne (hauteur du mur)
        int draw_start = -line_height / 2 + data->win_height / 2;
        if (draw_start < 0) // commence a dessiner a partir de la hauteur de l ecran
            draw_start = 0;
        int draw_end = line_height / 2 + data->win_height / 2;
        if (draw_end >= data->win_height) // commence a partir du bas de l ecran
            draw_end = data->win_height - 1;
        int color;
        if (ray.side == 0)
            color = RED;
        else
            color = RED_RUSH;
        int y = draw_start;
        while (y < draw_end)
        {
            my_pixel_put(data, x, y, color);
            y++;
        }
        x++;
    }
}
