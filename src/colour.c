/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:51:27 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 19:47:57 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_bitwise(t_map *map, int x, int y, int nb)
{
	unsigned char	aux;

	aux = nb & 0xFF;
	map->point[y][x].blue = (double)aux;
	aux = (nb >> 8) & 0xFF;
	map->point[y][x].green = (double)aux;
	aux = (nb >> 16) & 0xFF;
	map->point[y][x].red = (double)aux;
	return (nb);
}

int	ft_atoi_hex(char *str, t_map *map, int x, int y)
{
	int				nb;
	int				i;

	nb = 0;
	i = 0;
	while (str[i] != 'x')
		i++;
	if (str[i] == 'x')
		i++;
	while ((str[i] >= 'A' && str[i] <= 'F') || (str[i] >= '0' && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] <= 'f'))
	{
		if (str[i] >= 'A' && str[i] <= 'F')
			nb = nb * 16 + (str[i] - 55);
		else if (str[i] >= 'a' && str[i] <= 'f')
			nb = nb * 16 + (str[i] - 87);
		else
			nb = nb * 16 + (str[i] - '0');
		i++;
	}
	return (ft_bitwise(map, x, y, nb));
}

void	ft_set_colour(t_map *map, char *spl, int l, int j)
{
	if (ft_strchr(spl, ','))
		map->point[l][j].colour = ft_atoi_hex(spl, map, j, l);
	else
		map->point[l][j].colour = ft_atoi_hex("0xFFFFFF", map, j, l);
}
