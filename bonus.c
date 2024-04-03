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

void	ft_zoom(t_map *new)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < new->lines)
	{
		while (i < new->columns)
		{
			new->point[j][i].x = new->point[j][i].x * new->SCALE;
			new->point[j][i].y = new->point[j][i].x * new->SCALE;
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
	t_map *new;

	new = (t_map *) map;
	x = 2 + 2;
	y = 2 +2 + x;
	x = 2 +2 + y;
	if (keycode == 4)
	{
		new->SCALE = (double)(new->SCALE * 1.1);
		ft_rotate(new);
		set_image_black(new);
		ft_draw(new);
		mlx_put_image_to_window(new->mlx.mlx, new->mlx.win, new->img.img, 0, 0);
	}
	if (keycode == 5)
	{
		new->SCALE = (double)(new->SCALE / 1.1);
		ft_rotate(new);
		set_image_black(new);
		ft_draw(new);
		mlx_put_image_to_window(new->mlx.mlx, new->mlx.win, new->img.img, 0, 0);
	}
	return (0);
}
