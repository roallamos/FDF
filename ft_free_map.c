/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:49:27 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/26 11:32:40 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

void	ft_free_map(t_struct **map, int lines)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lines)
	{
		free (map[i]);
		i++;
	}
	free (map);
}
