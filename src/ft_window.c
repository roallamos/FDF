/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:45:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/06/06 15:45:18 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_scale(t_map *map)
{
	while (map->scale * map->columns * sin(M_PI / 4) < WIDTH / 2 && map->scale
		* map->lines * sin(M_PI / 6) < HEIGHT / 2 && map->scale * map->max_z
		* sin(M_PI / 3) < HEIGHT / 3)
		map->scale += 0.2;
}

void	ft_rotate(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			ft_rotations(i, j, map);
			i++;
		}
		i = 0;
		j++;
	}
}

int	ft_x_close(t_map *map)
{
	mlx_destroy_image(map->mlx.mlx, map->img.img);
	mlx_destroy_window(map->mlx.mlx, map->mlx.win);
	mlx_loop_end(map->mlx.mlx);
	mlx_destroy_display(map->mlx.mlx);
	ft_free_map(*map);
	exit(0);
	return (0);
}

void	ft_window(t_map *map)
{
	map->mlx.mlx = mlx_init();
	map->mlx.win = mlx_new_window(map->mlx.mlx, WIDTH, HEIGHT, "perro");
	map->img.img = mlx_new_image(map->mlx.mlx, WIDTH, HEIGHT);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bits_per_pixel,
			&map->img.line_length, &map->img.endian);
	ft_scale(map);
	map->z_rotation = M_PI / 4;
	map->x_rotation = M_PI / 3;
	map->y_rotation = 0;
	map->x_offset = WIDTH / 2;
	map->y_offset = HEIGHT / 3;
	ft_rotate(map);
	ft_draw(map);
	mlx_put_image_to_window(map->mlx.mlx, map->mlx.win, map->img.img, 0, 0);
}
