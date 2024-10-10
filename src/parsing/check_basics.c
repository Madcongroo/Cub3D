/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:14:06 by proton            #+#    #+#             */
/*   Updated: 2024/10/10 16:02:42 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int check_char(char *str, t_check *check)
{
	if (str[0] == 'N' && str[1] == 'O' && check->N == NULL)
		return (check->N = 1, 1);
	if (str[0] == 'S' && str[1] == 'O' && check->S == NULL)
		return (check->S = 1, 1);
	if (str[0] == 'E' && str[1] == 'A' && check->E == NULL)
		return (check->E = 1, 1);
	if (str[0] == 'W' && str[1] == 'E' && check->W == NULL)
		return (check->W = 1, 1);
	if (str[0] == 'F' && check->F == NULL)
		return (check->F = 1, 1);
	if (str[0] == 'C' && check->C == NULL)
		return (check->C = 1, 1);
	return (0);
}

/*checks if all the textures are on the map.
	If the map is at the bottom of the file / is on the file*/
int	first_map_check(char **array)
{
	int		i;
	int		count;
	t_check	check;
	
	i = -1;
	count = 0;
	check.C = 0;
	check.E = 0;
	check.F = 0;
	check.N = 0;
	check.S = 0;
	check.W = 0;
	while (array[++i])
		count += check_char(array[i], &check);
	
	return (0);
}
