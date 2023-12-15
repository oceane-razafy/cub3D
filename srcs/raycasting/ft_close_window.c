/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:22:35 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/11 19:35:54 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function called to close window in order to free everything
// if error was detected before, exit with status 1
int	ft_close_window(t_cub3d *cub3d)
{
	int	is_error;

	is_error = 0;
	if (cub3d->is_error != 0)
		is_error = 1;
	if (cub3d->mlx_ptr != NULL && cub3d->image.ptr != NULL)
		mlx_destroy_image(cub3d->mlx_ptr, cub3d->image.ptr);
	ft_destroy_all_tex_img(cub3d, &cub3d->raycast);
	ft_free_all_tex_files(cub3d);
	if (cub3d->mlx_ptr != NULL && cub3d->mlx_win != NULL)
		mlx_destroy_window(cub3d->mlx_ptr, cub3d->mlx_win);
	if (cub3d->mlx_ptr != NULL)
		mlx_destroy_display(cub3d->mlx_ptr);
	if (cub3d->mlx_ptr != NULL)
		free(cub3d->mlx_ptr);
	ft_free_map_char(cub3d->file_info.map);
	ft_free_map_int(cub3d->raycast.map);
	if (is_error == 1)
		exit(1);
	exit(0);
}

// Function to destroy all textures images
void	ft_destroy_all_tex_img(t_cub3d *cub3d, t_raycast *raycast)
{
	ft_destroy_one_tex_img(cub3d, &raycast->no_tex_img);
	ft_destroy_one_tex_img(cub3d, &raycast->so_tex_img);
	ft_destroy_one_tex_img(cub3d, &raycast->we_tex_img);
	ft_destroy_one_tex_img(cub3d, &raycast->ea_tex_img);
}

// Function to destroy one specific texture image
void	ft_destroy_one_tex_img(t_cub3d *cub3d, t_tex_img *tex_img)
{
	if (cub3d->mlx_ptr != NULL && tex_img->ptr != NULL)
		mlx_destroy_image(cub3d->mlx_ptr, tex_img->ptr);
}

// Function to free all the texture filenames string
void	ft_free_all_tex_files(t_cub3d *cub3d)
{
	if (cub3d->file_info.no_tex_filename != NULL)
		free(cub3d->file_info.no_tex_filename);
	if (cub3d->file_info.so_tex_filename != NULL)
		free(cub3d->file_info.so_tex_filename);
	if (cub3d->file_info.we_tex_filename != NULL)
		free(cub3d->file_info.we_tex_filename);
	if (cub3d->file_info.ea_tex_filename != NULL)
		free(cub3d->file_info.ea_tex_filename);
}
