/*













*/

#include "../../include/cub3d.h"

int	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else if (c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}
// Fonction pour supprimer tout les espace dans le chemin
char *remove_sup_space(char *str)
{
    int i;
    int j;
    char *new_str;

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
char *skip_space(char *str)
{
	while (*str && ft_is_whitespace(*str))
		str++;
	return (str);
}