/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handle_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:12:54 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/18 18:17:36 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_check(int y, int x, t_vars *v)
{
	if (v->map[y][x] == '1')
		return (0);
	if (v->map[y][x] != 'J')
		return (1);
	if (v->coins > 0)
		return (0);
	return (1);
}

void	gameover(t_vars *vars, int res)
{
	if (res == 'w')
		exit_clear(vars);
	if (res == 'l')
		vars->die = 1;
	return ;
}

void	portal_turn(t_vars *vars, char **map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == 'J')
			{
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->textures.portal_on, x * 50, y * 50);
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return ;
}

void	move_to(int y, int x, t_vars *v)
{
	char	*count;

	v->actions++;
	mlx_put_image_to_window(v->mlx, v->win, v->textures.l_wall, 0, 0);
	count = ft_itoa(v->actions);
	mlx_string_put(v->mlx, v->win, 0, 0, 0xFF00FF, count);
	free(count);
	v->map[v->y][v->x] = '5';
	mlx_put_image_to_window(v->mlx, v->win,
		v->textures.back, v->x * 50, v->y * 50);
	v->y = y;
	v->x = x;
	if (v->map[y][x] == 'H')
	{
		v->coins--;
		if (v->coins == 0)
			portal_turn(v, v->map);
	}
	if (v->map[y][x] == 'J')
		gameover(v, 'w');
	if (v->map[y][x] == 'S')
		gameover(v, 'l');
	v->map[y][x] = 'U';
	mlx_put_image_to_window(v->mlx, v->win,
		v->textures.pl_s[0], v->x * 50, v->y * 50);
}

void	player_action(int keycode, t_vars *v)
{
	if (keycode == 13 && move_check(v->y - 1, v->x, v))
		move_to(v->y - 1, v->x, v);
	else if (keycode == 1 && move_check(v->y + 1, v->x, v))
		move_to(v->y + 1, v->x, v);
	else if (keycode == 0 && move_check(v->y, v->x - 1, v))
		move_to(v->y, v->x - 1, v);
	else if (keycode == 2 && move_check(v->y, v->x + 1, v))
		move_to(v->y, v->x + 1, v);
}
