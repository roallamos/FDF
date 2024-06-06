/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:00 by rodralva          #+#    #+#             */
/*   Updated: 2024/06/06 15:42:23 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	leaks(void)
{
	system("leaks -q fdf");
}*/

void	ft_load_map(t_map *map, char *argv)
{
	t_list	*list;

	list = NULL;
	map->lines = ft_read_map(argv, &list);
	if (list->content == NULL)
		terminate(ERR_EMP);
	map->columns = 0;
	map->max_z = 0;
	ft_map_array(list, map);
	ft_lstclear(&list, free);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		terminate(ERR_ARGS);
	ft_memset(&map, 0, sizeof(t_map));
	ft_load_map(&map, argv[1]);
	ft_window(&map);
	mlx_key_hook(map.mlx.win, ft_press_key, &map);
	mlx_hook(map.mlx.win, 2, 1L << 0, ft_hold_key, &map);
	mlx_hook(map.mlx.win, 4, 1L<<2, ft_mouse_press, &map);
	mlx_hook(map.mlx.win, 5, 1L<<3, ft_mouse_release, &map);
	mlx_hook(map.mlx.win, 6, 1L<<6, ft_mouse_move, &map);
	mlx_hook(map.mlx.win, 17, 0L, ft_x_close, &map);
	mlx_loop(map.mlx.mlx);
	return (0);
}
