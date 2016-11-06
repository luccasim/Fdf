#include "fdf.h"

void	ft_mlx_window_clear(t_window *win)
{
	if (win)
	{
		mlx_clear_window(win->mlx, win->win);
	}
}