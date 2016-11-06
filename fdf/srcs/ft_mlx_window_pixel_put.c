#include "fdf.h"

void	ft_mlx_window_pixel_put(t_window *win, int x, int y, int c)
{
	uint32_t	color;
	uint32_t	a;
	uint32_t	b;

	if (x < 0 || y < 0)
		return ;
	a = (uint32_t)x;
	b = (uint32_t)y;
	if (a < win->width && b < win->height)
	{
		color = mlx_get_color_value(win->mlx, c);
		mlx_pixel_put(win->mlx, win->win, a, b, color);
	}
}