#include "fdf.h"

void	check_map(t_map *map)
{
	double		*tab;
	size_t		i;
	size_t		j;
	double		**putin;

	j = 0;
	while (j < map->map_size)
	{
		putin = map->map;
		tab = putin[j];
		i = 0;
		while (i < map->line_size)
		{
			ft_printf("[{g:1:%2.f}]", tab[i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}