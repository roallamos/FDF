/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:37:31 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 19:50:08 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_y_dx(t_map map, int i, int j, t_bresenham *bsh)
{
	bsh->rp = (double)abs(bsh->x - map.point[j][i].draw_x) / bsh->dx;
	bsh->red = (bsh->rp * map.point[j + 1][i].red + (1 - bsh->rp)
			* map.point[j][i].red);
	bsh->green = (bsh->rp * map.point[j + 1][i].green + (1 - bsh->rp)
			* map.point[j][i].green);
	bsh->blue = (bsh->rp * map.point[j + 1][i].blue + (1 - bsh->rp)
			* map.point[j][i].blue);
	my_mlx_pixel_put(&map.img, bsh->x + map.x_offset, bsh->y + map.y_offset,
		((int)bsh->red << 16) + ((int)bsh->green << 8) + (int)bsh->blue);
	bsh->x += (map.point[j + 1][i].draw_x - map.point[j][i].draw_x) / bsh->dx;
	if (bsh->d < 0)
		bsh->d = bsh->d + 2 * bsh->dy;
	else
	{
		bsh->d = bsh->d + 2 * (bsh->dy - bsh->dx);
		bsh->y += (map.point[j + 1][i].draw_y - map.point[j][i].draw_y)
			/ bsh->dy;
	}
}

void	draw_y_dy(t_map map, int i, int j, t_bresenham *bsh)
{
	bsh->rp = (double)abs(bsh->y - map.point[j][i].draw_y) / bsh->dy;
	bsh->red = (bsh->rp * map.point[j + 1][i].red + (1 - bsh->rp)
			* map.point[j][i].red);
	bsh->green = (bsh->rp * map.point[j + 1][i].green + (1 - bsh->rp)
			* map.point[j][i].green);
	bsh->blue = (bsh->rp * map.point[j + 1][i].blue + (1 - bsh->rp)
			* map.point[j][i].blue);
	my_mlx_pixel_put(&map.img, bsh->x + map.x_offset, bsh->y + map.y_offset,
		((int)bsh->red << 16) + ((int)bsh->green << 8) + (int)bsh->blue);
	bsh->y += (map.point[j + 1][i].draw_y - map.point[j][i].draw_y) / bsh->dy;
	if (bsh->d < 0)
		bsh->d = bsh->d + 2 * bsh->dx;
	else
	{
		bsh->d = bsh->d + 2 * (bsh->dx - bsh->dy);
		bsh->x += (map.point[j + 1][i].draw_x - map.point[j][i].draw_x)
			/ bsh->dx;
	}
}

void	draw_x_dx(t_map map, int i, int j, t_bresenham *bsh)
{
	bsh->rp = (double)abs(bsh->x - map.point[j][i].draw_x) / bsh->dx;
	bsh->red = (bsh->rp * map.point[j][i + 1].red + (1 - bsh->rp)
			* map.point[j][i].red);
	bsh->green = (bsh->rp * map.point[j][i + 1].green + (1 - bsh->rp)
			* map.point[j][i].green);
	bsh->blue = (bsh->rp * map.point[j][i + 1].blue + (1 - bsh->rp)
			* map.point[j][i].blue);
	my_mlx_pixel_put(&map.img, bsh->x + map.x_offset, bsh->y + map.y_offset,
		((int)bsh->red << 16) + ((int)bsh->green << 8) + (int)bsh->blue);
	bsh->x += (map.point[j][i + 1].draw_x - map.point[j][i].draw_x) / bsh->dx;
	if (bsh->d < 0)
		bsh->d = bsh->d + 2 * bsh->dy;
	else
	{
		bsh->d = bsh->d + 2 * (bsh->dy - bsh->dx);
		bsh->y += (map.point[j][i + 1].draw_y - map.point[j][i].draw_y)
			/ bsh->dy;
	}
}

void	draw_x_dy(t_map map, int i, int j, t_bresenham *bsh)
{
	bsh->rp = (double)abs(bsh->y - map.point[j][i].draw_y) / bsh->dy;
	bsh->red = (bsh->rp * map.point[j][i + 1].red + (1 - bsh->rp)
			* map.point[j][i].red);
	bsh->green = (bsh->rp * map.point[j][i + 1].green + (1 - bsh->rp)
			* map.point[j][i].green);
	bsh->blue = (bsh->rp * map.point[j][i + 1].blue + (1 - bsh->rp)
			* map.point[j][i].blue);
	my_mlx_pixel_put(&map.img, bsh->x + map.x_offset, bsh->y + map.y_offset,
		((int)bsh->red << 16) + ((int)bsh->green << 8) + (int)bsh->blue);
	bsh->y += (map.point[j][i + 1].draw_y - map.point[j][i].draw_y) / bsh->dy;
	if (bsh->d < 0)
		bsh->d = bsh->d + 2 * bsh->dx;
	else
	{
		bsh->d = bsh->d + 2 * (bsh->dx - bsh->dy);
		bsh->x += (map.point[j][i + 1].draw_x - map.point[j][i].draw_x)
			/ bsh->dx;
	}
}
