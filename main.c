/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:54:23 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/09 22:43:14 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode == 53)
		exit(0);
	return (0);
}

void	*select_txtr(int c, int x, int y, t_point s)
{}

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
			mlx_put_image_to_window(vars.mlx, vars.win, vars.textures.in_wall,
				50 * x, 50 * y);
			point.x++;
		}
		x = 0;
		y++;
	}
	mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
	mlx_loop(vars.mlx);
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
}

void	game_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, 1920, 1080, "so_long");
	paths_init(&vars->textures);
	textures_init(*vars, &vars->textures);
	maprender(*vars);
}

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
	}
	return (0);
}
