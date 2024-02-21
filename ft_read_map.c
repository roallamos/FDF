/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:40:20 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/21 21:15:42 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

int	ft_read_map(int fd, t_list **list)
{
	char	*content;
	int		i;

	i = 0;
	content = NULL;
	while (content || !*list)
	{
		content	= get_next_line(fd);
		ft_lstadd_back(list, ft_lstnew(content));
		if (content)
			i++;
	}
	return (i);
}
