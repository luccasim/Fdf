#include "fdf.h"

static int		top_color(int level)
{
	int		i;
	int		color;

	i = 0;
	// color = 0x00F28F39;
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

void			set_degrade(t_fdf *fdf)
{
	fdf->color = (fdf->color == 0) ? 0 : 2;
	fdf_draw(fdf);
	fdf_put_image(fdf);
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