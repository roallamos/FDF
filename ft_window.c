/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:45:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/26 19:42:13 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_window(int lines, int columns)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int i;
	int j;
	int y = 0; // isto vai ser y e onde pon lines tes que poñer en fronte lines
	int x = 0; // ito vay ser x e onde pon columns tes que poñer en fronte columns

	i = 0;
	j = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "perro");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (y < lines)
	{
		while (i <= WIDTH / (SCALE * (columns - 1)))
			my_mlx_pixel_put(&img, i++ + WIDTH/2 - WIDTH/10 - y * WIDTH / (SCALE * (lines - 1)), j++ + HEIGHT/10 + y * WIDTH / (SCALE * (lines - 1)), 0xFFFFFF);
		i = 0;
		j = 0;
		y++;
	}
	while (x < columns)
	{
		while (j <= HEIGHT / SCALE)
			my_mlx_pixel_put(&img, i-- + WIDTH/2 - WIDTH/10 + x * HEIGHT / (SCALE * (lines - 1)), j++ + HEIGHT/10 + x * HEIGHT / (SCALE * (lines - 1)), 0xFFFFFF);
		i = 0;
		j = 0;
		x++;
	}

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

