/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:49:27 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/14 12:47:21 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

void	ft_free_map(t_map map)
{
	int i;

	i = 0;
	while (i < map.lines)
	{
		free (map.point[i]);
		i++;
	}
	free (map.point);
}
