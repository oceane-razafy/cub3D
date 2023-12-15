/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:27:10 by tbae              #+#    #+#             */
/*   Updated: 2023/12/13 13:07:02 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to initialize all the data needed for cub3d project
void	ft_init_all(t_cub3d *cub3d, char **argv)
{
	cub3d->is_error = 0;
	cub3d->file_info.ceiling_color = -1;
	cub3d->file_info.floor_color = -1;
	ft_init_all_ptr(cub3d);
	scan_file(cub3d, argv);
	ft_check_tex_files(cub3d, &cub3d->file_info);
	ft_init_window_and_image(cub3d);
	ft_init_raycasting(cub3d);
}

// Function to initialize to NULL all the pointers
// that will be freed later on
void	ft_init_all_ptr(t_cub3d *cub3d)
{
	cub3d->image.ptr = NULL;
	cub3d->file_info.map_filename = NULL;
	cub3d->file_info.no_tex_filename = NULL;
	cub3d->file_info.so_tex_filename = NULL;
	cub3d->file_info.we_tex_filename = NULL;
	cub3d->file_info.ea_tex_filename = NULL;
	cub3d->file_info.map = NULL;
	cub3d->mlx_ptr = NULL;
	cub3d->mlx_win = NULL;
	cub3d->raycast.map = NULL;
	cub3d->raycast.no_tex_img.ptr = NULL;
	cub3d->raycast.so_tex_img.ptr = NULL;
	cub3d->raycast.we_tex_img.ptr = NULL;
	cub3d->raycast.ea_tex_img.ptr = NULL;
	cub3d->raycast.current_tex_img.ptr = NULL;
}

// Function to initialize the window and image
void	ft_init_window_and_image(t_cub3d *cub3d)
{
	t_image	*img;

	cub3d->mlx_ptr = mlx_init();
	if (cub3d->mlx_ptr == NULL)
		ft_cub3d_error(cub3d, "Initialization of mlx_ptr failed\n");
	cub3d->mlx_win = mlx_new_window(cub3d->mlx_ptr, W_WIDTH, W_HEIGHT, "cub3d");
	if (cub3d->mlx_win == NULL)
		ft_cub3d_error(cub3d, "Initialization of mlx_win failed\n");
	cub3d->image.ptr = mlx_new_image(cub3d->mlx_ptr, W_WIDTH, W_HEIGHT);
	if (cub3d->image.ptr == NULL)
		ft_cub3d_error(cub3d, "Initialization of image.ptr failed\n");
	img = &cub3d->image;
	cub3d->image.data = (char *)mlx_get_data_addr(
			cub3d->image.ptr, &img->bpp, &img->len, &img->end);
	if (cub3d->image.data == NULL)
		ft_cub3d_error(cub3d, "Initialization of image.data failed\n");
}

// Function to init all raycasting parameters
void	ft_init_raycasting(t_cub3d *cub3d)
{
	cub3d->raycast.player_x = cub3d->file_info.player_x + 0.5;
	cub3d->raycast.player_y = cub3d->file_info.player_y + 0.5;
	if (cub3d->file_info.player_view == north)
		ft_init_player_view_north(cub3d);
	if (cub3d->file_info.player_view == south)
		ft_init_player_view_south(cub3d);
	if (cub3d->file_info.player_view == west)
		ft_init_player_view_west(cub3d);
	if (cub3d->file_info.player_view == east)
		ft_init_player_view_east(cub3d);
	cub3d->raycast.movement_speed = 0.45;
	cub3d->raycast.rotation_speed = 0.45;
	ft_init_all_tex_img(cub3d, &cub3d->raycast);
	cub3d->raycast.map = malloc(
			sizeof(int *) * (cub3d->file_info.nb_line + 1));
	if (cub3d->raycast.map == NULL)
		ft_cub3d_error(cub3d, "Malloc of raycast.map failed\n");
	cub3d->raycast.map = ft_convert_map_char_to_int(cub3d,
			cub3d->raycast.map, cub3d->file_info.map);
	cub3d->file_info.map = NULL;
}

// Function to convert the char map into an int map
// from file_info struct to raycast struct
int	**ft_convert_map_char_to_int(t_cub3d *cub3d, int **map_int, char **map_char)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < cub3d->file_info.nb_line)
	{
		j = 0;
		map_int[i] = malloc(sizeof(int ) * (ft_strlen(
						map_char[i])));
		if (map_int[i] == NULL)
			ft_cub3d_error(cub3d, "Malloc of map_int[i] failed\n");
		while (map_char[i][j] != '\0')
		{
			map_int[i][j] = map_char[i][j] - '0';
			if (map_int[i][j] != 1 && map_int[i][j] != 0)
				map_int[i][j] = 0;
			j++;
		}
		i++;
	}
	map_int[i] = NULL;
	ft_free_map_char(map_char);
	return (map_int);
}
