/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almeliky <almeliky@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:56:36 by almeliky          #+#    #+#             */
/*   Updated: 2023/04/18 18:38:19 by almeliky         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

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
	char	*paths[24];
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
	void	*flask_s[4];
	void	*pl_s[4];
	void	*youdie;
	void	*die_mini;
	void	*peak_s[4];
}	t_texture;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	char		**map;
	int			coins;
	int			x;
	int			y;
	int			die;
	int			actions;
	int			bonus;
	t_texture	textures;
	t_point		mapsize;
	t_point		player_pos;
}		t_vars;

char	*ft_chrvalid(char **map, int j, int i);
char	*ft_wallvalid(t_vars *vars, char **map, int j, int i);
char	*ft_rectangvalid(char **map);
char	*ft_mapvalid(t_vars *vars, char **map);
int		ft_strlen(char *str);
int		ft_open(char *file);
int		ft_filelen(char *file);
char	*ft_mapread(char *file, int buffsize, int fd);
int		ft_linecount(char *str);
char	*ft_getline(char *str);
char	**ft_mapsplit(char	*str, int size, int i);
char	*ft_mapchr(char **map, int c);
void	fill(t_vars *vars, char **map, t_point point);
char	*ft_pathvalid(t_vars *vars, char **map);
void	game_init(t_vars *vars);
void	textures_init(t_vars vars, t_texture *textures);
void	*img_init(t_vars vars, char *path);
void	paths_init(t_texture *textures);
int		maprender(t_vars vars, int x, int y);
void	*select_txtr(int c, int x, int y, t_vars s);
void	*select_wall(int x, int y, t_vars s);
int		handle_keypress(int keycode, t_vars *vars);
void	player_action(int keycode, t_vars *v);
void	move_to(int y, int x, t_vars *v);
void	portal_turn(t_vars *vars, char **map);
void	gameover(t_vars *vars, int res);
int		move_check(int y, int x, t_vars *v);
char	*ft_itoa(int n);
long	ft_abs(long int num);
int		ft_anim(t_vars *vars);
void	die_animate(t_vars *vars);
void	animation_render(t_vars *vars, int x, int y, int s);
void	map_clear(t_vars *vars, int i);
void	image_clear(t_vars *vars);
int		exit_clear(t_vars *vars);
void	*ft_calloc(size_t count, size_t size);
void	ft_putstr(char *s);
char	*type_check(const char *haystack, const char *needle);

#endif