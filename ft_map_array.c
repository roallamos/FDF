/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 10:58:05 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/26 14:49:24 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

t_struct **ft_map_array(t_list *list, int lines, int *columns)
{
	t_struct	**map;
	char	**spl;
	int	l;
	int j;
	
	l = 0;
	j = 0;
	map = (t_struct **) malloc(lines * sizeof(t_struct *));
	if (!map)
		return (NULL);
	while (l < lines)
	{
		spl = ft_split(list->content, ' ');
		while (spl[*columns])
			*columns += 1;
		map[l] = (t_struct *) malloc(*columns * sizeof(t_struct));
		if (!map[l])
			return (NULL);
		while (j < *columns)
		{
			if (ft_strchr(spl[j], ','))
				map[l][j].colour =ft_substr(spl[j], 1, ft_strlen(spl[j]));
			map[l][j].height = ft_atoi(spl[j]);
			map[l][j].x = j;
			map[l][j].y = l;
			free (spl[j]);
			j++;
		}
		j = 0;
		l++;
		list = list->next;
		free (spl);
	}
	return (map);
}
