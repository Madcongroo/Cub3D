/*
HEADER










HEADER
*/

#include "./include/cub3d.h"

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->player = NULL;
	data->raycast = NULL;
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2 && argv[2])
		return (free_all(&data, "Error\nNumber of arguments\n"));
	init_struct(&data);
	if (start_parsing(&data, argv[1]) == -1)
		return (free_all(&data, "Error\nMap error\n"));
	
}
