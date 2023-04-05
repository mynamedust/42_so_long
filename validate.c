#include "so_long.h"

char	*ft_chrvalid(char **map)
{
	int		j;
	v_chars list = {0, 0, 0};

	j = 0;
	while (*map)
	{
		while ((*map)[j])
		{
			if ((*map)[j] == 'E')
				list.e += 1;
			else if ((*map)[j] == 'P')
				list.p += 1;
			else if ((*map)[j] == 'C')
				list.c += 1;
			else if ((*map)[j] != '0' && (*map)[j] != '1')
				return ("Invalid input format.");
			j++;
		}
		j = 0;
		map++;
	}
	if (list.e != 1 || list.p != 1 || list.c < 1)
		return ("Invalid input format.");
	return (NULL);
}

char	*ft_wallvalid(char **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (i == 0 && map[i][j] != '1')
				return ("The map must be closed by walls.");
			if (map[i + 1] == NULL && map[i][j] != '1')
				return ("The map must be closed by walls.");
			if ((j == 0 || j == ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return ("The map must be closed by walls.");
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}

char	*ft_rectangvalid(char **map)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(*map);
	while (map[j])
	{
		if (len != ft_strlen(map[j]))
			return ("Invalid input format.");
		j++;
	}
	if (j < 2 || len < 2)
		return ("Invalid input format.");
	return (NULL);
}

char	*ft_mapvalid(char	**map)
{
	char	*message;

	if ((message = ft_chrvalid(map)) != NULL)
		return (message);
	if ((message = ft_wallvalid(map)) != NULL)
		return (message);
	if ((message = ft_rectangvalid(map)) != NULL)
		return (message);
	// if (message = ft_pathvalid(map))
	// 	return (message);
	return (NULL);
}

// typedef struct	s_point
// {
// 	int			x;
// 	int			y;
// }				t_point;

// void	fill(char **tab, t_point size, t_point point, char f_chr)
// {
// 	if (point.x < 0 || point.x >= size.x || point.y < 0 || point.y >= size.y 
// 		|| tab[point.y][point.x] != f_chr)
// 		return ;
// 	tab[point.y][point.x] = 'F';
// 	fill(tab, size, (t_point){point.x - 1, point.y}, f_chr);
// 	fill(tab, size, (t_point){point.x, point.y - 1}, f_chr);
// 	fill(tab, size, (t_point){point.x, point.y + 1}, f_chr);
// 	fill(tab, size, (t_point){point.x + 1, point.y}, f_chr);
// }

// void	ft_pathvalid(char **map)
// {
// 	int		e;
// 	t_point	p;

// 	e = 0;
// 	p = {0, 0};
// 	while (map[p.y])
// 	{
// 		while (map[p.y][p.x])
// 		{
// 			if (map[p.y][p.x] == 'P')
// 				break ;
// 			p.x++;
// 		}
// 		if (map[p.y][p.x] == 'P')
// 			break ;
// 		p.x = 0;
// 		p.y++;
// 	}
// 	fill(tab, size, begin, tab[begin.y][begin.x]);
// }