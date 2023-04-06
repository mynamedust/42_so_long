#ifndef SO_L0NG_H
# define SO_L0NG_H

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<mlx.h>

typedef struct s_chars
{
	int	e;
	int	c;
	int	p;
}	t_chars;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

char	*ft_chrvalid(char **map);
char	*ft_wallvalid(char **map);
char	*ft_rectangvalid(char **map);
char	*ft_mapvalid(char	**map);
int	ft_strlen(char *str);
int	ft_open(char *file);
int	ft_filelen(char *file);
char	*ft_mapread(char *file);
int	ft_linecount(char *str);
char	*ft_getline(char *str);
char	**ft_mapsplit(char	*str);
char	*ft_mapchr(char **map, int c);
void	fill(char **map, t_point point);
char	*ft_pathvalid(char **map);

#endif