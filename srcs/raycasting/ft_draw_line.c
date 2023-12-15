/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 23:34:17 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/13 12:51:20 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to draw the vertical line at the x-coordinate specified
void	ft_draw_line(t_cub3d *cub3d, int x)
{
	t_raycast	*raycast;

	raycast = &cub3d->raycast;
	if (ft_init_drawing_param(raycast) == -1)
		return ;
	ft_draw_floor_and_ceiling(x, cub3d);
	ft_draw_wall(x, cub3d, raycast);
}

// Function to draw the floor and ceiling with their respective colors
void	ft_draw_floor_and_ceiling(int x, t_cub3d *cub3d)
{
	int	y;

	y = 0;
	while (y <= cub3d->raycast.start_point)
	{
		ft_put_pixel(cub3d, x, y, cub3d->file_info.ceiling_color);
		y++;
	}
	y = cub3d->raycast.end_point;
	while (y <= W_HEIGHT)
	{
		ft_put_pixel(cub3d, x, y, cub3d->file_info.floor_color);
		y++;
	}
}

// Function to draw the wall (from start_point to end_point)
void	ft_draw_wall(int x, t_cub3d *cub3d, t_raycast *raycast)
{
	int	y;

	y = raycast->start_point;
	while (y <= raycast->end_point)
	{
		raycast->tex_y = (int)raycast->tex_pos
			% (raycast->current_tex_img.height - 1);
		raycast->tex_pos += raycast->step;
		raycast->color = ft_get_pixel(&raycast->current_tex_img,
				raycast->tex_x, raycast->tex_y);
		ft_put_pixel(cub3d, x, y, raycast->color);
		y++;
	}
}
