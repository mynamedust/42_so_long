int	ft_anim(t_vars *vars)
{
	static int	i;
	static int	s;
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (vars->die == 1)
	{
		if (vars->mapsize.y > 4 && vars->mapsize.x >= 16)
			mlx_put_image_to_window(vars->mlx, vars->win,
					vars->textures.youdie, (vars->mapsize.x - 16) * 25,
						(vars->mapsize.y - 5) * 25);
		else
			mlx_put_image_to_window(vars->mlx, vars->win,
				vars->textures.die_mini, (vars->mapsize.x - 7) * 25,
				(vars->mapsize.y - 3) * 25);
		return (0);
	}
	if (i % 8000 == 0)
		i = 0;
	if (i % 2000 == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.back , vars->x * 50,vars->y * 50);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.pl_s[s] , vars->x * 50,vars->y * 50);
		s++;
		if (s > 3)
			s = 0;
		while (vars->map[y])
		{
			while (vars->map[y][x])
			{
				if (vars->map[y][x] == 'S')
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->textures.peak_s[s], 50 * x, 50 * y);
				if (vars->map[y][x] == 'H')
				{
					mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.back , x * 50, y * 50);
					mlx_put_image_to_window(vars->mlx, vars->win,
						vars->textures.flask_s[s], 50 * x, 50 * y);
				}
				x++;
			}
			x = 0;
			y++;
		}
	}
	i++;
	return (0);
}