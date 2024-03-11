/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:45:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/11 19:12:48 by rodralva         ###   ########.fr       */
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

/*int	colour_gradient()
{
	int	color;
	
	color = 0xFFFFFF;
	return ((colour - 0x000000) / dx);
}*/

void	ft_bresenham_y(int i, int j, t_map map, t_data *img)
{
	int dx;
	int dy;
	int D;
	int x;
	int y;
	int c = 0;

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
				
				my_mlx_pixel_put(img, x, y, ((map.point[j][i].red + c * (map.point[j + 1][i].red - map.point[j][i].red) / dx) * 65536 + (map.point[j][i].green + c * (map.point[j + 1][i].green - map.point[j][i].green) / dx) * 256 + (map.point[j][i].blue + c * (map.point[j + 1][i].blue - map.point[j][i].blue) / dx)));
				x += (map.point[j + 1][i].x - map.point[j][i].x)/dx;
				if (D < 0)
					D = D + 2 * dy;
				else
				{
					D = D + 2 * (dy - dx);
					y += (map.point[j + 1][i].y - map.point[j][i].y)/dy;
				}
				c++;
			}
		}
		else
		{
			D = 2 * dx - dy;
			while (y != map.point[j + 1][i].y)
			{
				my_mlx_pixel_put(img, x, y, map.point[j][i].colour);
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
				my_mlx_pixel_put(img, x, y, map.point[j][i].colour);
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
				my_mlx_pixel_put(img, x, y, map.point[j][i].colour);
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
//	int		SCALE_Z;

//	SCALE_Z = 100;
//	while (SCALE * map->columns / sin(M_PI/6) > WIDTH + 370 || SCALE * map->lines / sin(M_PI/6) > HEIGHT - 100)
	while (map->SCALE * map->columns * sin(M_PI/4) < WIDTH/2 && map->SCALE * map->lines * sin(M_PI/6) < HEIGHT/2 && map->SCALE * map->max_z * sin(M_PI/3) < HEIGHT / 3)
		map->SCALE += 0.2;
	x = (map->point[j][i].x - map->point[j][i].y) * map->SCALE * sin(M_PI/4);
	y = (map->point[j][i].x + map->point[j][i].y) * map->SCALE * sin(M_PI/4);
	y = y * cos(M_PI/3);
//	while (y + SCALE_Z * map->max_z / sin(M_PI/3) > HEIGHT / 2)
//		SCALE_Z = SCALE_Z * 90/100;
	y = y - sin(M_PI/3) * map->SCALE * map->point[j][i].z;
	map->point[j][i].x = x + WIDTH/2;
	map->point[j][i].y = y + HEIGHT/3;
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
	map.SCALE = 1;
	while (j < map.lines)
	{
		while (i < map.columns)
		{
			ft_rotate(&map, i, j);
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
			ft_bresenham_x(i, j, map, &img);
			ft_bresenham_y(i, j, map, &img);
			i++;
		}
		i = 0;
		j ++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

