#include "fdf.h"

void			set_color(t_fdf *fdf)
{
	fdf->color = (fdf->color == 0) ? 1 : 0;
	fdf_draw(fdf);
	fdf_put_image(fdf);
}

void			set_degrade(t_fdf *fdf)
{
	fdf->color = (fdf->color) ? 2 : 0;
	fdf_draw(fdf);
	fdf_put_image(fdf);
}

static int		top_color(int level)
{
	int		i;
	int		color;

	i = 0;
	color = MLX_YELLOW;
	while (i < level)
	{
		color -= 0x00010400;
		i++;
	}
	return (color);
}

static int		low_color(int level)
{
	int		i;
	int		color;

	color = 0x00000001;
	i = 0;
	while (i > level)
	{
		color += 0x00000042;
		i--;
	}
	return (color);
}

int				color_level(t_fdf *fdf, int level)
{
	int		color;

	color = MLX_WHITE;
	if (fdf->color == 0)
		return (color);
	if (fdf->color == 1)
	{
		if (level >= 1)
			color = MLX_GREEN;
		if (level >= 4)
			color = MLX_YELLOW;
		if (level >= 7)
			color = MLX_ORANGE;
		if (level >= 10)
			color = MLX_BROWN;
		if (level > 12)
			color = MLX_RED;
	}
	else
	{
		if (level < 0)
			color = low_color(level);
		else
			color = top_color(level);
	}
	return (color);
}