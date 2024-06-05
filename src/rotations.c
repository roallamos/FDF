/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 16:30:22 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/09 19:56:17 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_z_rotation(t_rot *rot, int i, int j, t_map *map)
{
	rot->x = map->point[j][i].x * cos(map->z_rotation) - map->point[j][i].y
		* sin(map->z_rotation);
	rot->y = map->point[j][i].x * sin(map->z_rotation) + map->point[j][i].y
		* cos(map->z_rotation);
	rot->z = map->point[j][i].z;
}

void	ft_x_rotation(t_rot *rot, t_map *map)
{
	double	y;
	double	z;

	y = rot->y;
	z = rot->z;
	rot->y = y * cos(map->x_rotation) - z * sin(map->x_rotation);
	rot->z = y * sin(map->x_rotation) + z * cos(map->x_rotation);
}

void	ft_y_rotation(t_rot *rot, t_map *map)
{
	double	x;
	double	z;

	x = rot->x;
	z = rot->z;
	rot->x = x * cos(map->y_rotation) + z * sin(map->y_rotation);
	rot->z = z * cos(map->y_rotation) - x * sin(map->y_rotation);
}

void	ft_rotations(int i, int j, t_map *map)
{
	t_rot	rot;

	ft_z_rotation(&rot, i, j, map);
	ft_x_rotation(&rot, map);
	ft_y_rotation(&rot, map);
	map->point[j][i].draw_x = rot.x * map->scale;
	map->point[j][i].draw_y = rot.y * map->scale;
}
