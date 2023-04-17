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

long int	ft_abs(long int num)
{
	if (num < 0)
		num = -1 * num;
	return (num);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*link;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
		return (malloc(0));
	if (SIZE_MAX / size < count)
		return (NULL);
	link = malloc(count * size);
	if (!link)
		return (NULL);
	while (i++ < count * size)
		((char *)link)[i - 1] = '\0';
	return (link);
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	i;
	long int	num;
	int			size;

	i = 1;
	size = 2;
	num = n;
	while (num / i != 0 && size++ >= 0)
		i *= 10;
	str = ft_calloc(size, 1);
	if (!str)
		return (NULL);
	str[0] = '0';
	size = 0;
	if (num < 0)
		str[size++] = '-';
	num = ft_abs(num);
	while (i >= 10)
	{
		i /= 10;
		str[size++] = '0' + num / i;
		num %= i;
	}
	return (str);
}