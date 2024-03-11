/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:00 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/11 18:00:11 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
void leaks()
{
	system("leaks -q a.out");
}

int	main(int argc, char **argv)
{
	t_list	*list;
	t_map	map;

	if (argc != 2)
		return (0);
	list = NULL;
	map.lines = ft_read_map(argv[1], &list);
	ft_map_array(list, &map);
	ft_lstclear(&list, free);
//	while (list)
//	{
//		printf("lista ---- %s\n", list->content);
//		list = list->next;
//	}
//	ft_print(map);
	ft_window(map);
	ft_free_map(map);
//	atexit(leaks);
	return (0);
}
