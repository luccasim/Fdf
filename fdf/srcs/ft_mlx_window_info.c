#include "ft_mlx.h"
#include "ft_printf.h"

void	ft_mlx_window_info(t_window *w)
{
	ft_printf("Window(%p)\t:\n", w);
	ft_printf("mlx\t\t = %p\n", w->mlx);
	ft_printf("win\t\t = %p\n", w->win);
	ft_printf("name\t\t = %s\n", w->name);
	ft_printf("height\t\t = %u\n", w->height);
	ft_printf("width\t\t = %u\n", w->width);
}