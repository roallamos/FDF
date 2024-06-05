/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:58:05 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 15:12:50 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_load_points(t_map *map, char **spl, int l, int j)
{
	map->point[l][j].z = ft_atoi(spl[j]);
	if (abs(map->point[l][j].z) > map->max_z)
		map->max_z = abs(map->point[l][j].z);
	map->point[l][j].x = j - map->columns / 2;
	map->point[l][j].y = l - map->lines / 2;
	free(spl[j]);
}

void	ft_set_map(t_list *list, t_map *map, int l, int j)
{
	char	**spl;

	spl = ft_split(list->content, ' ');
	if (l != 0)
		ft_check_columns(map->columns, spl);
	while (spl[map->columns])
		map->columns += 1;
	map->point[l] = (t_struct *)malloc(map->columns * sizeof(t_struct));
	if (!map->point[l])
		terminate(ERR_MEM);
	while (j < map->columns)
	{
		ft_set_colour(map, spl[j], l, j);
		ft_load_points(map, spl, l, j);
		j++;
	}
	free(spl);
}

int	ft_map_array(t_list *list, t_map *map)
{
	int		l;
	int		j;

	l = 0;
	j = 0;
	map->point = (t_struct **)malloc(map->lines * sizeof(t_struct *));
	if (!map->point)
		terminate(ERR_MEM);
	while (l < map->lines)
	{
		ft_set_map(list, map, l, j);
		j = 0;
		l++;
		list = list->next;
	}
	return (1);
}
