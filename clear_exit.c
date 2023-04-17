void	map_clear(t_vars *vars, int i)
{
	while (vars->map[i])
	{
		free(map[i]);
		i++;
	}
	free(vars->map);
}

void	image_clear(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->textures->in_wall);
	mlx_destroy_image(vars->mlx, vars->textures->t_wall);
	mlx_destroy_image(vars->mlx, vars->textures->l_wall);
	mlx_destroy_image(vars->mlx, vars->textures->lb_wall);
	mlx_destroy_image(vars->mlx, vars->textures->r_wall);
	mlx_destroy_image(vars->mlx, vars->textures->rb_wall);
	mlx_destroy_image(vars->mlx, vars->textures->b_wall);
	mlx_destroy_image(vars->mlx, vars->textures->back);
	mlx_destroy_image(vars->mlx, vars->textures->portal_on);
	mlx_destroy_image(vars->mlx, vars->textures->portal_off);
	mlx_destroy_image(vars->mlx, vars->textures->flask_s[0]);
	mlx_destroy_image(vars->mlx, vars->textures->flask_s[1]);
	mlx_destroy_image(vars->mlx, vars->textures->flask_s[2]);
	mlx_destroy_image(vars->mlx, vars->textures->flask_s[3]);
	mlx_destroy_image(vars->mlx, vars->textures->pl_s[0]);
	mlx_destroy_image(vars->mlx, vars->textures->pl_s[1]);
	mlx_destroy_image(vars->mlx, vars->textures->pl_s[2]);
	mlx_destroy_image(vars->mlx, vars->textures->pl_s[3]);
	mlx_destroy_image(vars->mlx, vars->textures->youdie);
	mlx_destroy_image(vars->mlx, vars->textures->die_mini);
	mlx_destroy_image(vars->mlx, vars->textures->peak_s[0]);
	mlx_destroy_image(vars->mlx, vars->textures->peak_s[1]);
	mlx_destroy_image(vars->mlx, vars->textures->peak_s[2]);
	mlx_destroy_image(vars->mlx, vars->textures->peak_s[3]);
}

void exit_clear(t_vars *vars)
{
	map_clear(vars, 0);
	image_clear(vars);
	exit(0);
}