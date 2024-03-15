/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:45:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/15 12:33:42 by rodralva         ###   ########.fr       */
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

void	ft_bresenham_y(int i, int j, t_map map, t_data *img)
{
	int dx;
	int dy;
	int D;
	int x;
	int y;
	double relative_pos;
	double red;
	double green;
	double blue;

	x = map.point[j][i].x;
	y = map.point[j][i].y;
	if (j + 1 < map.lines)
	{
		dx = abs(map.point[j + 1][i].x - x);
		dy = abs(map.point[j + 1][i].y - y);
		if (dx > dy)
		{
			D = 2 * dy - dx;
			while (x != map.point[j + 1][i].x)
			{
				relative_pos = (double) abs(x - map.point[j][i].x) / dx;
				red = (relative_pos * map.point[j + 1][i].red + (1 - relative_pos) * map.point[j][i].red);
				green = (relative_pos * map.point[j + 1][i].green + (1 - relative_pos) * map.point[j][i].green);
				blue = (relative_pos * map.point[j + 1][i].blue + (1 - relative_pos) * map.point[j][i].blue);
				my_mlx_pixel_put(img, x, y,  ((int)red << 16) + ((int)green << 8) + (int)blue);
				x += (map.point[j + 1][i].x - map.point[j][i].x)/dx;
				if (D < 0)
					D = D + 2 * dy;
				else
				{
					D = D + 2 * (dy - dx);
					y += (map.point[j + 1][i].y - map.point[j][i].y)/dy;
				}
			}
		}
		else
		{
			D = 2 * dx - dy;
			while (y != map.point[j + 1][i].y)
			{
				relative_pos = (double) abs(y - map.point[j][i].y) / dy;
				red = (relative_pos * map.point[j + 1][i].red + (1 - relative_pos) * map.point[j][i].red);
				green = (relative_pos * map.point[j + 1][i].green + (1 - relative_pos) * map.point[j][i].green);
				blue = (relative_pos * map.point[j + 1][i].blue + (1 - relative_pos) * map.point[j][i].blue);
				my_mlx_pixel_put(img, x, y,  ((int)red << 16) + ((int)green << 8) + (int)blue);
				y += (map.point[j + 1][i].y - map.point[j][i].y)/dy;
				if (D < 0)
					D = D + 2 * dx;
				else
				{
					D = D + 2 * (dx - dy);
					x += (map.point[j + 1][i].x - map.point[j][i].x)/dx;
				}
			}
		}
	}
}

void	ft_bresenham_x(int i, int j, t_map map, t_data *img)
{
	int dx;
	int dy;
	int D;
	int x;
	int y;
	double relative_pos;
	double red;
	double green;
	double blue;

	x = map.point[j][i].x;
	y = map.point[j][i].y;
	if (i + 1 < map.columns)
	{
		dx = abs(map.point[j][i + 1].x - x);
		dy = abs(map.point[j][i + 1].y - y);
		D = 2 * dy - dx;
		if (dx > dy)
		{
			while (x <= map.point[j][i + 1].x)
			{
				relative_pos = (double) abs(x - map.point[j][i].x) / dx;
				red = (relative_pos * map.point[j][i + 1].red + (1 - relative_pos) * map.point[j][i].red);
				green = (relative_pos * map.point[j][i + 1].green + (1 - relative_pos) * map.point[j][i].green);
				blue = (relative_pos * map.point[j][i + 1].blue + (1 - relative_pos) * map.point[j][i].blue);
				my_mlx_pixel_put(img, x, y,  ((int)red << 16) + ((int)green << 8) + (int)blue);
				x += (map.point[j][i + 1].x - map.point[j][i].x)/dx;
				if (D < 0)
					D = D + 2 * dy;
				else
				{
					D = D + 2 * (dy - dx);
					y += (map.point[j][i + 1].y - map.point[j][i].y)/dy;
				}
			}
		}
		else
		{
			D = 2 * dx - dy;
			while (y != map.point[j][i + 1].y)
			{
				relative_pos = (double) abs(y - map.point[j][i].y) / dy;
				red = (relative_pos * map.point[j][i + 1].red + (1 - relative_pos) * map.point[j][i].red);
				green = (relative_pos * map.point[j][i + 1].green + (1 - relative_pos) * map.point[j][i].green);
				blue = (relative_pos * map.point[j][i + 1].blue + (1 - relative_pos) * map.point[j][i].blue);
				my_mlx_pixel_put(img, x, y,  ((int)red << 16) + ((int)green << 8) + (int)blue);
				y += (map.point[j][i + 1].y - map.point[j][i].y)/dy;
				if (D < 0)
					D = D + 2 * dx;
				else
				{
					D = D + 2 * (dx - dy);
					x += (map.point[j][i + 1].x - map.point[j][i].x)/dx;
				}
			}
		}
	}
}


void	ft_rotate(t_map *map, int i, int j)
{
	double 	x;
	double 	y;

	while (map->SCALE * map->columns * sin(M_PI/4) < WIDTH/2 && map->SCALE * map->lines * sin(M_PI/6) < HEIGHT/2 && map->SCALE * map->max_z * sin(M_PI/3) < HEIGHT / 3)
		map->SCALE += 0.2;
	x = (map->point[j][i].x - map->point[j][i].y) * map->SCALE * sin(M_PI/4);
	y = (map->point[j][i].x + map->point[j][i].y) * map->SCALE * sin(M_PI/4);
	y = y * cos(M_PI/3);
	y = y - sin(M_PI/3) * map->SCALE * map->point[j][i].z;
	map->point[j][i].x = x + WIDTH/2;
	map->point[j][i].y = y + HEIGHT/3;
}

int	ft_close(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		ft_free_map(*map);
		exit(0);
	}
	return (0);
}

int	ft_x_close(t_map *map)
{
	mlx_destroy_window(map->mlx.mlx, map->mlx.win);
	ft_free_map(*map);
	exit(0);
	return (0);
}


void	ft_window(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map->mlx.mlx = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.mlx, WIDTH, HEIGHT, "perro");
	map->img.img = mlx_new_image(map->mlx.mlx, WIDTH, HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel, &map->img.line_length, &map->img.endian);
	map->SCALE = 1;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			ft_rotate(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	ft_draw(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
}
