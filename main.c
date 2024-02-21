/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:00 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/21 21:15:39 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

int	main(int argc, char **argv)
{
	int 	fd;
	int		lines;
	t_list	*list;
//	int		**map;
	t_list	*flist;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	list = NULL; 
	lines = ft_read_map(fd, &list);
//	map = ft_map_array(list);
	flist = list;
	while (list)
	{
		printf("%s\n", list->content);
		list = list->next;
	}
	ft_lstclear(&flist, free);
	system("leaks -q a.out");
	return (0);
}
