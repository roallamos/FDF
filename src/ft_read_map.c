/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:40:20 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 20:35:28 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_read_map(char *map, t_list **list)
{
	char	*content;
	int		fd;
	int		i;

	i = 0;
	content = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		terminate(ERR_OPEN);
	while (content || !*list)
	{
		content = get_next_line(fd);
		ft_lstadd_back(list, ft_lstnew(content));
		if (content)
			i++;
	}
	close(fd);
	return (i);
}
