/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:55:29 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/18 18:20:15 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	maprender(t_vars vars, int x, int y)
{
	while (vars.map[y])
	{
		while (vars.map[y][x])
		{
			vars.x = x;
			vars.y = y;
			mlx_put_image_to_window(vars.mlx, vars.win,
				select_txtr(vars.map[y][x], x, y, vars), 50 * x, 50 * y);
			if (vars.map[y][x] == 'H')
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.textures.flask_s[0], 50 * x, 50 * y);
			if (vars.map[y][x] == 'U')
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.textures.pl_s[0], 50 * x, 50 * y);
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
	textures->paths[10] = "./textures/flask1.xpm";
	textures->paths[11] = "./textures/flask2.xpm";
	textures->paths[12] = "./textures/flask3.xpm";
	textures->paths[13] = "./textures/flask4.xpm";
	textures->paths[14] = "./textures/player1.xpm";
	textures->paths[15] = "./textures/player2.xpm";
	textures->paths[16] = "./textures/player3.xpm";
	textures->paths[17] = "./textures/player4.xpm";
	textures->paths[18] = "./textures/youdie.xpm";
	textures->paths[19] = "./textures/die_mini.xpm";
	textures->paths[20] = "./textures/peak1.xpm";
	textures->paths[21] = "./textures/peak2.xpm";
	textures->paths[22] = "./textures/peak3.xpm";
	textures->paths[23] = "./textures/peak4.xpm";
}

void	*img_init(t_vars vars, char *path)
{
	void	*img;
	int		img_wd;
	int		img_hg;

	img = mlx_xpm_file_to_image(vars.mlx, path, &img_wd, &img_hg);
	if (!img)
	{
		ft_putstr("Image initialization error.");
		exit_clear(&vars);
	}
	return (img);
}

void	textures_init(t_vars vars, t_texture *textures)
{
	textures->in_wall = img_init(vars, textures->paths[0]);
	textures->t_wall = img_init(vars, textures->paths[1]);
	textures->l_wall = img_init(vars, textures->paths[2]);
	textures->lb_wall = img_init(vars, textures->paths[3]);
	textures->r_wall = img_init(vars, textures->paths[4]);
	textures->rb_wall = img_init(vars, textures->paths[5]);
	textures->b_wall = img_init(vars, textures->paths[6]);
	textures->back = img_init(vars, textures->paths[7]);
	textures->portal_on = img_init(vars, textures->paths[8]);
	textures->portal_off = img_init(vars, textures->paths[9]);
	textures->flask_s[0] = img_init(vars, textures->paths[10]);
	textures->flask_s[1] = img_init(vars, textures->paths[11]);
	textures->flask_s[2] = img_init(vars, textures->paths[12]);
	textures->flask_s[3] = img_init(vars, textures->paths[13]);
	textures->pl_s[0] = img_init(vars, textures->paths[14]);
	textures->pl_s[1] = img_init(vars, textures->paths[15]);
	textures->pl_s[2] = img_init(vars, textures->paths[16]);
	textures->pl_s[3] = img_init(vars, textures->paths[17]);
	textures->youdie = img_init(vars, textures->paths[18]);
	textures->die_mini = img_init(vars, textures->paths[19]);
	textures->peak_s[0] = img_init(vars, textures->paths[20]);
	textures->peak_s[1] = img_init(vars, textures->paths[21]);
	textures->peak_s[2] = img_init(vars, textures->paths[22]);
	textures->peak_s[3] = img_init(vars, textures->paths[23]);
}

void	game_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->mapsize.x * 50,
			vars->mapsize.y * 50, "./so_long");
	vars->die = 0;
	vars->actions = 0;
	paths_init(&vars->textures);
	textures_init(*vars, &vars->textures);
	maprender(*vars, 0, 0);
}
