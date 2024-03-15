/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 12:23:48 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/15 12:25:14 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			ft_bresenham_x(i, j, *map, &map->img);
			ft_bresenham_y(i, j, *map, &map->img);
			i++;
		}
		i = 0;
		j++;
	}
}
