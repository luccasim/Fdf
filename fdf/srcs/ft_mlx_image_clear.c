#include "ft_mlx.h"

void	ft_mlx_image_clear(t_image *t)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < t->width)
	{
		j = 0;
		while (j < t->height)
		{
			ft_mlx_image_pixel_put(t, i, j, MLX_DARK);
			j++;
		}
		i++;
	}
}