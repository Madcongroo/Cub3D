/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:59:39 by bproton           #+#    #+#             */
/*   Updated: 2024/12/10 10:47:44 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*transfer_after_n(char *remind)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	while (remind[i] != '\n' && remind[i] != '\0')
		i++;
	if (remind[i] == '\0')
	{
		free(remind);
		return (NULL);
	}
	i++;
	new = (char *)malloc(sizeof(char) * (ft_strlen(remind) - i + 1));
	if (!new)
		return (NULL);
	while (remind[i] != '\0')
		new[j++] = remind[i++];
	new[j] = '\0';
	free(remind);
	return (new);
}

char	*transfer_to_n(char *remind)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	if (!remind[i])
		return (NULL);
	while (remind[i] != '\n' && remind[i] != '\0')
		i++;
	new = (char *)malloc(sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	while (j < i)
	{
		new[j] = remind[j];
		j++;
	}
	if (remind[j] == '\n')
		new[j++] = '\n';
	new[j] = '\0';
	return (new);
}

char	*ft_duporjoin(char *remind, char *buffer)
{
	char	*temp;

	if (remind)
	{
		temp = remind;
		remind = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
	}
	else
		remind = ft_strdup(buffer);
	return (remind);
}

char	*read_function(char *remind, int fd)
{
	char	*buffer;
	int		check;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	check = 1;
	while (check != 0)
	{
		check = read(fd, buffer, BUFFER_SIZE);
		if (check == -1)
		{
			free(buffer);
			free(remind);
			return (NULL);
		}
		buffer[check] = '\0';
		remind = ft_duporjoin(remind, buffer);
		if (check_if_n(remind))
			break ;
	}
	free(buffer);
	return (remind);
}

char	*get_next_line(int fd)
{
	static char	*remind;
	char		*newline;

	if (fd < 0 || !BUFFER_SIZE)
		return (NULL);
	remind = read_function(remind, fd);
	if (!remind)
	{
		free(remind);
		return (NULL);
	}
	newline = transfer_to_n(remind);
	remind = transfer_after_n(remind);
	return (newline);
}
