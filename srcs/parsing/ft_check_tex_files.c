/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tex_files.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 00:54:44 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/11 18:34:49 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to check if a texture file exists or is readable
void	ft_check_tex_files(t_cub3d *cub3d, t_file_info *file_info)
{
	int	fd_no;
	int	fd_so;
	int	fd_we;
	int	fd_ea;

	if (file_info->no_tex_filename == NULL
		|| file_info->so_tex_filename == NULL
		|| file_info->we_tex_filename == NULL
		|| file_info->ea_tex_filename == NULL)
		ft_cub3d_error(cub3d, "Impossible to read a texture file\n");
	fd_no = open(file_info->no_tex_filename, O_RDONLY);
	fd_so = open(file_info->so_tex_filename, O_RDONLY);
	fd_we = open(file_info->we_tex_filename, O_RDONLY);
	fd_ea = open(file_info->ea_tex_filename, O_RDONLY);
	if (fd_no == -1 || fd_so == -1 || fd_we == -1 || fd_ea == -1)
		ft_cub3d_error(cub3d, "Impossible to read a texture file\n");
	if (close(fd_no) == -1 || close (fd_so) == -1
		|| close (fd_we) == -1 || close (fd_ea) == -1)
		ft_cub3d_error(cub3d, "Impossible to close a texture file\n");
}
