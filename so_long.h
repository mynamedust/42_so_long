/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:37:34 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/09 19:37:34 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_chars
{
	int	e;
	int	c;
	int	p;
}	t_chars;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_texture
{
	char	*paths[12];
	void	*in_wall;
	void	*t_wall;
	void	*l_wall;
	void	*lb_wall;
	void	*r_wall;
	void	*rb_wall;
	void	*b_wall;
	void	*back;
	void	*portal_on;
	void	*portal_off;
	void	*flask;
	void	*player;
}	t_texture;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	int			coins;
	int			x;
	int			y;
	t_texture	textures;
	t_point		mapsize;
	t_point		player_pos;
}		t_vars;

char	*ft_chrvalid(char **map);
char	*ft_wallvalid(t_vars *vars, char **map);
char	*ft_rectangvalid(char **map);
char	*ft_mapvalid(t_vars *vars, char **map);
int		ft_strlen(char *str);
int		ft_open(char *file);
int		ft_filelen(char *file);
char	*ft_mapread(char *file);
int		ft_linecount(char *str);
char	*ft_getline(char *str);
char	**ft_mapsplit(char	*str);
char	*ft_mapchr(char **map, int c);
void	fill(t_vars *vars, char **map, t_point point);
char	*ft_pathvalid(t_vars *vars, char **map);

#endif