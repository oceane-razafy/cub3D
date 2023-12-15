/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbae <tbae@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:07:03 by tbae              #+#    #+#             */
/*   Updated: 2023/12/13 09:57:40 by tbae             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_line(char **argv, t_cub3d *cub3d)
{
	char	*line;
	int		fd;
	int		nb_line;

	nb_line = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_cub3d_error(cub3d, "Map cannot be opened\n"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		nb_line++;
		free (line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (nb_line);
}

void	scan_file(t_cub3d *cub3d, char **argv)
{
	int		idx;
	int		nb_line;
	char	**file;

	if (ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])) == 0)
		return (ft_cub3d_error(cub3d,
				"Provide a file with a .cub extension\n"));
	if (ft_strlen(ft_strnstr(argv[1], ".cub", ft_strlen(argv[1]))) != 4)
		return (ft_cub3d_error(cub3d,
				"Provide a file with a .cub extension\n"));
	nb_line = count_line(argv, cub3d);
	file = build_file(cub3d, argv, nb_line);
	idx = 0;
	while (idx < nb_line)
		free(file[idx++]);
	free(file);
	check_element(cub3d);
	if (cub3d->file_info.floor_color == -1)
		return (ft_cub3d_error(cub3d, "Floor color not found\n"));
	if (cub3d->file_info.ceiling_color == -1)
		return (ft_cub3d_error(cub3d, "Ceiling color not found\n"));
	return ;
}
