/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_file_caracters.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 18:41:24 by proton            #+#    #+#             */
/*   Updated: 2024/12/10 10:48:03 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	count_file_chars(char *file)
{
	int		fd;
	int		len;
	int		check;
	char	*line;

	len = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	check = 1;
	while (check != 0)
	{
		line = get_next_line(fd);
		if (!line)
			check = 0;
		if (line)
			len += ft_strlen(line);
		if (line)
			free (line);
	}
	close (fd);
	return (len);
}
