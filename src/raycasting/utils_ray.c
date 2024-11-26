/*













*/

#include "../../include/cub3d.h"

void	my_pixel_put_rgb(t_data *data, int x, int y, t_rgb *color)
{
	unsigned int	color_transform;

	color_transform = (color->r << 16) | (color->g << 8) | color->b;
	my_pixel_put(data, x, y, color_transform);
}
