/*
HEADER










HEADER
*/

#include "cub3d.h"

void	display_array(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
}
