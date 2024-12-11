/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmartin2 <tmartin2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:07:12 by tmartin2          #+#    #+#             */
/*   Updated: 2024/12/11 16:07:15 by tmartin2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !n)
		return (NULL);
	str = malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	while (n)
	{
		str[i] = s[i];
		i++;
		n--;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strncpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	if (size < 2)
		return (NULL);
	while (src[i] && i < size)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int	good_char(char c)
{
	if (c != 'N' && c != 'S' && c != 'E' && c != 'W' && c != '0'
		&& c != '1' && !ft_is_whitespace(c))
		return (1);
	return (0);
}

// Fonction pour supprimer tout les espace dans le chemin
char	*remove_sup_space(char *str)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	new_str = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (!ft_is_whitespace(str[i]))
		{
			new_str[j] = str[i];
			j++;
		}
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

// Fonction pour supprimer les espace entre le nom de la texture et sont chemin
char	*skip_space(char *str)
{
	while (*str && ft_is_whitespace(*str))
		str++;
	return (str);
}
