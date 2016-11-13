#include "fdf.h"

static void		bresenham_neg(t_fdf *fdf, t_point inc, t_point d, t_point a)
{
	int		i;
	int		cumul;
	int		color;

	i = 1;
	cumul = d.x / 2;
	color = color_level(fdf, a.color);
	while (i <= d.x)
	{
		a.x = a.x + inc.x;
		cumul = cumul + d.y;
		if (cumul >= d.x)
		{
			cumul = cumul - d.x;
			a.y = a.y + inc.y;
			color = color_level(fdf, ++a.color);
		}
		ft_mlx_image_pixel_put(fdf->img, a.x, a.y, color);
		i++;
	}
}

static void		bresenham_pos(t_fdf *fdf, t_point inc, t_point d, t_point a)
{
	int		i;
	int		cumul;
	int		color;

	i = 1;
	cumul = d.y / 2;
	color = color_level(fdf, a.color);
	while (i <= d.y)
	{
		a.y = a.y + inc.y;
		cumul = cumul + d.x;
		if (cumul >= d.y)
		{
			cumul = cumul - d.y;
			a.x = a.x + inc.x;
			color = color_level(fdf, ++a.color);
		}
		ft_mlx_image_pixel_put(fdf->img, a.x, a.y, color);
		i++;
	}
}

static void		draw_line(t_point i, t_point f, t_fdf *fdf)
{
	t_point		a;
	t_point		d;
	t_point		inc;

	a.x = i.x;
	a.y = i.y;
	a.color = i.color;
	d.x = f.x - i.x;
	d.y = f.y - i.y;
	inc.x = (d.x > 0) ? 1 : -1;
	inc.y = (d.y > 0) ? 1 : -1;
	d.x = ABS(d.x);
	d.y = ABS(d.y);
	if (d.x > d.y)
  		bresenham_neg(fdf, inc, d, a);
    else
    	bresenham_pos(fdf, inc, d, a);
}

static void		calculpoint(int i, int j, t_fdf *fdf, t_point *a)
{
	size_t		map_dist;
	double		**map;
	int			line_size;
	int			map_size;

	map_dist = fdf->map->dist;
	map = fdf->map->map;
	line_size = fdf->map->line_size;
	map_size = fdf->map->map_size;
	if (i < map_size && j < line_size)
	{
		a->x = map_dist + (j * map_dist);
		a->y = map_dist + (i * map_dist);
		a->x -= map[i][j];
		a->y -= map[i][j];
		a->color = map[i][j];
	}
}

void			fdf_draw(t_fdf *fdf)
{
	t_point 	a;
	t_point 	b;
	size_t		i;
	size_t		j;
	t_map		*map;

	ft_mlx_image_clear(fdf->img);
	i = 0;
	map = fdf->map;
	while (i < map->map_size)
	{
		j = 0;
		while (j < map->line_size)
		{
			calculpoint(i, j, fdf, &a);
			calculpoint(i, j + 1, fdf, &b);
			if (j + 1 < map->line_size)
				draw_line(a, b, fdf);
			calculpoint(i + 1, j, fdf, &b);
			if (i + 1 < map->map_size)
				draw_line(a, b, fdf);
			j++;
		}
		i++;
	}
}