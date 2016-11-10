#include "ft_mlx.h"
#include <stdlib.h>
#include <unistd.h>

void		ft_mlx_window_del(t_window *win)
{
	if (win)
	{
		if (win->win)
			mlx_destroy_window(win->mlx, win->win);
		free(win);
		_exit(1);
	}
}