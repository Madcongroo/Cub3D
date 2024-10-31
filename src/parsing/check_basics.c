/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_basics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 15:14:06 by proton            #+#    #+#             */
/*   Updated: 2024/10/29 10:46:43 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_switch(t_check *check, char c)
{
	if (c == 'n')
		return (check->n++, 1);
	else if (c == 's')
		return (check->s++, 1);
	else if (c == 'e')
		return (check->e++, 1);
	else if (c == 'w')
		return (check->w++, 1);
	else if (c == 'f')
		return (check->f++, 1);
	else
		return (check->c++, 1);
}

static int	is_line_valid(char *str, t_check *check, char c)
{
	int	i;

	if (c == 'n' || c == 's' || c == 'e' || c == 'w')
	{
		i = 2;
		while (str[i] != '.' && str[i])
		{
			if (!ft_is_whitespace(str[i++]))
				return (0);
		}
		if (str[i] || (str[i] == '.' && str[i + 1] == '/'))
			return (check_switch(check, c));
	}
	else
	{
		i = 1;
		while (str[++i])
		{
			if (!ft_is_whitespace(str[i]) && str[i] != ','
				&& (str[i] < '0' || str[i] > '9'))
				return (0);
		}
		return (check_switch(check, c));
	}
	return (0);
}

static int	check_char(char *str, t_check *check)
{
	if (str[0] == 'N' && str[1] == 'O')
		return (is_line_valid(str, check, 'n'));
	else if (str[0] == 'S' && str[1] == 'O')
		return (is_line_valid(str, check, 's'));
	else if (str[0] == 'E' && str[1] == 'A')
		return (is_line_valid(str, check, 'e'));
	else if (str[0] == 'W' && str[1] == 'E')
		return (is_line_valid(str, check, 'w'));
	else if (str[0] == 'F')
		return (is_line_valid(str, check, 'f'));
	else if (str[0] == 'C')
		return (is_line_valid(str, check, 'c'));
	else if ((str[0] != '0' && str[0] != '1') && (!ft_is_whitespace(str[0])))
		return (-1);
	return (0);
}

int	search_stop_trim(char **array)
{
	int	i;
	int	j;

	i = -1;
	while (array[++i])
	{
		j = 0;
		while (ft_is_whitespace(array[i][j]) && array[i][j])
			j++;
		if (array[i][j] == '0' || array[i][j] == '1')
			return (i);
		else
			continue ;
	}
	return (0);
}

/*set the check struct, trims each lines, checks if eache elements are there*/
/*rempli la structure check, enleve les espaces au debut et a la fin,
	regarde si tous les elements sont presents*/
int	check_basics(char **array)
{
	int		i;
	int		stop_trim;
	t_check	check;

	i = -1;
	ft_memset(&check, 0, sizeof(t_check));
	stop_trim = search_stop_trim(array);
	while (array[++i])
	{
		if (stop_trim > 0)
		{
			array[i] = ft_strtrim(array[i], " 	");
			if (!array[i])
				return (ft_free_array(array));
		}
		if (check_char(array[i], &check) == -1)
			return (error_msg("Error\nUnknown caracter\n"));
		stop_trim--;
	}
	if (check.n != 1 || check.s != 1 || check.e != 1
		|| check.w != 1 || check.f != 1 || check.c != 1)
		return (error_msg("Error\nA texture is missing\n"));
	return (0);
}
