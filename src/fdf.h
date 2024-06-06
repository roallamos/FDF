/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:36:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/06/06 15:42:56 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
//# include "mlx.h"
# include "../mlx_linux/mlx.h"
# include <errno.h>
# include <math.h>

# define WIDTH 1080
# define HEIGHT 1080

# define ERR_ARGS "Incorrect number of arguments"
# define ERR_OPEN "Could not open file"
# define ERR_MAP "Map format is incorrect"
# define ERR_MEM "Memory allocation error"
# define ERR_EMP "Empty map"

typedef struct mlx
{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct rot
{
	double	x;
	double	y;
	double	z;
}				t_rot;

typedef struct s_struct
{
	int			z;
	int			x;
	int			y;
	int			draw_x;
	int			draw_y;
	int			colour;
	double		red;
	double		green;
	double		blue;
}				t_struct;

typedef struct s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct s_map
{
	int			lines;
	int			columns;
	int			max_z;
	t_struct	**point;
	double		scale;
	double		z_rotation;
	double		x_rotation;
	double		y_rotation;
	int			y_offset;
	int			x_offset;
	int			x_mouse;
	int			y_mouse;
	int			mouse_key;
	t_mlx		mlx;
	t_data		img;
}				t_map;

typedef struct s_bresenham
{
	int		dx;
	int		dy;
	int		d;
	int		x;
	int		y;
	double	rp;
	double	red;
	double	green;
	double	blue;
}				t_bresenham;

int				ft_read_map(char *map, t_list **list);
int				ft_map_array(t_list *list, t_map *map);
void			ft_free_map(t_map map);
void			ft_window(t_map *map);
void			ft_print(t_map map);
void			ft_rotate(t_map *map);
int				ft_press_key(int keycode, t_map *map);
int				ft_x_close(t_map *map);
void			terminate(char *error);
void			ft_check_columns(int columns, char **spl);
int				ft_mouse_press(int keycode, int x, int y, void *map);
int				ft_mouse_release(int keycode, int x, int y, void *map);
int				ft_mouse_move(int x, int y, void *map);
int				ft_hold_key(int keycode, t_map *map);
int				ft_views(int keycode, t_map *map);
void			ft_bresenham_x(int i, int j, t_map map);
void			ft_bresenham_y(int i, int j, t_map map);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			set_image_black(t_map *map);
void			ft_move(int keycode, t_map *map);
void			ft_draw(t_map *map);
void			set_new_image(t_map *map);
void			ft_set_colour(t_map *map, char *spl, int l, int j);
void			ft_rotations(int i, int j, t_map *map);
void			draw_y_dx(t_map map, int i, int j, t_bresenham *bsh);
void			draw_y_dy(t_map map, int i, int j, t_bresenham *bsh);
void			draw_x_dx(t_map map, int i, int j, t_bresenham *bsh);
void			draw_x_dy(t_map map, int i, int j, t_bresenham *bsh);

#endif
