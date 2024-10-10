/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proton <proton@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 11:13:56 by bproton           #+#    #+#             */
/*   Updated: 2024/10/10 14:35:01 by proton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_wordcount(const char *s, char c)
{
	size_t	i;
	size_t	wcnt;

	i = 0;
	wcnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wcnt++;
		i++;
	}
	return (wcnt);
}

static	char	*ft_printwords(const char *s, char c, size_t word)
{
	size_t	j;
	char	*str;

	j = 0;
	str = (char *)malloc(sizeof(char) * (word + 1));
	if (!str)
		return (NULL);
	if (word == 0)
		return (NULL);
	while (*s != c && *s)
	{
		if (j >= word)
			break ;
		str[j] = *s;
		j++;
		s++;
	}
	str[j] = '\0';
	return (str);
}

static	char	**ft_wordlength(char **str, const char *s, char c, size_t j)
{
	size_t	sep;
	size_t	word;
	size_t	i;

	sep = 0;
	i = 0;
	while (i < j)
	{
		word = 0;
		while (s[sep] == c)
			sep++;
		while (s[sep + word] != c && s[sep + word])
			word++;
		str[i] = ft_printwords(s + sep, c, word);
		sep += word;
		i++;
	}
	return (str);
}

static	void	ft_free(char **str, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(str[i]);
		i++;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	char	**str;

	if (s == NULL)
		return (NULL);
	j = ft_wordcount(s, c);
	str = (char **)malloc(sizeof(char *) * (j + 1));
	if (!str)
		return (NULL);
	str = ft_wordlength(str, s, c, j);
	if (!str)
		ft_free(str, j);
	str[j] = NULL;
	return (str);
}

/*int main(void)
{
	const char s[] = "sal utc ava";
	char **s2;
	size_t i;

	i = 0;
	s2 = ft_split(s, ' ');
	if (s2) 
	{
		while (s2[i] != NULL)
		{
			printf("%s\n", s2[i]);
			free(s2[i]);
			i++;
		}
		free(s2);
	}
	return 0;
}*/