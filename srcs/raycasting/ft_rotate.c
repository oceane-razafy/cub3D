/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 22:29:15 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/04 22:29:17 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to rotate the player's view to the right
void	ft_rotate_right(t_raycast *raycast)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = raycast->dir_x;
	raycast->dir_x = raycast->dir_x * cos(-raycast->rotation_speed)
		- raycast->dir_y * sin(-raycast->rotation_speed);
	raycast->dir_y = olddir_x * sin(-raycast->rotation_speed)
		+ raycast->dir_y * cos(-raycast->rotation_speed);
	oldplane_x = raycast->plane_x;
	raycast->plane_x = raycast->plane_x * cos(-raycast->rotation_speed)
		- raycast->plane_y * sin(-raycast->rotation_speed);
	raycast->plane_y = oldplane_x * sin(-raycast->rotation_speed)
		+ raycast->plane_y * cos(-raycast->rotation_speed);
}

// Function to rotate the player's view to the left
void	ft_rotate_left(t_raycast *raycast)
{
	double	olddir_x;
	double	oldplane_x;

	olddir_x = raycast->dir_x;
	raycast->dir_x = raycast->dir_x * cos(raycast->rotation_speed)
		- raycast->dir_y * sin(raycast->rotation_speed);
	raycast->dir_y = olddir_x * sin(raycast->rotation_speed)
		+ raycast->dir_y * cos(raycast->rotation_speed);
	oldplane_x = raycast->plane_x;
	raycast->plane_x = raycast->plane_x * cos(raycast->rotation_speed)
		- raycast->plane_y * sin(raycast->rotation_speed);
	raycast->plane_y = oldplane_x * sin(raycast->rotation_speed)
		+ raycast->plane_y * cos(raycast->rotation_speed);
}
