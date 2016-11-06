#include "fdf.h"

t_image		*ft_mlx_image_new(uint32_t height, uint32_t width)
{
	t_image		*n;
	void		*mlx;
	void		*img;

	if (!(mlx = ft_mlx_init_sglt()))
	{
		PERROR("mlx connexion failed, cant alloc image");
		return (NULL);
	}
	if ((n = ft_memalloc(sizeof(t_image))))
	{
		if ((img = mlx_new_image(mlx, width, height)))
		{
			n->img = img;
			n->addr = mlx_get_data_addr(img, &n->bpp, &n->size_line, &n->endian);
			n->height = height;
			n->width = width;
		}
		else
		{
			PERROR("cant create a image!");
			return (NULL);
		}
	}
	return (n);
}