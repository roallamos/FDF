/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodralva <rodralva@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:24:00 by rodralva          #+#    #+#             */
/*   Updated: 2024/02/20 21:28:00 by rodralva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (NULL);
	fd = open(*argv[1], O_RDONLY);
	else if (ft_check_map(fd))
