#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>

int	ft_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		perror("Open Error. Open failed on input file");	
	return (fd);
}

int	ft_filelen(char *file)
{
	int		len;
	char	c;
	int		fd;
	
	fd = ft_open(file);
	if (fd == -1)
		exit(0);
	len = 0;
	while (read(fd, &c, 1) > 0)
		len++;
	close(fd);
	return (len);
}

char	*ft_mapread(char *file)
{
	char	*map;
	int		fd;
	int		buffsize;

	buffsize = ft_filelen(file);
	if (buffsize <= 0)
	{
		perror("Read Error. Empty file");
		exit(0);
	}
	map = malloc(buffsize + 1);
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
	while (str[i]  && str[i] == '\n')
	{
		i++;
		printf("asdasd");
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] != '\0' && str[i + 1] != '\n')
			count++;
		i++;
	}
	printf("%d\n", count);
	return (count);
}

char	*ft_getline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc (i + 1);
	line[i] = '\0';
	i = 0;
	while (*str && *str != '\n')
	{
		line[i] = *str;
		i++;
		str++;
	}
	return (line);
}

char	**ft_mapsplit(char	*str)
{
	int		i;
	int		size;
	char	**map;

	if (!str)
		return (NULL);
	size = ft_linecount(str);
	i = 0;
	map = malloc (sizeof(char *) * (size + 1));
	if (!map)
	{
		perror("Malloc Error. Memory allocaton failed");
		exit(0);
	}
	while (*str)
	{
		while (*str && *str == '\n')
			str++;
		if (*str && *str != '\n')
			map[i++] = ft_getline(str);
		while (*str && *str != '\n')
			str++;
	}
	map[i] = NULL;
	return (map);
}

int	main(int argc, char **argv)
{
	char	**map;
	char	*buff;
	int i = 0;

	if (argc == 2)
	{
		buff = ft_mapread(argv[1]);
		// printf("%s\n", buff);
		map = ft_mapsplit(buff);
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
	return (0);
}