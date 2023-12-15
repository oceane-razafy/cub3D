/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_all_tex_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 20:50:14 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/11 00:43:01 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to initialize all textures images:
// no_tex_img, so_tex_img, we_tex_img, ea_tex_img
void	ft_init_all_tex_img(t_cub3d *cub3d, t_raycast *raycast)
{
	t_file_info	*file_info;
	t_tex_img	*no_tex_img;
	t_tex_img	*so_tex_img;
	t_tex_img	*we_tex_img;
	t_tex_img	*ea_tex_img;

	file_info = &cub3d->file_info;
	no_tex_img = &raycast->no_tex_img;
	so_tex_img = &raycast->so_tex_img;
	we_tex_img = &raycast->we_tex_img;
	ea_tex_img = &raycast->ea_tex_img;
	ft_init_one_tex_img(no_tex_img, cub3d, file_info->no_tex_filename);
	ft_init_one_tex_img(so_tex_img, cub3d, file_info->so_tex_filename);
	ft_init_one_tex_img(we_tex_img, cub3d, file_info->we_tex_filename);
	ft_init_one_tex_img(ea_tex_img, cub3d, file_info->ea_tex_filename);
}

// Function to initiliaze a specific texture image
void	ft_init_one_tex_img(t_tex_img *tex_img,
	t_cub3d *cub3d, char *tex_filename)
{
	tex_img->ptr = mlx_xpm_file_to_image(cub3d->mlx_ptr,
			tex_filename, &tex_img->width, &tex_img->height);
	if (tex_img->ptr == NULL)
		ft_cub3d_error(cub3d, "Initialization of a texture failed\n");
	tex_img->data = (int *)mlx_get_data_addr(
			tex_img->ptr, &tex_img->bpp, &tex_img->len, &tex_img->end);
	if (tex_img->data == NULL)
		ft_cub3d_error(cub3d, "Initialization of a texture failed\n");
}
