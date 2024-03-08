/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:58:05 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/08 14:16:10 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

int ft_map_array(t_list *list, t_map *map)
{
	char	**spl;
	int		l;
	int		j;
	
	l = 0;
	j = 0;
	map->max_z = 0;
	map->columns = 0;
	map->point = (t_struct **) malloc(map->lines * sizeof(t_struct *));
	if (!map->point)
		return (0);
	while (l < map->lines)
	{
		spl = ft_split(list->content, ' ');
		while (spl[map->columns])
			map->columns += 1;
		map->point[l] = (t_struct *) malloc(map->columns * sizeof(t_struct));
		if (!map->point[l])
			return (0);
		while (j < map->columns)
		{
			if (ft_strchr(spl[j], ','))
				map->point[l][j].colour =ft_substr(spl[j], 1, ft_strlen(spl[j]));
			map->point[l][j].z = ft_atoi(spl[j]);
			if (abs(map->point[l][j].z) > map->max_z)
				map->max_z = abs(map->point[l][j].z);
			map->point[l][j].x = j;
			map->point[l][j].y = l;
		//	printf("las x -> %i las y -> %i", map.point[l][j].x, map.point[l][j].y);
			free (spl[j]);
			j++;
		}
		j = 0;
		l++;
		list = list->next;
		free (spl);
	}
	return (1);
}
