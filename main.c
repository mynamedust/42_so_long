/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:54:23 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/17 15:07:38 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		player_action(keycode, vars);
	else if (keycode == 53)
		exit_clear(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.pl_s[0], vars->x * 50, vars->y * 50);
	return (0);
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
		free(buff);
		validate = ft_mapvalid(&vars, vars.map);
		if (validate)
		{
			printf("%s\n", validate);
			exit_clear(0);
		}
		game_init(&vars);
		mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
		mlx_loop_hook(vars.mlx, ft_anim, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
