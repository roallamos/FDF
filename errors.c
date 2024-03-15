/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 17:20:18 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/15 11:15:13 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	terminate(char *error)
{
	if (errno == 0)
		ft_putendl_fd(error, 2);
	else
		perror(error);
	exit(1);
}

void	ft_check_columns(int columns, char **spl)
{
	int	i;

	i = 0;
	while(spl[i])
		i++;
	if (columns != i)
		terminate(ERR_MAP);
}
