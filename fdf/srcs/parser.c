#include "fdf.h"

static t_list		*get_file(char *path)
{
	int		fd;
	t_list	*list;
	t_list	*tmp;
	char	*line;

	line = NULL;
	list = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (THROW(FT_ERROR_OPEN));
	while (get_next_line(fd, &line))
	{
		if (!line)
			return (THROW(FT_ERROR_GNL));
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		if (!list)
			list = tmp;
		else
			ft_lstadd_tail(list, tmp);
		ft_strdel(&line);
	}
	if ((fd = close(fd) < 0))
		THROW(FT_ERROR_CLOSE);
	return (list);
}

static int			fill_map(double **map, size_t size, char **content)
{
	int		i;
	int		k;
	double	*tab;
	int		elem;

	k = ft_strstrlen(content);
	tab = ft_memalloc(sizeof(double) * k + 1);
	i = 0;
	while (i < k)
	{
		elem = ft_atoi(content[i]);
		tab[i] = elem;
		i++;
	}
	map[size] = tab;
	return (i);
}

static t_map		*get_map(t_list *file)
{
	t_map		*map;
	size_t		size_map;
	size_t		size_line;
	char		**elem;

	map = ft_memalloc(sizeof(t_map));
	size_map = ft_lstlen(file);
	map->map = ft_memalloc(sizeof(double*) * size_map + 1);
	map->map_size = size_map;
	map->line_size = 0;
	map->map[size_map] = NULL;
	map->dist = FDF_DIST;
	size_map = 0;
	while (file)
	{
		elem = ft_strsplit((char *)file->content, ' ');
		size_line = fill_map(map->map, size_map++, elem);
		if (map->line_size == 0)
			map->line_size = size_line;
		ft_strdelsplit(elem);
		file = file->next;
		if (size_line != map->line_size)
			return (NULL);
	}
	return (map);
}

t_map				*parser(int ac, char **av)
{
	t_map	*ret;
	t_list	*file;

	ret = NULL;
	if (ac == 1 || ac >= 3)
		return (THROW(FDF_ERROR_INPUT));
	if ((file = get_file(*++av)) == NULL)
		return (NULL);
	if ((ret = get_map(file)) == NULL)
		return (THROW(FDF_ERROR_FORMAT));
	ft_printf("{g:1:%s}\n", "Valid file!");
	return (ret);
}