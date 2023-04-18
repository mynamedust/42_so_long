/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 21:54:23 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/18 18:37:23 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keypress(int keycode, t_vars *vars)
{
	if (vars->die == 1)
		exit_clear(vars);
	if (keycode == 13 || keycode == 1 || keycode == 0 || keycode == 2)
		player_action(keycode, vars);
	else if (keycode == 53 || keycode == 17)
		exit_clear(vars);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->textures.pl_s[0], vars->x * 50, vars->y * 50);
	return (0);
}

char	*ft_mapvalid(t_vars *vars, char	**map)
{
	char	*message;

	message = ft_chrvalid(map, 0, 0);
	if (message != NULL)
		return (message);
	message = ft_wallvalid(vars, map, 0, 0);
	if (message != NULL)
		return (message);
	message = ft_rectangvalid(map);
	if (message != NULL)
		return (message);
	message = ft_pathvalid(vars, map);
	if (message != NULL)
		return (message);
	return (NULL);
}

int	main(int argc, char **argv)
{
	char	*buff;
	char	*validate;
	t_vars	vars;

	if (argc == 2)
	{
		if (!(type_check(argv[1], ".ber")))
			exit(0);
		buff = ft_mapread(argv[1], 0, 0);
		vars.map = ft_mapsplit(buff, 0, 0);
		free(buff);
		validate = ft_mapvalid(&vars, vars.map);
		if (validate)
		{
			ft_putstr(validate);
			map_clear(&vars, 0);
			exit(0);
		}
		game_init(&vars);
		mlx_hook(vars.win, 2, 1L << 0, handle_keypress, &vars);
		mlx_hook(vars.win, 17, 0, exit_clear, &vars);
		if (vars.bonus)
			mlx_loop_hook(vars.mlx, ft_anim, &vars);
		mlx_loop(vars.mlx);
	}
	return (0);
}
