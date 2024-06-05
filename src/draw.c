/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:23:48 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 19:48:46 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			ft_bresenham_x(i, j, *map);
			ft_bresenham_y(i, j, *map);
			i++;
		}
		i = 0;
		j++;
	}
}

void	set_image_black(t_map *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j <= HEIGHT)
	{
		while (i <= WIDTH)
		{
			my_mlx_pixel_put(&new->img, i, j, 0x000000);
			i++;
		}
		i = 0;
		j++;
	}
}

void	set_new_image(t_map *map)
{
	set_image_black(map);
	ft_draw(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
}

void	ft_bresenham_y(int i, int j, t_map map)
{
	t_bresenham	bsh;

	bsh.x = map.point[j][i].draw_x;
	bsh.y = map.point[j][i].draw_y;
	if (j + 1 < map.lines)
	{
		bsh.dx = abs(map.point[j + 1][i].draw_x - bsh.x);
		bsh.dy = abs(map.point[j + 1][i].draw_y - bsh.y);
		if (bsh.dx > bsh.dy)
		{
			bsh.d = 2 * bsh.dy - bsh.dx;
			while (bsh.x != map.point[j + 1][i].draw_x)
				draw_y_dx(map, i, j, &bsh);
		}
		else
		{
			bsh.d = 2 * bsh.dx - bsh.dy;
			while (bsh.y != map.point[j + 1][i].draw_y)
				draw_y_dy(map, i, j, &bsh);
		}
	}
}

void	ft_bresenham_x(int i, int j, t_map map)
{
	t_bresenham	bsh;

	bsh.x = map.point[j][i].draw_x;
	bsh.y = map.point[j][i].draw_y;
	if (i + 1 < map.columns)
	{
		bsh.dx = abs(map.point[j][i + 1].draw_x - bsh.x);
		bsh.dy = abs(map.point[j][i + 1].draw_y - bsh.y);
		bsh.d = 2 * bsh.dy - bsh.dx;
		if (bsh.dx > bsh.dy)
		{
			while (bsh.x != map.point[j][i + 1].draw_x)
				draw_x_dx(map, i, j, &bsh);
		}
		else
		{
			bsh.d = 2 * bsh.dx - bsh.dy;
			while (bsh.y != map.point[j][i + 1].draw_y)
				draw_x_dy(map, i, j, &bsh);
		}
	}
}
