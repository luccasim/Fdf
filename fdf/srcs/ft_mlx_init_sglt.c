#include "fdf.h"

void	*ft_mlx_init_sglt(void)
{
	static void		*mlx = NULL;

	if (!mlx)
	{
		if (!(mlx = mlx_init()))
			return (mlx);
	}
	return (mlx);
}