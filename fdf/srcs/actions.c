/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:52:30 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/25 09:52:34 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fdf_put_image(t_fdf *fdf)
{
	t_vector	*v;
	void		*img;
	void		*win;
	void		*mlx;

	v = fdf->vect;
	mlx = fdf->win->mlx;
	win = fdf->win->win;
	img = fdf->img->img;
	ft_mlx_window_clear(fdf->win);
	mlx_put_image_to_window(mlx, win, img, v->point.x, v->point.y);
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
	size_t	zoom;

	zoom = fdf->map->dist;
	if (key == MLX_KEY_MOIN || key == 4)
	{
		zoom -= 5;
		if (zoom < 5)
			zoom = 5;
	}
	if (key == MLX_KEY_PLUS || key == 5)
	{
		zoom += 5;
		if (zoom > FDF_DIST_MAX)
			zoom = FDF_DIST_MAX;
	}
	if (zoom != fdf->map->dist)
	{
		fdf->map->dist = zoom;
		fdf_draw(fdf);
		fdf_put_image(fdf);
	}
}
