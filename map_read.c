/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:42:03 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/18 14:42:03 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_mapread(char *file, int buffsize, int fd)
{
	char	*map;

	buffsize = ft_filelen(file);
	if (buffsize <= 0)
	{
		perror("Read Error. Empty file");
		exit(0);
	}
	map = malloc(buffsize + 1);
	map[buffsize] = '\0';
	if (!map)
	{
		perror("Malloc Error. Memory allocaton failed");
		exit(0);
	}
	fd = ft_open(file);
	if (fd == -1)
	{
		free(map);
		exit(0);
	}
	read(fd, map, buffsize);
	close(fd);
	return (map);
}

int	ft_linecount(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] == '\n' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		if (str[i] == '\n' && str[i + 1] == '\n')
			break ;
		i++;
	}
	if (str[i - 1] != '\n')
		count++;
	return (count);
}

char	*ft_getline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n' && str[i] != 2 && str[i] != 127)
		i++;
	line = malloc (i + 1);
	line[i] = '\0';
	i = 0;
	while (*str && *str != '\n' && *str != 2 && *str != 127)
	{
		line[i] = *str;
		i++;
		str++;
	}
	return (line);
}

char	**ft_mapsplit(char	*str, int size, int i)
{
	char	**map;

	if (!str)
		return (NULL);
	size = ft_linecount(str);
	map = malloc (sizeof(char *) * (size + 1));
	if (!map)
	{
		perror("Malloc Error. Memory allocaton failed");
		exit(0);
	}
	while (*str && *str == '\n')
			str++;
	while (*str)
	{
		if (*str && *str != '\n' && *str != '\r')
			map[i++] = ft_getline(str);
		while (*str && *str != '\n')
			str++;
		if (*str == '\n')
			str++;
	}
	map[i] = NULL;
	return (map);
}
