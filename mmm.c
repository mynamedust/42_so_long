#include "so_long.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	void	*empty_img;
	int 	x;
	int 	y;
	int		prev_x;
	int		prev_y;
}				t_vars;

int	closee(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int handle_keypress(int keycode, t_vars *vars)
{
	vars->prev_x = vars->x;
    vars->prev_y = vars->y;
	mlx_put_image_to_window(vars->mlx, vars->win, vars->empty_img, vars->prev_x , vars->prev_y );

    if (keycode == 13)
        vars->y -= 10; 
    else if (keycode == 1)
        vars->y += 10;
    else if (keycode == 0)
        vars->x -= 10;
    else if (keycode == 2)
        vars->x += 10;
	else if (keycode == 53)
		exit(0);

    mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x, vars->y);
    return 0;
}

int	maprender()
{
	
}

int	main()
{
	t_vars	vars;
	char	*relative_path = "./brick.xpm";
	int		img_width;
	int		img_height;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.x = 200;
	vars.y = 200;
	vars.img = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	vars.empty_img = mlx_new_image(vars.mlx, img_width, img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, vars.x, vars.y);
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
	