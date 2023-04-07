#include "so_long.h"

int handle_keypress(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 53)
		exit(0);
    return 0;
}

int	maprender(char	**map)
{
	t_vars	vars;
	char	*relative_path = "./brick.xpm";
	int		img_width;
	int		img_height;
	t_point	point;

	point = (t_point){0};
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "so_long");
	vars.x = 400;
	vars.y = 400;
	vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	vars.empty_img = mlx_new_image(vars.mlx, img_width, img_height);
	while (map[point.y])
	{
		while (map[point.y][point.x])
		{
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.x + (img_width * point.x) , vars.y + (img_height * point.y));
			point.x++;
		}
		point.x = 0;
		point.y++;
	}
	// mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}

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
		maprender(map);
	}
	return (0);
}