#include "so_long.h"

void	*select_txtr(int c, int x, int y, t_vars s)
{
	if (c == '5' || c == 'U' || c == 'H')
		return (s.textures.back);
	if (c == 'J' && s.coins > 0)
		return (s.textures.portal_off);
	if (c == 'J' && s.coins == 0)
		return (s.textures.portal_on);
	if (c == '1')
	{
		if (y == 0 && x != 0 && x != s.mapsize.x - 1)
		{
			if (s.map[y + 1][x] == '1')
				return (s.textures.in_wall);
			return (s.textures.t_wall);
		}
		if (y == s.mapsize.y - 1 && x != 0 && x != s.mapsize.x - 1)
			return (s.textures.b_wall);
		if (x == 0)
		{
			if (y == s.mapsize.y - 1)
				return (s.textures.lb_wall);
			return (s.textures.l_wall);
		}
		if (x == s.mapsize.x - 1)
		{
			if (y == s.mapsize.y - 1)
				return (s.textures.rb_wall);
			return (s.textures.r_wall);
		}
		if (s.map[y + 1][x] != '1')
			return (s.textures.b_wall);
	}
	return (s.textures.in_wall);
}

int	peak_anim(t_vars *vars)
{
	static int	ii;
	
	// if (ii % 2000 == 0)
	// 	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.back , 200, 200);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.peak1 , 700, 300);
	if (ii % 8000 == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.peak4 , 700, 300);
		ii = 0;
	}
	else if (ii % 6000 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.peak3, 700, 300);
	else if (ii % 4000 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.peak2, 700, 300);
	else if (ii % 2000 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.peak1, 700, 300);
	ii++;
	printf("%d - num\n", ii);
	return (0);
}

int	maprender(t_vars vars, int x, int y)
{
	while (vars.map[y])
	{
		while (vars.map[y][x])
		{
			mlx_put_image_to_window(vars.mlx, vars.win,
				select_txtr(vars.map[y][x], x, y, vars), 50 * x, 50 * y);
			if (vars.map[y][x] == 'H')
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.textures.flask, 50 * x, 50 * y);
			if (vars.map[y][x] == 'S')
			{
				mlx_loop_hook(vars.mlx, peak_anim, &vars);
				printf("entry\n");
			}
			if (vars.map[y][x] == 'U')
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.textures.player1, 50 * x, 50 * y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	paths_init(t_texture *textures)
{
	textures->paths[0] = "./textures/inwall.xpm";
	textures->paths[1] = "./textures/topwall.xpm";
	textures->paths[2] = "./textures/leftwall.xpm";
	textures->paths[3] = "./textures/leftbotwall.xpm";
	textures->paths[4] = "./textures/rightwall.xpm";
	textures->paths[5] = "./textures/rightbotwall.xpm";
	textures->paths[6] = "./textures/botwall.xpm";
	textures->paths[7] = "./textures/back.xpm";
	textures->paths[8] = "./textures/portalon.xpm";
	textures->paths[9] = "./textures/portaloff.xpm";
	textures->paths[10] = "./textures/flask.xpm";
	textures->paths[11] = "./textures/player1.xpm";
	textures->paths[12] = "./textures/player2.xpm";
	textures->paths[13] = "./textures/player3.xpm";
	textures->paths[14] = "./textures/player4.xpm";
	textures->paths[15] = "./textures/youdie.xpm";
	textures->paths[16] = "./textures/die_mini.xpm";
	textures->paths[17] = "./textures/peak1.xpm";
	textures->paths[18] = "./textures/peak2.xpm";
	textures->paths[19] = "./textures/peak3.xpm";
	textures->paths[20] = "./textures/peak4.xpm";
}

void	textures_init(t_vars vars, t_texture *textures)
{
	int	img_wd;
	int	img_hg;

	textures->in_wall = mlx_xpm_file_to_image(vars.mlx, textures->paths[0],
			&img_wd, &img_hg);
	textures->t_wall = mlx_xpm_file_to_image(vars.mlx, textures->paths[1],
			&img_wd, &img_hg);
	textures->l_wall = mlx_xpm_file_to_image(vars.mlx, textures->paths[2],
			&img_wd, &img_hg);
	textures->lb_wall = mlx_xpm_file_to_image(vars.mlx, textures->paths[3],
			&img_wd, &img_hg);
	textures->r_wall = mlx_xpm_file_to_image(vars.mlx, textures->paths[4],
			&img_wd, &img_hg);
	textures->rb_wall = mlx_xpm_file_to_image(vars.mlx, textures->paths[5],
			&img_wd, &img_hg);
	textures->b_wall = mlx_xpm_file_to_image(vars.mlx, textures->paths[6],
			&img_wd, &img_hg);
	textures->back = mlx_xpm_file_to_image(vars.mlx, textures->paths[7],
			&img_wd, &img_hg);
	textures->portal_on = mlx_xpm_file_to_image(vars.mlx, textures->paths[8],
			&img_wd, &img_hg);
	textures->portal_off = mlx_xpm_file_to_image(vars.mlx, textures->paths[9],
			&img_wd, &img_hg);
	textures->flask = mlx_xpm_file_to_image(vars.mlx, textures->paths[10],
			&img_wd, &img_hg);
	textures->player1 = mlx_xpm_file_to_image(vars.mlx, textures->paths[11],
			&img_wd, &img_hg);
	textures->player2 = mlx_xpm_file_to_image(vars.mlx, textures->paths[12],
			&img_wd, &img_hg);
	textures->player3 = mlx_xpm_file_to_image(vars.mlx, textures->paths[13],
			&img_wd, &img_hg);
	textures->player4 = mlx_xpm_file_to_image(vars.mlx, textures->paths[14],
			&img_wd, &img_hg);
	textures->youdie = mlx_xpm_file_to_image(vars.mlx, textures->paths[15],
			&img_wd, &img_hg);
	textures->die_mini = mlx_xpm_file_to_image(vars.mlx, textures->paths[16],
			&img_wd, &img_hg);
	textures->peak1 = mlx_xpm_file_to_image(vars.mlx, textures->paths[17],
			&img_wd, &img_hg);
	textures->peak2 = mlx_xpm_file_to_image(vars.mlx, textures->paths[18],
			&img_wd, &img_hg);
	textures->peak3 = mlx_xpm_file_to_image(vars.mlx, textures->paths[19],
			&img_wd, &img_hg);
	textures->peak4 = mlx_xpm_file_to_image(vars.mlx, textures->paths[20],
			&img_wd, &img_hg);
}

void	game_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->mapsize.x * 50, vars->mapsize.y * 50, "so_long");
	paths_init(&vars->textures);
	textures_init(*vars, &vars->textures);
	maprender(*vars, 0, 0);
}