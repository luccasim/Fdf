/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luccasim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:10:05 by luccasim          #+#    #+#             */
/*   Updated: 2016/11/25 13:10:08 by luccasim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_mlx.h"
# include "ft_tool.h"
# include "list.h"
# include "ft_unix.h"

# define FDF_W_HEIGTH			850
# define FDF_W_WIDTH			850

# define FDF_MOVE				25
# define FDF_DIST				15
# define FDF_DIST_MAX			50

# define FDF_EXIT				fdf_exit(FT_EXIT)

# define FDF_SET_LOW_COLOR		MLX_BLUE
# define FDF_SET_TOP_COLOR		MLX_BLOND

typedef enum	e_fdf_error
{
	FDF_ERROR = FT_ERROR,
	FDF_ERROR_FORMAT,
	FDF_ERROR_INPUT,
	FDF_ERROR_INIT,
	FDF_ERROR_WINDOW,
	FDF_ERROR_IMAGE
}				t_fdf_error;

typedef struct	s_point
{
	double		x;
	double		y;
	int			color;
}				t_point;

typedef struct	s_vector
{
	t_point		point;
	double		dist;
}				t_vector;

typedef struct	s_map
{
	double		**map;
	size_t		map_size;
	size_t		line_size;
	size_t		dist;
}				t_map;

typedef struct	s_fdf
{
	t_window	*win;
	t_image		*img;
	t_map		*map;
	t_vector	*vect;
	int			color;
}				t_fdf;

t_map	*parser(int ac, char **av);
void	fdf_draw(t_fdf *fdf);
void	fdf_hook(t_fdf *fdf);

void	set_color(t_fdf *fdf);
void	set_degrade(t_fdf *fdf);
int		color_level(t_fdf *fdf, int level);

void	zoom_map(int key, t_fdf *fdf);
void	reset_vector(t_fdf *fdf);
void	change_vector(t_fdf *fdf, int keycode);
void	fdf_put_image(t_fdf *fdf);

int		fdf_exit(int error);

#endif
