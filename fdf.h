/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 20:36:36 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/26 17:20:48 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft/libft.h"
# include "./mlx/mlx.h"

# define WIDTH 720
# define HEIGHT 720
# define SCALE 10

typedef struct s_struct 
{
	int	height;
	int	x;
	int y;
	char *colour;
} t_struct;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int	ft_read_map(char *map, t_list **list);
t_struct	**ft_map_array(t_list *list, int lines, int *columns);
void	ft_free_map(t_struct **map, int lines);
void	ft_window(int lines, int collumns);
void	ft_print(t_struct **map);

#endif
