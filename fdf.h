/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:36:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/14 15:55:26 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"
# include <math.h>

# define WIDTH 1080
# define HEIGHT 720

# define ERR_ARGS "Incorrect number of arguments"
# define ERR_OPEN "Could not open file"

typedef struct mlx
{
	void *mlx;
	void *win;
} t_mlx;

typedef struct s_struct 
{
	int	z;
	int	x;
	int y;
	int colour;
	double	red;
	double	green;
	double	blue;
} t_struct;

typedef struct s_map
{
	int lines;
	int columns;
	int	max_z;
	t_struct **point;
	float SCALE;
	int x_offset;
	int y_offset;
	t_mlx mlx; 
} t_map;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

typedef struct s_utils
{
	t_map map;
} t_utils;

int	ft_read_map(char *map, t_list **list);
int	ft_map_array(t_list *list, t_map *map);
void	ft_free_map(t_map map);
void	ft_window(t_map map);
void	ft_print(t_map map);
void	terminate(char *error);

#endif
