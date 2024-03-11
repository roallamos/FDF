/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:58:05 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/11 18:49:48 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"



int	ft_atoi_hex(char *str, t_map *map, int x, int y)
{
	int nb;
	int i;

	nb = 0;
	i = 0;
	while (str[i] != 'x')
		i++;
	i++;
	while ((str[i] >= 'A' && str[i] <= 'F') || (str[i] >= '0' && str[i] <= '9'))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb * 16 + (str[i] - 55);
		else
			nb = nb * 16 + (str[i] - '0');
		i++;
	}
	map->point[y][x].red = nb / 65536;
	map->point[y][x].green = (nb - 16711680) / 256;
	map->point[y][x].blue = (nb -16776960);
	return (nb);
}


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
				map->point[l][j].colour = ft_atoi_hex(spl[j], map, j, l);
			else
				map->point[l][j].colour = ft_atoi_hex("0xFFFFFF", map, j, l);
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
