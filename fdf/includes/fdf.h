#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "ft_printf.h"
# include "ft_unix.h"
# include "list.h"
# include <mlx.h>
# include <inttypes.h>
# include <fcntl.h>
# include <stdlib.h>

typedef enum 	e_mlx_key
{
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	KEY_1 = 18,
	KEY_2 = 19,
	KEY_3 = 20,
	KEY_4 = 21,
	KEY_5 = 23,
	KEY_6 = 22,
	KEY_7 = 26,
	KEY_8 = 28,
	KEY_9 = 25,
	KEY_0 = 29,
	KEY_MOIN = 27,
	KEY_PLUS = 24,
	KEY_RET = 36,
	KEY_SPACE = 49,
	KEY_ESC = 53,
	KEY_NONE
}				t_mlx_key;

typedef struct	s_window
{
	void		*mlx;
	void		*win;
	uint32_t	height;
	uint32_t	width;
	char		*name;
}				t_window;

typedef struct	s_image
{
	void		*img;
	void		*addr;
	uint32_t	height;
	uint32_t	width;
	int			bpp;
	int			endian;
	int			size_line;
}				t_image;

typedef struct	s_vector
{
	int			x;
	int			y;
	int			dist;
}				t_vector;

typedef struct	s_map
{
	int			**map;
	size_t		map_size;
	size_t		line_size;
}				t_map;

//mlx bases :
void		*ft_mlx_init_sglt(void);
// window
t_window	*ft_mlx_window_new(char *name, uint32_t height, uint32_t width);
void		ft_mlx_window_pixel_put(t_window *w, int x, int y, int c);
void		ft_mlx_window_del(t_window *win);
void		ft_mlx_window_clear(t_window *win);
// pixel
// void		ft_mlx_pixel_image(t_image *img, t_pixel *pix);
// void		ft_mlx_pixel_window(t_window *win, t_pixel *pix);
// image
t_image		*ft_mlx_image_new(uint32_t height, uint32_t width);
void		ft_mlx_image_pixel_put(t_image *i, int x, int y, int c);
uint32_t	ft_mlx_image_pixel_get(t_image *i, int x, int y);
void		ft_mlx_image_del(t_image *img);
//fdf :
#endif