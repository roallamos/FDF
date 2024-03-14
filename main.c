/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:00 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/14 15:55:23 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void leaks()
{
	system("leaks -q a.out");
}

void	ft_load_map(t_map *map, char *argv)
{
	t_list	*list;

	list = NULL;
	map->lines = ft_read_map(argv, &list);
	ft_map_array(list, map);
	ft_lstclear(&list, free);
}

int	main(int argc, char **argv)
{
//	t_list	*list;
	t_utils	data;
//	t_map	map;

	atexit(leaks);
	if (argc != 2)
		terminate(ERR_ARGS);
	ft_load_map(&data.map, argv[1]);
//	ft_init_var(&data.map.mlx);
	ft_window(data.map);
	ft_free_map(data.map);
	return (0);
}
