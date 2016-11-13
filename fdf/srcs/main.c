#include "fdf.h"

static t_image		*fdf_image(t_map *map)
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

static t_fdf		*fdf_init(t_window *win, t_map *map, t_image *image)
{
	t_fdf		*fdf;
	t_vector	*vector;

	if ((fdf = ft_memalloc(sizeof(t_fdf))) == NULL)
		return (NULL);
	if ((vector = ft_memalloc(sizeof(t_vector))) == NULL)
		return (NULL);
	vector->point.x = 0;
	vector->point.y = 0;
	vector->dist = FDF_DIST_MAX;
	fdf->win = win;
	fdf->map = map;
	fdf->img = image;
	fdf->vect = vector;
	fdf->color = 0;
	PUTSTR("Ecriture dans l 'image!");
	TIME_START;
	fdf_draw(fdf);
	TIME_END;
	PUTSTR("Affichage de l'image");
	fdf_put_image(fdf);
	return (fdf);
}

int					main(int ac, char **av)
{
	t_window	*win;
	t_map		*map;
	t_image		*image;
	t_fdf		*fdf;

	if ((map = parser(ac, av)) == NULL)
		return (FDF_EXIT);
	if ((win = ft_mlx_window_new("FDF", FDF_W_WIDTH, FDF_W_HEIGTH)) == NULL)
		return (FDF_EXIT);
	if ((image = fdf_image(map)) == NULL)
		return (FDF_EXIT);
	if ((fdf = fdf_init(win, map, image)) == NULL)
		return (FDF_EXIT);
	fdf_hook(fdf);
	return (FDF_EXIT);
}