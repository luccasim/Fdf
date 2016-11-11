#ifndef FDF_H
# define FDF_H

# include "ft_mlx.h"
# include "ft_tool.h"
# include "list.h"

# define FDF_W_HEIGTH			850
# define FDF_W_WIDTH			850
# define FDF_MOVE				50
# define FDF_DIST				15
# define FDF_DIST_MAX			50
# define FDF_USAGE_INPUT		0
# define FDF_USAGE_FILE_FORMAT	2
# define FDF_USAGE_ERROR		4

typedef enum	e_fdf_color
{
	FDF_DARK = 0,
	FDF_BLUE,
	FDF_GREEB,
	FDF_RED,
	FDF_WHITE
}				t_fdf_color;

typedef struct	s_point
{
	double		x;
	double		y;
	int			color;
}				t_point;

typedef struct	s_vector
{
	t_point		point;
	double		dist;
}				t_vector;

typedef struct	s_map
{
	double		**map;
	size_t		map_size;
	size_t		line_size;
	size_t		dist;
}				t_map;

typedef struct	s_fdf
{
	t_window	*win;
	t_image		*img;
	t_map		*map;
	t_vector	*vect;
	int			color;
}				t_fdf;

t_map	*parser(int ac, char **av);
void	mlx_event(t_fdf *fdf);
void	fdf_draw(t_fdf *fdf);

/*
** Mlx key hook function
*/

void		set_color(t_fdf *fdf);
void		set_degrade(t_fdf *fdf);
int			color_level(t_fdf *fdf, int level);
void		zoom_map(int key, t_fdf *fdf);
void		reset_vector(t_fdf *fdf);
void		change_vector(t_fdf *fdf, int keycode);
void		fdf_put_image(t_fdf *fdf);

#endif