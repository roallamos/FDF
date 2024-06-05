/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:49:27 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 20:35:11 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.lines)
	{
		free(map.point[i]);
		i++;
	}
	free(map.point);
}
