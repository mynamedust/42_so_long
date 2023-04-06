#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_mapchr(char **map, int c)
{
	int	i;

	i = 0;
	while (*map)
	{
		while ((*map)[i])
		{
			if ((*map)[i] == c)
				return (&((*map)[i]));
			i++;
		}
		i = 0;
		map++;
	}
	return (NULL);
}