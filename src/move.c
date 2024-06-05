/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:54:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 19:57:50 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_views(int keycode, t_map *map)
{
	if (keycode == 112)
	{
		map->z_rotation = 0;
		map->x_rotation = 0;
	}
	if (keycode == 105)
	{
		map->z_rotation = M_PI / 4;
		map->x_rotation = M_PI / 3;
	}
	if (keycode == 108)
	{
		map->z_rotation = M_PI / 2;
		map->x_rotation = M_PI / 2;
	}
	if (keycode == 97)
	{
		map->z_rotation = 0;
		map->x_rotation = M_PI / 2;
	}
	map->y_rotation = 0;
	ft_rotate(map);
	set_new_image(map);
	return (0);
}

void	ft_move(int keycode, t_map *map)
{
	if (keycode == 65362)
		map->y_offset -= 10;
	if (keycode == 65364)
		map->y_offset += 10;
	if (keycode == 65363)
		map->x_offset += 10;
	if (keycode == 65361)
		map->x_offset -= 10;
}
