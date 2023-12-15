/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:07:03 by tbae              #+#    #+#             */
/*   Updated: 2023/12/13 14:44:17 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_around(t_cub3d *cub3d, int idx_x, int idx_y)
{
	int		nb_line;

	nb_line = 0;
	while (cub3d->file_info.map[nb_line]
		&& cub3d->file_info.map[nb_line][0] != '\0')
		nb_line++;
	if (idx_y == 0 || idx_x == 0 || idx_x == nb_line - 1
		|| idx_y == ft_strlen(cub3d->file_info.map[idx_x]) - 1)
		return (ft_cub3d_error(cub3d, "Map not formated correctly\n"));
	if (idx_y > ft_strlen(cub3d->file_info.map[idx_x - 1]) - 1)
		return (ft_cub3d_error(cub3d, "Map not formated correctly\n"));
	if (idx_y > ft_strlen(cub3d->file_info.map[idx_x + 1]) - 1)
		return (ft_cub3d_error(cub3d, "Map not formated correctly\n"));
	if (cub3d->file_info.map[idx_x][idx_y - 1] == ' '
		|| cub3d->file_info.map[idx_x][idx_y + 1] == ' '
		|| cub3d->file_info.map[idx_x - 1][idx_y] == ' '
		|| cub3d->file_info.map[idx_x + 1][idx_y] == ' ')
		return (ft_cub3d_error(cub3d, "Map not formated correctly\n"));
}

int	exec_line_element(t_cub3d *cub3d, int i_l, int i_c, t_player_view d)
{
	cub3d->file_info.player_x = i_l;
	cub3d->file_info.player_y = i_c;
	cub3d->file_info.player_view = d;
	return (1);
}

static int	checking_line_element(t_cub3d *cub3d, int idx_line)
{
	int		idx_column;
	int		player;

	idx_column = 0;
	player = 0;
	while (cub3d->file_info.map[idx_line][idx_column] != '\0')
	{
		if (cub3d->file_info.map[idx_line][idx_column] == 'N')
			player += exec_line_element(cub3d, idx_line, idx_column, north);
		else if (cub3d->file_info.map[idx_line][idx_column] == 'E')
			player += exec_line_element(cub3d, idx_line, idx_column, east);
		else if (cub3d->file_info.map[idx_line][idx_column] == 'W')
			player += exec_line_element(cub3d, idx_line, idx_column, west);
		else if (cub3d->file_info.map[idx_line][idx_column] == 'S')
			player += exec_line_element(cub3d, idx_line, idx_column, south);
		else if (cub3d->file_info.map[idx_line][idx_column] == '0')
			check_around(cub3d, idx_line, idx_column);
		else if (cub3d->file_info.map[idx_line][idx_column] != '1'
				&& cub3d->file_info.map[idx_line][idx_column] != ' ')
			return (ft_cub3d_error(cub3d, "Wrong element in the map\n"), 1);
		idx_column++;
	}
	return (player);
}

void	check_element(t_cub3d *cub3d)
{
	int		idx_line;
	int		nb_line;
	int		player;

	idx_line = 0;
	nb_line = 0;
	player = 0;
	while (cub3d->file_info.map[nb_line])
		nb_line++;
	while (idx_line < nb_line)
	{
		player += checking_line_element(cub3d, idx_line);
		idx_line++;
	}
	if (player != 1)
		return (ft_cub3d_error(cub3d, "Wrong number of player\n"));
	check_around(cub3d, cub3d->file_info.player_x, cub3d->file_info.player_y);
	nb_line = 0;
	while (cub3d->file_info.map[nb_line]
		&& cub3d->file_info.map[nb_line][0] != '\0')
		nb_line++;
	cub3d->file_info.nb_line = nb_line;
	return ;
}

void	build_map(t_cub3d *cub3d, char **file, int idx)
{
	int		nb_line;
	int		idx_map;

	nb_line = 0;
	idx_map = 0;
	while (file[nb_line + idx] != NULL)
		nb_line++;
	cub3d->file_info.map = malloc (sizeof(char *) * (nb_line + 1));
	if (!cub3d->file_info.map)
		return (ft_cub3d_error(cub3d, "Malloc of file_info.map failed\n"));
	while (idx_map < nb_line)
	{
		cub3d->file_info.map[idx_map] = ft_strdup(file[idx]);
		if (cub3d->file_info.map[idx_map] == NULL)
			return (ft_cub3d_error(cub3d, "Malloc of file_info.map failed\n"));
		idx++;
		idx_map++;
	}
	cub3d->file_info.map[idx_map] = NULL;
	return ;
}
