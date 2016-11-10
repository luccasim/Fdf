#include "ft_mlx.h"
#include <stdlib.h>

void	ft_mlx_image_del(t_image *img)
{
	void	*mlx;

	mlx = ft_mlx_init_sglt();
	if (img && mlx)
	{
		mlx_destroy_image(mlx, img);
		free(img);
	}
}