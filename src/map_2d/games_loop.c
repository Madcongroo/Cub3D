/*













*/
#include "../../include/cub3d.h"

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}
void games_loop(t_data *data)
{
    mlx_hook(data->win, 17, 0, close_window, data);
    mlx_loop(data->mlx);
}