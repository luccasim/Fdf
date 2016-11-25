/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 09:53:37 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/25 09:53:40 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			fdf_key_hook(int keycode, void *param)
{
	t_mlx_key	key;
	t_fdf		*fdf;

	key = keycode;
	fdf = (t_fdf*)param;
	if (key == MLX_KEY_ESC)
		exit(0);
	if (key == MLX_KEY_D)
		set_degrade(fdf);
	if (key == MLX_KEY_C)
		set_color(fdf);
	if (key == MLX_KEY_PLUS || key == MLX_KEY_MOIN)
		zoom_map(keycode, fdf);
	if (key == MLX_KEY_R)
		reset_vector(fdf);
	if (IS_ARROW(key))
		change_vector(fdf, key);
	return (keycode);
}

static int			fdf_mouse_hook(int button, int x, int y, void *p)
{
	t_fdf *fdf;

	fdf = (t_fdf*)p;
	(void)x;
	(void)y;
	if (button == 5)
		zoom_map(button, fdf);
	else if (button == 4)
		zoom_map(button, fdf);
	return (1);
}

static int			fdf_expose_hook(void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	fdf_put_image(fdf);
	return (1);
}

void				fdf_hook(t_fdf *fdf)
{
	mlx_key_hook(fdf->win->win, fdf_key_hook, fdf);
	mlx_mouse_hook(fdf->win->win, fdf_mouse_hook, fdf);
	mlx_expose_hook(fdf->win->win, fdf_expose_hook, fdf);
	mlx_loop(fdf->win->mlx);
}
