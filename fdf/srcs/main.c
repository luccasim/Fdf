#include "fdf.h"
#include "ft_unix.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "list.h"
#include "get_next_line.h"

static t_image			*fdf_image(t_map *map)
{
	t_image *image;
	size_t	image_width;
	size_t	image_height;

	image = NULL;
	image_width = FDF_DIST_MAX * (map->line_size + 1);
	image_height = FDF_DIST_MAX * (map->map_size + 1);
	image = ft_mlx_image_new(image_height, image_width);
	return (image);
}

static int				fdf_key_hook(int keycode, void *param)
{
	t_mlx_key	key;
	t_fdf		*fdf;

	key = keycode;
	fdf = (t_fdf*)param;
	if (key == MLX_KEY_ESC)
		exit(0);
	if (key == MLX_KEY_D)
		ft_mlx_window_clear(fdf->win);
	if (key == MLX_KEY_C)
		set_color(fdf);
	if ( key == MLX_KEY_PLUS || key == MLX_KEY_MOIN)
		zoom_map(keycode, fdf);
	if (key == MLX_KEY_R)
		reset_vector(fdf);
	if (IS_ARROW(key))
		change_vector(fdf, key);
	return (keycode);
}

static int				fdf_expose_hook(void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	fdf_put_image(fdf);
	return (1);
}

static t_fdf			*fdf_init(t_window *win, t_map *map)
{
	t_fdf		*fdf;
	t_vector	*vector;

	fdf = ft_memalloc(sizeof(t_fdf));
	vector = ft_memalloc(sizeof(t_vector));
	fdf->win = win;
	fdf->map = map;
	vector->point.x = 0;
	vector->point.y = 0;
	vector->dist = FDF_DIST_MAX;
	fdf->img = fdf_image(map);
	fdf->vect = vector;
	fdf->color = 0;
	PUTSTR("ecriture dans l 'image!");
	fdf_draw(fdf);
	PUTSTR("affichage de l'image");
	fdf_put_image(fdf);
	return (fdf);
}

int						main(int ac, char **av)
{
	t_window	*win;
	t_map		*map;
	t_fdf		*fdf;

	if ((map = parser(ac, av)) == NULL)
		return (0);
	if ((win = ft_mlx_window_new("FDF", FDF_W_WIDTH, FDF_W_HEIGTH)) == NULL)
		return (0);
	fdf = fdf_init(win, map);
	mlx_key_hook(win->win, fdf_key_hook, fdf);
	mlx_expose_hook(win->win, fdf_expose_hook, fdf);
	mlx_loop(win->mlx);
	return (0);
}