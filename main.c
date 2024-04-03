/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:00 by rodralva          #+#    #+#             */
/*   Updated: 2024/03/15 14:39:30 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void leaks()
{
//	system("leaks -q a.out");
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
	t_map	map;

//	atexit(leaks);
	if (argc != 2)
		terminate(ERR_ARGS);
	ft_load_map(&map, argv[1]);
	ft_window(&map);
	mlx_mouse_hook(map.mlx.win, ft_mouse, &map);
	mlx_key_hook(map.mlx.win, ft_close, &map);
	mlx_hook(map.mlx.win, 2, 1L<<0, ft_hold_key, &map);
	mlx_hook(map.mlx.win, 17, 0L, ft_x_close, &map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
