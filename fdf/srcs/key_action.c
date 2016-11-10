#include "fdf.h"

void		fdf_put_image(t_fdf *fdf)
{
	t_vector *v;

	v = fdf->vect;
	ft_mlx_window_clear(fdf->win);
	mlx_put_image_to_window(fdf->win->mlx, fdf->win->win, fdf->img->img, v->point.x, v->point.y);
}

void		change_vector(t_fdf *fdf, int keycode)
{
	if (keycode == MLX_KEY_TOP)
		fdf->vect->point.y -= FDF_MOVE;
	else if (keycode == MLX_KEY_BOT)
		fdf->vect->point.y += FDF_MOVE;
	else if (keycode == MLX_KEY_LEFT)
		fdf->vect->point.x -= FDF_MOVE;
	else if (keycode == MLX_KEY_RIGHT)
		fdf->vect->point.x += FDF_MOVE;
	fdf_put_image(fdf);
}

void		reset_vector(t_fdf *fdf)
{
	fdf->vect->point.x = 0;
	fdf->vect->point.y = 0;
	fdf->color = 0;
	fdf->map->dist = FDF_DIST;
	fdf_draw(fdf);
	fdf_put_image(fdf);
}

void		zoom_map(int key, t_fdf *fdf)
{
	t_map 	*map;
	size_t	zoom;

	map = fdf->map;
	zoom = map->dist;
	if (key == MLX_KEY_MOIN)
	{
		zoom -= 5;
		if (zoom <= 5)
			zoom = 5;
	}
	if (key == MLX_KEY_PLUS)
	{
		zoom += 5;
		if (zoom > FDF_DIST_MAX)
			zoom = FDF_DIST_MAX;
	}
	fdf->map->dist = zoom;
	fdf_draw(fdf);
	fdf_put_image(fdf);
}

void		set_color(t_fdf *fdf)
{
	fdf->color = (fdf->color == 0) ? 1 : 0;
	fdf_draw(fdf);
	fdf_put_image(fdf);
}