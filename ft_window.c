/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:45:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/06 12:55:15 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_rotate(t_map *map, int i, int j)
{
	double x;
	double y;
			
	x = (map->point[j][i].y - map->point[j][i].x) * SCALE * sin(M_PI/4);
	y = (map->point[j][i].x + map->point[j][i].y) * SCALE	* sin(M_PI/4);
	y = y * cos(M_PI/3);
	y = y - sin(M_PI/3) * SCALE * map->point[j][i].z;
	map->point[j][i].x = x;
	map->point[j][i].y = y;
}

void	ft_window(int lines, int columns, t_map map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int i;
	int j;

	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "perro");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (j < lines)
	{
		while (i < columns)
		{
			ft_rotate(&map, i, j);
			my_mlx_pixel_put(&img, map.point[j][i].x + 370, map.point[j][i].y + 100, 0xFFFFFF);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

