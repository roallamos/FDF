/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:06:28 by rodralva          #+#    #+#             */
/*   Updated: 2024/04/08 19:37:59 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_mouse_release(int keycode, int x, int y, void *map)
{
	t_map	*new;

	(void)x;
	(void)y;
	new = (t_map *)map;
	if (keycode == 3)
		new->mouse_key = 0;
	return (0);
}

int	ft_mouse_move(int x, int y, void *map)
{
	t_map	*new;

	if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
		return (0);
	new = (t_map *)map;
	if (new->mouse_key == 3)
	{
		new->x_rotation = (double)(new->x_rotation + (double)((new->y_mouse - y) / 3));
		new->y_rotation = (double)(new->y_rotation + (double)((new->x_mouse - x) / 3));
		new->x_mouse = x;
		new->y_mouse = y;
		ft_rotate(new);
		set_image_black(new);
		ft_draw(new);
		mlx_put_image_to_window(new->mlx.mlx, new->mlx.win, new->img.img, 0, 0);
	}
	return (0);
}

int	ft_mouse_press(int keycode, int x, int y, void *map)
{
	t_map	*new;

	new = (t_map *)map;
	if (keycode == 4)
	{
		new->scale = (double)(new->scale * 1.1);
		ft_rotate(new);
		set_new_image(new);
	}
	if (keycode == 5)
	{
		new->scale = (double)(new->scale / 1.1);
		ft_rotate(new);
		set_new_image(new);
	}
	if (keycode == 3)
	{
		new->x_mouse = x;
		new->y_mouse = y;
		new->mouse_key = 3;
	}
	return (0);
}
