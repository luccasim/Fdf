#include "ft_mlx.h"
#include "ft_unix.h"

void	*ft_mlx_init_sglt(void)
{
	static void		*mlx = NULL;

	if (!mlx)
	{
		if (!(mlx = mlx_init()))
		{
			ERROR("mlx_init() connexion fail");
			return (mlx);
		}
	}
	return (mlx);
}