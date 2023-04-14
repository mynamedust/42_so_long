/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:54:23 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/14 17:51:05 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		player_action(keycode, vars);
	else if (keycode == 53)
		exit(0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.player1, vars->x * 50, vars->y * 50);
	return (0);
}

int	player_anim(t_vars *vars)
{
	static int	i;
	
	if (i % 2000 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.back , vars->x * 50,vars->y * 50);
	if (i % 8000 == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.player4 , vars->x * 50,vars->y * 50);
		i = 0;
	}
	else if (i % 6000 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.player3, vars->x * 50,vars->y * 50);
	else if (i % 4000 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.player2, vars->x * 50,vars->y * 50);
	else if (i % 2000 == 0)
		mlx_put_image_to_window(vars->mlx, vars->win, vars->textures.player1, vars->x * 50,vars->y * 50);
	i++;
	// printf("%d - num\n", i);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*buff;
	char	*validate;
	t_vars	vars;

	// int i = 0;
	if (argc == 2)
	{
		buff = ft_mapread(argv[1]);
		vars.map = ft_mapsplit(buff);
		// while (vars.map[i])
		// {
		// 	printf("%s\n", vars.map[i]);
		// 	i++;
		// }
		validate = ft_mapvalid(&vars, vars.map);
		if (validate)
		{
			printf("%s\n", validate);
			exit(0);
		}
		game_init(&vars);
		mlx_string_put(vars.mlx, vars.win, 0, 0, 0xFF00FF, "5");
		mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
		mlx_loop_hook(vars.mlx, player_anim, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
