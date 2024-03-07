/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:45:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/07 12:46:42 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >=  HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_bresenham(int i, int j, t_map map, t_data *img)
{
	int dx;
	int dy;
	int D;
	int x;
	int y;

	x = 0;
	y = 0;
	if (i + 1 < map.columns)
	{
		dx = map.point[j][i + 1].x - map.point[j][i].x;
		dy = map.point[j][i + 1].y - map.point[j][i].y;
		D = 2 * dy - dx;
		if (dx > dy)
		{
			while (map.point[j][i + 1].x != map.point[j][i].x + x || map.point[j][i + 1].y != map.point[j][i].y + y)
			{
				if (D <= 0)
				{
					if (map.point[j][i].y + y != map.point[j][i + 1].y)
						y += 1;
					D = D + 2 * dy;
				}
				else
					D = D + 2 * (dy - dx);
				if (map.point[j][i].x + x != map.point[j][i + 1].x)
					x += 1;
				my_mlx_pixel_put(img, map.point[j][i].x + x, map.point[j][i].y + y, 0xFFFFFF);
			}
		}
		else if (dx < dy)
		{
			while (map.point[j][i + 1].x != map.point[j][i].x + x || map.point[j][i + 1].y != map.point[j][i].y + y)
			{
				if (D <= 0)
				{
					if (map.point[j][i].x + x != map.point[j][i + 1].x)
						x += 1;
					D = D + 2 * dx;
				}
				else
					D = D + 2 * (dx - dy);
				if (map.point[j][i].y + y != map.point[j][i + 1].y)
					y += 1;
				my_mlx_pixel_put(img, map.point[j][i].x + x, map.point[j][i].y + y, 0xFFFFFF);
			}
		}
	}
	x = 0;
	y = 0;
	if (j + 1 < map.lines)
	{
		dx = map.point[j + 1][i].x - map.point[j][i].x;
		dy = map.point[j + 1][i].y - map.point[j][i].y;
		D = 2 * dy - dx;
		if (dx > dy)
		{
			while (map.point[j + 1][i].x != map.point[j][i].x + x || map.point[j + 1][i].y != map.point[j][i].y + y)
			{
				if (D <= 0)
				{
					if (map.point[j][i].y + y != map.point[j + 1][i].y)
						y += 1;
					D = D + 2 * dy;
				}
				else
					D = D + 2 * (dy - dx);
				if (map.point[j][i].x + x != map.point[j + 1][i].x)
					x -= 1;
				my_mlx_pixel_put(img, map.point[j][i].x + x, map.point[j][i].y + y, 0xFFFFFF);
			}
		}
		else if (dx < dy)
		{
			while (map.point[j + 1][i].x != map.point[j][i].x + x || map.point[j + 1][i].y != map.point[j][i].y + y)
			{
				if (D <= 0)
				{
					if (map.point[j][i].x + x != map.point[j + 1][i].x)
						x -= 1;
					D = D + 2 * dx;
				}
				else
					D = D + 2 * (dx - dy);
				if (map.point[j][i].y + y != map.point[j + 1][i].y)
					y += 1;
				my_mlx_pixel_put(img, map.point[j][i].x + x, map.point[j][i].y + y, 0xFFFFFF);
			}
		}
	}
}

void	ft_rotate(t_map *map, int i, int j)
{
	double x;
	double y;
			
	x = (map->point[j][i].x - map->point[j][i].y) * SCALE * sin(M_PI/4);
	y = (map->point[j][i].x + map->point[j][i].y) * SCALE * sin(M_PI/4);
	y = y * cos(M_PI/3);
	y = y - sin(M_PI/3) * SCALE * map->point[j][i].z;
	map->point[j][i].x = x + 370;
	map->point[j][i].y = y + 100;
}

void	ft_window(t_map map)
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
	while (j < map.lines)
	{
		while (i < map.columns)
		{
			ft_rotate(&map, i, j);
	//		ft_bresenham(i, j, map, &img);
//			my_mlx_pixel_put(&img, map.point[j][i].x, map.point[j][i].y, 0xFFFFFF);
			i++;
		}
		i = 0;
		j++;
	}


// ----------------------------


	i = 0;
	j = 0; 
	while (j < map.lines)
	{
		while (i < map.columns)
		{
			ft_bresenham(i, j, map, &img);
			i++;
		}
		i = 0;
		j ++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

