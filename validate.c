#include "so_long.h"

char	*ft_chrvalid(char **map, int j, int i)
{
	t_chars list;

	list = (t_chars){0};
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				list.e += 1;
			else if (map[i][j] == 'P')
				list.p += 1;
			else if (map[i][j] == 'C')
				list.c += 1;
			else if (map[i][j] != '\0' && map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'S')
				return ("Invalid input format.");
			j++;
		}
		j = 0;
		i++;
	}
	if (list.e != 1 || list.p != 1 || list.c < 1)
		return ("Invalid input format.");
	return (NULL);
}

char	*ft_wallvalid(t_vars *vars, char **map)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				vars->x = j;
				vars->y = i;
			}
			if ((i == 0 && map[i][j] != '1') ||
				(map[i + 1] == NULL && map[i][j] != '1'))
				return ("The map must be closed by walls.");
			if ((j == 0 || j == ft_strlen(map[i]) - 1) && map[i][j] != '1')
				return ("The map must be closed by walls.");
			j++;
		}
		vars->mapsize.x = j;
		j = 0;
		i++;
	}
	vars->mapsize.y = i;
	return (NULL);
}

char	*ft_rectangvalid(char **map)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(*map);
	while (*map)
	{
		if (len != ft_strlen(*map))
			return ("Invalid input format.aaa");
		map++;
		j++;
	}
	if (j < 2 || len < 2)
		return ("Invalid input format.");
	return (NULL);
}

void	fill(t_vars *vars, char **map, t_point point)
{
	if (point.x < 0 || point.x >= ft_strlen(map[point.y]) || point.y < 0 || map[point.y] == NULL 
		|| !(map[point.y][point.x] == 'C' || map[point.y][point.x] == '0'
		|| map[point.y][point.x] == 'E' || map[point.y][point.x] == 'P'))
		return ;
	if (map[point.y][point.x] == 'C')
		vars->coins++;
	map[point.y][point.x] += 5;
	fill(vars, map, (t_point){point.x - 1, point.y});
	fill(vars, map, (t_point){point.x, point.y - 1});
	fill(vars, map, (t_point){point.x, point.y + 1});
	fill(vars, map, (t_point){point.x + 1, point.y});
}

char	*ft_pathvalid(t_vars *vars,char **map)
{
	int		e;
	t_point	p;

	e = 0;
	p = (t_point){0};
	while (map[p.y])
	{
		while (map[p.y][p.x])
		{
			if (map[p.y][p.x] == 'P')
				break ;
			p.x++;
		}
		if (map[p.y][p.x] == 'P')
			break ;
		p.x = 0;
		p.y++;
	}
	fill(vars, map, p);
	if (ft_mapchr(map, 'C') || ft_mapchr(map, 'E'))
		return ("Path validation failed");
	return (NULL);
}

char	*ft_mapvalid(t_vars *vars, char	**map)
{
	char	*message;
	
	if ((message = ft_chrvalid(map, 0, 0)) != NULL)
		return (message);
	if ((message = ft_wallvalid(vars, map)) != NULL)
		return (message);
	if ((message = ft_rectangvalid(map)) != NULL)
		return (message);
	if ((message = ft_pathvalid(vars, map)) != NULL)
		return (message);
	return (NULL);
}