/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:49:27 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/05 18:20:31 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

void	ft_free_map(t_map map, int lines)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < lines)
	{
		free (map.point[i]);
		i++;
	}
	free (map.point);
}
