/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:10:29 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/18 15:10:52 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*select_txtr(int c, int x, int y, t_vars s)
{
	if (c == '5' || c == 'U' || c == 'H' || c == 'S')
		return (s.textures.back);
	if (c == 'J' && s.coins > 0)
		return (s.textures.portal_off);
	if (c == 'J' && s.coins == 0)
		return (s.textures.portal_on);
	if (c == '1')
		return (select_wall(x, y, s));
	return (s.textures.in_wall);
}

void	*select_wall(int x, int y, t_vars s)
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
	return (s.textures.in_wall);
}
