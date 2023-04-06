#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	closee(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	main(int argc, char **argv)
{
	char	**map;
	char	*buff;
	char	*validate;
	t_vars	vars;

	int i = 0;
	if (argc == 2)
	{
		buff = ft_mapread(argv[1]);
		map = ft_mapsplit(buff);
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
		printf("\n");
		i = 0;
		validate = ft_mapvalid(map);
		if (validate)
			printf("%s\n", validate);
		while (map[i])
		{
			printf("%s\n", map[i]);
			i++;
		}
	}

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_hook(vars.win, 2, 0, closee, &vars);
	mlx_loop(vars.mlx);

	return (0);
}