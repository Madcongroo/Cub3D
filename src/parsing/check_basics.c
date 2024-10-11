/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:14:06 by proton            #+#    #+#             */
/*   Updated: 2024/10/11 15:07:45 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_switch(t_check *check, char c)
{
	if (c == 'n')
		return (check->N++, 1);
	else if (c == 's')
		return (check->S++, 1);
	else if (c == 'e')
		return (check->E++, 1);
	else if (c == 'w')
		return (check->W++, 1);
	else if (c == 'f')
		return (check->F++, 1);
	else
		return (check->C++, 1);
}

static int	is_line_valid(char *str, t_check *check, char c)
{
	int	i;

	if (c == 'n' || c == 's' || c == 'e' || c == 'w')
	{
		i = 2;
		while (str[i] != '.' && str[i])
		{
			if (str[i] != ' ' && str[i] != '\t')
				return (0);
			i++;
		}
		if (str[i] || (str[i] == '.' && str[i + 1] == '/'))
			return (check_switch(check, c));
	}
	else
	{
		i = 1;
		while (str[++i])
		{
			if (str[i] != ' ' && str[i] != '\t' && (str[i] < '0' && str[i] > '9'))
				return (0);
		}
		return (check_switch(check, c));
	}
	return (0);
}

static int check_char(char *str, t_check *check)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (is_line_valid(str, check, 'n'));
	if (str[0] == 'S' && str[1] == 'O')
		return (is_line_valid(str, check, 's'));
	if (str[0] == 'E' && str[1] == 'A')
		return (is_line_valid(str, check, 'e'));
	if (str[0] == 'W' && str[1] == 'E')
		return (is_line_valid(str, check, 'w'));
	if (str[0] == 'F')
		return (is_line_valid(str, check, 'f'));
	if (str[0] == 'C')
		return (is_line_valid(str, check, 'c'));
	if ((str[0] != 'N' || str[0] != 'S' || str[0] != 'E' || str[0] != 'W'
		|| str[0] != 'F' || str[0] != 'C' || str[0] != '0' || str[0] != '1'))
			return (-1);
	return (0);
}

/*checks if all the textures are on the map.
	If the map is at the bottom of the file / is on the file*/
int	check_basics(char **array)
{
	int		i;
	t_check	check;
	
	i = -1;
	ft_memset(&check, 0, sizeof(t_check));
	while (array[++i])
	{
		array[i] = ft_strtrim(array[i], " 	");
		if (!array[i])
			return (ft_free_array(array));
		check_char(array[i], &check);
	}
	if (check.N != 1 || check.S != 1 || check.E != 1
		|| check.W != 1 || check.F != 1 || check.C != 1)
			return (-1);
	return (0);
}
