#include "fdf.h"

static void			*usage(int format)
{
	if (format == FDF_USAGE_FILE_FORMAT)
		ERROR("File format [n][m]:\n0 0 0 0\n0 1 2 0\n0 0 0 0");
	else if (format == FDF_USAGE_INPUT)
		ERROR("./fdf [path_file]");
	else if (format == FDF_USAGE_ERROR)
		ERROR("Can't open the file!");
	return (NULL);
}

static t_list		*get_file(char *path)
{
	int		fd;
	t_list	*list;
	t_list	*tmp;
	char	*line;

	line = NULL;
	list = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (NULL);
	while (get_next_line(fd, &line))
	{
		if (!line)
			return (NULL);
		tmp = ft_lstnew(line, ft_strlen(line) + 1);
		if (!list)
			list = tmp;
		else
			ft_lstadd_tail(list, tmp);
		ft_strdel(&line);
	}
	if ((fd = close(fd) < 0))
		PERROR("close");
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
	t_map	*map;
	int		size_map;
	int		size_line;
	char	**elem;

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
		return (usage(FDF_USAGE_INPUT));
	if ((file = get_file(*++av)) == NULL)
		return (usage(FDF_USAGE_ERROR));
	if ((ret = get_map(file)) == NULL)
		return (usage(FDF_USAGE_FILE_FORMAT));
	ft_printf("{g:1:%s}\n", "Valid file!");
	return (ret);
}