/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:23:08 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/15 14:39:32 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_image_black(t_map *new)
{
	int i;
	int j;

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

void	ft_scale_negative(t_map *new)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < new->lines)
	{
		while (i < new->columns)
		{
			new->point[j][i].y = (double) (new->point[j][i].y * 0.9);
			new->point[j][i].x = (double) (new->point[j][i].x * 0.9);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_scale_positive(t_map *new)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < new->lines)
	{
		while (i < new->columns)
		{
			new->point[j][i].y = (double) (new->point[j][i].y * 1.1);
			new->point[j][i].x = (double) (new->point[j][i].x * 1.1);
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_move_down(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			map->point[j][i].y += 10;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_move_up(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			map->point[j][i].y -= 10;
			i++;
		}
		i = 0;
		j++;
	}
}
void	ft_move_right(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			map->point[j][i].x += 10;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_move_left(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			map->point[j][i].x -= 10;
			i++;
		}
		i = 0;
		j++;
	}
}
int	ft_hold_key(int keycode, t_map *map)
{
	if (keycode == 126)
	{
		ft_move_up(map);
		set_image_black(map);
		ft_draw(map);
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
	}
	if (keycode == 125)
	{
		ft_move_down(map);
		set_image_black(map);
		ft_draw(map);
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
	}
	if (keycode == 123)
	{
		ft_move_left(map);
		set_image_black(map);
		ft_draw(map);
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
	}
	if (keycode == 124)
	{
		ft_move_right(map);
		set_image_black(map);
		ft_draw(map);
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
	}
	return (0);
}

int	ft_mouse(int keycode, int x, int y, void *map)
{
	int i;
	int j;
	t_map *new;

	new = (t_map *) map;
	x = 2;
	y = 2;
	if (keycode == 4)
	{
		ft_scale_positive(new);
		set_image_black(new);	

		i = 0;
		j = 0;
		while (j < new->lines)
		{
			while (i < new->columns)
			{
				ft_bresenham_x(i, j, *new, &new->img);
				ft_bresenham_y(i, j, *new, &new->img);
				i++;
			}
			i = 0;
			j++;
		}
		mlx_put_image_to_window(new->mlx.mlx, new->mlx.win, new->img.img, 0, 0);
	}
	if (keycode == 5)
	{
		ft_scale_negative(new);
		set_image_black(new);	

		i = 0;
		j = 0;
		while (j < new->lines)
		{
			while (i < new->columns)
			{
				ft_bresenham_x(i, j, *new, &new->img);
				ft_bresenham_y(i, j, *new, &new->img);
				i++;
			}
			i = 0;
			j++;
		}
		mlx_put_image_to_window(new->mlx.mlx, new->mlx.win, new->img.img, 0, 0);
	}
	return (0);
}
