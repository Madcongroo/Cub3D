/*
HEADER










HEADER
*/

#include "./include/cub3d.h"

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2 && argv[2])
		return (free_all(&data, "Error\nNumber of arguments\n"));
	if (init_struct(&data) == -1)
		return (free_all(&data, "Error\nInitializing structs\n"));
	if (start_parsing(&data, argv[1]) == -1)
		return (free_all(&data, "Error\nMap error\n"));
	
}
