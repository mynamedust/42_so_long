/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:54:23 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/11 22:43:47 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(int x, int y, t_vars *v)
{
	if (v.map[y][x] == '1')
		return (0);
	if (v->map[y][x] != 'J')
		return (1);
	if (v->coins > 0)
		return (0);
	exit(0);
}

void	player_action(int keycode, t_vars *v)
{
	if (keycode == 13 && !move_check(v->y - 1, v->x, v))
		move_to(v->y - 1, v->x, v);
    else if (keycode == 1 && !move_check(v->y + 1, v->x, v))
        move_to(v->y + 1, v->x, v);
    else if (keycode == 0 && !move_check(v->y, v->x - 1, v))
        move_to(v->y, v->x - 1, v);
    else if (keycode == 2 &&  && !move_check(v->y, v->x + 1, v))
        move_to(v->y, v->x + 1, v);
}

int	handle_keypress(int keycode, t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.back, vars->x * 50, vars->y * 50);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2 || keycode == 53)
		player_action(keycode, vars);
	else if (keycode == 53)
		exit(0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.player, vars->x * 50, vars->y * 50);
	return (0);
}

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

int	maprender(t_vars vars)
{
	int	y;
	int	x;

	x = 0;
	y = 0;
	while (vars.map[y])
	{
		while (vars.map[y][x])
		{
			mlx_put_image_to_window(vars.mlx, vars.win,
				select_txtr(vars.map[y][x], x, y, vars), 50 * x, 50 * y);
			if (vars.map[y][x] == 'H')
			{
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.textures.flask, 50 * x, 50 * y);
			}
			if (vars.map[y][x] == 'U')
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.textures.player, 50 * x, 50 * y);
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
	textures->paths[11] = "./textures/player.xpm";
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
	textures->player = mlx_xpm_file_to_image(vars.mlx, textures->paths[11],
			&img_wd, &img_hg);
}

void	game_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->mapsize.x * 50, vars->mapsize.y * 50, "so_long");
	paths_init(&vars->textures);
	textures_init(*vars, &vars->textures);
	maprender(*vars);
}

// void	handle_events(t_vars *vars)
// {

// }

int	main(int argc, char **argv)
{
	char	*buff;
	char	*validate;
	t_vars	vars;

	if (argc == 2)
	{
		buff = ft_mapread(argv[1]);
		vars.map = ft_mapsplit(buff);
		validate = ft_mapvalid(&vars, vars.map);
		if (validate)
			printf("%s\n", validate);
		game_init(&vars);
		printf("%d - y, %d - x", vars.y, vars.x);
		mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
