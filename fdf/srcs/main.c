#include "fdf.h"
#include "ft_unix.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "list.h"
#include "get_next_line.h"

static int		my_key_hook(int keycode, void *param)
{
	t_mlx_key	key;
	(void)param;
	key = keycode;
	if (key == KEY_A)
		ft_printf("C'est la key A\n");
	if (key == KEY_B)
		PUTNBR(keycode);
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_NONE)
		ERROR("unknow key set");
	return (keycode);
}

t_list	*parse_file(char *path)
{
	int		fd;
	t_list	*list;
	t_list	*tmp;
	char	*line;

	line = NULL;
	list = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
	{
		PERROR("open");
		return (list);
	}
	while (get_next_line(fd, &line))
	{
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

int		usage(void)
{
	return (ERROR("usage : ./fdf [map1]"));
}

// debug

void	read_list(t_list *elem)
{
	char	*str;

	str = (char *)elem->content;
	PUTSTR(str);
}

// mettre dans ft_list

size_t		list_size(t_list *list)
{
	t_list	*tmp;
	size_t	k;

	tmp = list;
	k = 0;
	while (tmp)
	{
		k++;
		tmp = tmp->next;
	}
	return (k);
}

// mettre dans ft_tool

size_t		split_size(char **split)
{
	size_t	size;

	size = 0;
	while (*split)
	{
		size++;
		split++;
	}
	return (size);
}

// debug

void	check_map(t_map *map)
{
	int			*tab;
	size_t		i;
	size_t		j;
	int			**putin;

	j = 0;
	while (j < map->map_size)
	{
		putin = map->map;
		tab = putin[j];
		i = 0;
		while (i < map->line_size)
		{
			ft_printf("[%i]", tab[i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}

int		fill_map(int **map, size_t size, char **content)
{
	int		i;
	int		k;
	int		*tab;
	int		elem;

	k = split_size(content);
	tab = ft_memalloc(sizeof(int) * k + 1);
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

// mettre dans ft_tool

void		ft_strdelsplit(char **split)
{
	char	**tmp;

	tmp = split;
	while (*split)
	{
		free(*split);
		split++;
	}
	free(tmp);
}

t_map		*get_map(t_list *list)
{
	t_map	*map;
	int		size_map;
	int		size_line;
	char	**elem;

	map = ft_memalloc(sizeof(t_map));
	size_map = list_size(list);
	map->map = ft_memalloc(sizeof(int*) * size_map + 1);
	map->map_size = size_map;
	map->line_size = 0;
	map->map[size_map] = NULL;
	size_map = 0;
	while (list)
	{
		elem = ft_strsplit((char *)list->content, ' ');
		size_line = fill_map(map->map, size_map++, elem);
		if (map->line_size == 0)
			map->line_size = size_line;
		ft_strdelsplit(elem);
		list = list->next;
		if (size_line != map->line_size)
			return (NULL);
	}
	return (map);
}

int		main(int ac, char **av)
{
	t_window	*win;
	t_list		*list;
	t_map		*map;

	if (ac == 1 || ac >= 3)
		return (usage());
	list = parse_file(*++av);
	if (list)
		ft_lstiter(list, read_list);
	else
		return (ERROR("parsing map failed"));
	if (!(map = get_map(list)))
		return (ERROR("parsing map failed!"));
	win = ft_mlx_window_new("Bonjour", 500, 500);
	if (win)
	{
		PUTSTR("window create!");
		mlx_key_hook(win->win, my_key_hook, win);
		mlx_loop(win->mlx);
	}
	return (0);
}