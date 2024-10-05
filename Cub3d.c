/*
HEADER








HEADER
*/

#include "./include/cub3d.h"

void	init_struct(t_data *data)
{
	data->map = NULL;
	data->player = NULL;
	data->text = NULL;
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2 && argv[2])
		return (free_all(&data, "Wrong nuber of arguments\n"));
	init_struct(&data);
	
}
