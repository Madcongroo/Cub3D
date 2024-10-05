/*
HEADER







HEADER
*/

# ifndef CUB3D_H
# define CUB3D_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <limits.h>
#include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*fl;
	char	*ce;
}	t_textures;

typedef struct s_player
{
	int		pos_x;
	int		pox_y;

}	t_player;

typedef struct s_data
{
	char		**map;
	t_textures	*text;
	t_player	*player;


}	t_data;

/*Error gestion*/
int		free_all(t_data *data, char *str);
void	ft_free_array(char **array);


# endif