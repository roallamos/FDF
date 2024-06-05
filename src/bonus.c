/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 08:23:08 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 19:59:05 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_map *new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < new->lines)
	{
		while (i < new->columns)
		{
			new->point[j][i].x = new->point[j][i].x * new->scale;
			new->point[j][i].y = new->point[j][i].x * new->scale;
			i++;
		}
		i = 0;
		j++;
	}
}

int	ft_hold_key(int keycode, t_map *map)
{
	if (keycode >= 65361 && keycode <= 65364)
		ft_move(keycode, map);
	if (keycode == 120)
	{
		map->x_rotation = (double)(map->x_rotation + 0.1);
		ft_rotate(map);
	}
	if (keycode == 121)
	{
		map->y_rotation = (double)(map->y_rotation + 0.1);
		ft_rotate(map);
	}
	if (keycode == 122)
	{
		map->z_rotation = (double)(map->z_rotation + 0.1);
		if (map->z_rotation >= 2 * M_PI)
			map->z_rotation = (double)(map->z_rotation - 2 * M_PI);
		ft_rotate(map);
	}
	set_new_image(map);
	return (0);
}

int	ft_press_key(int keycode, t_map *map)
{
	if (keycode == 105 || keycode == 112 || keycode == 97 || keycode == 108)
		ft_views(keycode, map);
	if (keycode == 65307)
	{
		mlx_destroy_image(map->mlx.mlx, map->img.img);
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		ft_free_map(*map);
		exit(0);
	}
	return (0);
}
