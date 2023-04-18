/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:49:16 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/18 17:36:56 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	while (read(fd, &c, 1) > 0 && c && ((c >= 32 && c <= 127) || c == '\n'))
		len++;
	close(fd);
	return (len);
}

char	*type_check(const char *haystack, const char *needle)
{
	int	i;

	i = 0;
	if (!haystack)
	{
		ft_putstr("Wrong file type.");
		return (NULL);
	}
	while (*needle != haystack[i] && haystack[i])
		i++;
	if (!(haystack[i]) || haystack[i - 1] == '.')
	{
		ft_putstr("Wrong file type.");
		return (NULL);
	}
	while (*needle == haystack[i])
	{
		if (*needle == '\0' && haystack[i] == '\0')
			return ((char *)haystack);
		i++;
		needle++;
	}
	ft_putstr("Wrong file type.");
	return (NULL);
}
