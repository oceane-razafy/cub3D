/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tex_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 00:21:08 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/15 02:24:55 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_get_tex_path(t_cub3d *cub3d, char *tex_file_var,
									char *tex_file, char **file)
{
	if (tex_file_var != NULL)
		return (ft_free_map_char(file), ft_cub3d_error(cub3d,
				"A texture file is mentioned more than once\n"), NULL);
	else
		return (ft_strdup(tex_file));
	return (NULL);
}
