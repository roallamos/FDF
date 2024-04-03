#include "fdf.h"

void	ft_move_down(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			map->point[j][i].draw_y += 10;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_move_up(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			map->point[j][i].draw_y -= 10;
			i++;
		}
		i = 0;
		j++;
	}
}
void	ft_move_right(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			map->point[j][i].draw_x += 10;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_move_left(t_map *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < map->lines)
	{
		while (i < map->columns)
		{
			map->point[j][i].x -= 10;
			i++;
		}
		i = 0;
		j++;
	}
}

