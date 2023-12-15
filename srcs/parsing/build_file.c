/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:07:03 by tbae              #+#    #+#             */
/*   Updated: 2023/12/15 00:37:35 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_info(t_cub3d *cub3d, char *str, char **file)
{
	char	**str_color;
	int		color;

	str_color = ft_split(str, ',');
	if (str_color == NULL)
		return (ft_free_map_char(file), ft_cub3d_error(cub3d, "Malloc\n"), 1);
	if (str_color[0] == NULL || ft_atoi(str_color[0]) > 255
		|| ft_atoi(str_color[0]) < 0)
		return (ft_free_map_char(str_color), ft_free_map_char(file),
			ft_cub3d_error(cub3d, "wrong color (R)\n"), 1);
	color = ft_atoi(str_color[0]) * 16 * 16 * 16 * 16;
	if (str_color[1] == NULL || ft_atoi(str_color[1]) > 255
		|| ft_atoi(str_color[1]) < 0)
		return (ft_free_map_char(str_color), ft_free_map_char(file),
			ft_cub3d_error(cub3d, "wrong color (G)\n"), 1);
	color += ft_atoi(str_color[1]) * 16 * 16;
	if (str_color[2] == NULL || ft_atoi(str_color[2]) > 255
		|| ft_atoi(str_color[2]) < 0)
		return (ft_free_map_char(str_color), ft_free_map_char(file),
			ft_cub3d_error(cub3d, "wrong color (B)\n"), 1);
	color += ft_atoi(str_color[2]);
	if (str_color[3] != NULL)
		return (ft_free_map_char(str_color), ft_free_map_char(file),
			ft_cub3d_error(cub3d, "wrong color\n"), 1);
	return (ft_free_map_char(str_color), color);
}

void	put_tex_filename(t_cub3d *cub3d, char **file, int idx, char *str)
{
	int	skip;

	skip = 2;
	while (file[idx][skip] && file[idx][skip] == ' ')
		skip++;
	if (file[idx][skip] == '\0')
		return (ft_free_map_char(file),
			ft_cub3d_error(cub3d, "Texture file not found\n"));
	if (str[0] == 'N' && str[1] == 'O')
		cub3d->file_info.no_tex_filename = ft_get_tex_path(cub3d,
				cub3d->file_info.no_tex_filename, file[idx] + skip, file);
	else if (str[0] == 'S' && str[1] == 'O')
		cub3d->file_info.so_tex_filename = ft_get_tex_path(cub3d,
				cub3d->file_info.so_tex_filename, file[idx] + skip, file);
	else if (str[0] == 'W' && str[1] == 'E')
		cub3d->file_info.we_tex_filename = ft_get_tex_path(cub3d,
				cub3d->file_info.we_tex_filename, file[idx] + skip, file);
	else if (str[0] == 'E' && str[1] == 'A')
		cub3d->file_info.ea_tex_filename = ft_get_tex_path(cub3d,
				cub3d->file_info.ea_tex_filename, file[idx] + skip, file);
	return ;
}

void	put_colors(t_cub3d *cub3d, char **file, int idx, char *str)
{
	int	skip;

	skip = 1;
	while (file[idx][skip] && file[idx][skip] == ' ')
		skip++;
	if (file[idx][skip] == '\0')
		return (ft_free_map_char(file),
			ft_cub3d_error(cub3d, "Color missing\n"));
	if (str[0] == 'F')
	{
		if (cub3d->file_info.floor_color == -1)
			cub3d->file_info.floor_color = color_info(cub3d,
					file[idx] + skip, file);
		else
			return (ft_free_map_char(file), ft_cub3d_error(cub3d, "Floor\n"));
	}
	else if (str[0] == 'C')
	{
		if (cub3d->file_info.ceiling_color == -1)
			cub3d->file_info.ceiling_color = color_info(cub3d,
					file[idx] + skip, file);
		else
			return (ft_free_map_char(file), ft_cub3d_error(cub3d, "Ceiling\n"));
	}
	return ;
}

void	file_info(t_cub3d *cub3d, char **file, int idx)
{
	if (file[idx] == NULL)
		return (ft_free_map_char(file),
			ft_cub3d_error(cub3d, "Map not found\n"));
	if (file[idx][0] == 'N' && file[idx][1] == 'O')
		return (put_tex_filename(cub3d, file, idx, "NO"),
			file_info(cub3d, file, idx + 1));
	if (file[idx][0] == 'S' && file[idx][1] == 'O')
		return (put_tex_filename(cub3d, file, idx, "SO"),
			file_info(cub3d, file, idx + 1));
	if (file[idx][0] == 'W' && file[idx][1] == 'E')
		return (put_tex_filename(cub3d, file, idx, "WE"),
			file_info(cub3d, file, idx + 1));
	if (file[idx][0] == 'E' && file[idx][1] == 'A')
		return (put_tex_filename(cub3d, file, idx, "EA"),
			file_info(cub3d, file, idx + 1));
	if (file[idx][0] == 'F' && file[idx][1] == ' ')
		return (put_colors(cub3d, file, idx, "F"),
			file_info(cub3d, file, idx + 1));
	if (file[idx][0] == 'C' && file[idx][1] == ' ')
		return (put_colors(cub3d, file, idx, "C"),
			file_info(cub3d, file, idx + 1));
	if (file[idx][0] == '\0')
		return (file_info(cub3d, file, idx + 1));
	else
		build_map(cub3d, file, idx);
}

char	**build_file(t_cub3d *cub3d, char **argv, int nb_line)
{
	int		fd;
	int		idx;
	char	**file;

	idx = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_cub3d_error(cub3d, "Map cannot be opened\n"), NULL);
	file = malloc (sizeof(char *) * (nb_line + 1));
	if (!file)
		return (close(fd),
			ft_cub3d_error(cub3d, "Malloc of file failed\n"), NULL);
	while (idx < nb_line)
	{
		file[idx] = get_next_line(fd);
		if (file[idx] == NULL)
			return (ft_free_map_char(file),
				ft_cub3d_error(cub3d, "Malloc failed"), NULL);
		if (file[idx][ft_strlen(file[idx]) - 1] == '\n')
			file[idx][ft_strlen(file[idx]) - 1] = '\0';
		idx++;
	}
	file[idx] = NULL;
	close (fd);
	return (file_info(cub3d, file, 0), file);
}
