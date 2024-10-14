/*













*/
#include "../../include/cub3d.h"

int start_map_2d(t_data *data)
{
    data->mlx = mlx_init();
    if (!data->mlx)
        return (-1);
    data->win_width = 1920;
    data->win_height = 1080;
    data->win = mlx_new_window(data->mlx, data->win_width, data->win_height, "cub3D");
    if (!data->win)
        return (-1);
    games_loop(data);
    return (0);
}