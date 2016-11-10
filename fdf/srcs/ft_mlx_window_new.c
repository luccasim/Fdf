#include "ft_mlx.h"
#include "libft.h"
#include "ft_unix.h"

t_window	*ft_mlx_window_new(char *name, uint32_t height, uint32_t width)
{
	t_window	*new;
	void		*mlx;

	mlx = ft_mlx_init_sglt();
	new = 0;
	if (mlx)
	{
		new = ft_memalloc(sizeof(t_window));
		if (new)
		{
			new->win = mlx_new_window(mlx, width, height, name);
			new->height = height;
			new->width = width;
			new->name = name;
			new->mlx = mlx;
		}
		else
			ERROR("fail alloction for window ptr");
	}
	return (new);
}