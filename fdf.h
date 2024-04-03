/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:36:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/15 14:38:25 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
//# include "./mlx/mlx.h"
# include "./mlx_linux/mlx.h"
# include <math.h>
# include <errno.h>

# define WIDTH 1080
# define HEIGHT 1080

# define ERR_ARGS "Incorrect number of arguments"
# define ERR_OPEN "Could not open file"
# define ERR_MAP "Map format is incorrect"

typedef struct mlx
{
	void *mlx;
	void *win;
} t_mlx;

typedef struct s_struct 
{
	int	z;
	int	x;
	int	y;
	int	draw_x;
	int	draw_y;
	int colour;
	double	red;
	double	green;
	double	blue;
} t_struct;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_map
{
	int lines;
	int columns;
	int	max_z;
	t_struct **point;
	double SCALE;
	int x_offset;
	int y_offset;
	t_mlx mlx;
	t_data img;	
} t_map;

int	ft_read_map(char *map, t_list **list);
int	ft_map_array(t_list *list, t_map *map);
void	ft_free_map(t_map map);
void	ft_window(t_map *map);
void	ft_print(t_map map);
void	ft_rotate(t_map *map);
int		ft_close(int keycode, t_map *map);
int		ft_x_close(t_map *map);
void	terminate(char *error);
void	ft_check_columns(int columns, char **spl);
int		ft_mouse(int keycode, int x, int y, void *map);
int		ft_hold_key(int keycode, t_map *map);
void	ft_bresenham_x(int i, int j, t_map map, t_data *img);
void	ft_bresenham_y(int i, int j, t_map map, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	set_image_black(t_map *map);
void	ft_move_up(t_map *map);
void	ft_draw(t_map *map);
void	ft_move_down(t_map *map);
void	ft_move_up(t_map *map);
void	ft_move_left(t_map *map);
void	ft_move_right(t_map *map);
#endif
