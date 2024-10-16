/*
HEADER










HEADER
*/

#include "./include/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2 && argv[2])
		return (free_all(&data));
	if (init_struct(&data) == -1)
		return (free_all(&data));
	if (start_parsing(&data, argv[1]) == -1)
		return (free_all(&data));
	if (start_map_2d(&data) == -1)
		return (free_all(&data));
	free_all(&data);
	
}
