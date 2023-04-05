#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	char	*buff;
	char	*validate;

	int i = 0;
	if (argc == 2)
	{
		buff = ft_mapread(argv[1]);
		map = ft_mapsplit(buff);
		validate = ft_mapvalid(map);
		if (validate)
			printf("%s\n", validate);
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
	}
	return (0);
}