/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:00 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/06 12:58:39 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void leaks()
{
	system("leaks -q a.out");
}

int	main(int argc, char **argv)
{
	int		lines;
	int		columns;
	t_list	*list;
	t_map	map;

	columns = 0;
	if (argc != 2)
		return (0);
	list = NULL;
	lines = ft_read_map(argv[1], &list);
	map = ft_map_array(list, lines, &columns);
	ft_lstclear(&list, free);
//	while (list)
//	{
//		printf("lista ---- %s\n", list->content);
//		list = list->next;
//	}
	//ft_free_map(map, lines);
//	ft_print(map);
	ft_window(lines, columns, map);
	ft_free_map(map, lines);
	atexit(leaks);
	return (0);
}
