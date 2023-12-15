/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_drawing_param.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 21:51:03 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/04 21:57:39 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to initialize all the data needed to draw the entire image
int	ft_init_drawing_param(t_raycast *raycast)
{
	ft_get_current_tex_img(raycast);
	ft_compute_line_param(raycast);
	ft_get_wall_x(raycast);
	ft_get_tex_x(raycast);
	raycast->step = 1.0 * raycast->current_tex_img.height
		/ raycast->line_height;
	raycast->tex_pos = (raycast->start_point
			- W_HEIGHT / 2 + raycast->line_height / 2) * raycast->step;
	if (raycast->start_point < 0 || raycast->start_point > W_HEIGHT
		|| raycast->end_point < 0 || raycast->end_point > W_HEIGHT)
		return (-1);
	return (0);
}

// Function to get the right texture image (the current one needed)
void	ft_get_current_tex_img(t_raycast *raycast)
{
	if (raycast->side == 0 && raycast->step_x == -1)
		raycast->current_tex_img = raycast->so_tex_img;
	if (raycast->side == 0 && raycast->step_x == 1)
		raycast->current_tex_img = raycast->no_tex_img;
	if (raycast->side == 1 && raycast->step_y == -1)
		raycast->current_tex_img = raycast->ea_tex_img;
	if (raycast->side == 1 && raycast->step_y == 1)
		raycast->current_tex_img = raycast->we_tex_img;
}

// Function to compute line parameters:
// line height, line start point & end point
void	ft_compute_line_param(t_raycast *raycast)
{
	raycast->line_height = (int)(W_HEIGHT / raycast->perp_wall_dist);
	raycast->start_point = -raycast->line_height / 2 + W_HEIGHT / 2;
	if (raycast->start_point < 0)
		raycast->start_point = 0;
	raycast->end_point = raycast->line_height / 2 + W_HEIGHT / 2;
	if (raycast->end_point >= W_HEIGHT)
		raycast->end_point = W_HEIGHT - 1;
}

// Function to get the wall x-coordinate
void	ft_get_wall_x(t_raycast *raycast)
{
	if (raycast->side == 0)
		raycast->wall_x = raycast->player_y
			+ raycast->perp_wall_dist * raycast->ray_y;
	else
		raycast->wall_x = raycast->player_x
			+ raycast->perp_wall_dist * raycast->ray_x;
	raycast->wall_x -= floor((raycast->wall_x));
}

// Function to get the right x-coordinate of the texture
void	ft_get_tex_x(t_raycast *raycast)
{
	raycast->tex_x = (int)(raycast->wall_x
			* (double)(raycast->current_tex_img.width));
	if (raycast->side == 0 && raycast->ray_x > 0)
		raycast->tex_x = raycast->current_tex_img.width - raycast->tex_x - 1;
	if (raycast->side == 1 && raycast->ray_y < 0)
		raycast->tex_x = raycast->current_tex_img.width - raycast->tex_x - 1;
}
