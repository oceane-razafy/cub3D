/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:23:06 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/11 19:43:49 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to launch/relaunch the game (relaunch, when we move the player)
void	ft_launch_game(t_cub3d *cub3d)
{
	t_raycast	*raycast;
	int			x;

	raycast = &cub3d->raycast;
	x = 0;
	while (x < W_WIDTH)
	{
		ft_compute_ray_and_dir_position(raycast, x);
		raycast->map_x = (int)(raycast->player_x);
		raycast->map_y = (int)(raycast->player_y);
		ft_compute_delta_dist(raycast);
		ft_compute_step_and_side_dist(raycast);
		ft_launch_dda(raycast);
		if (raycast->side == 0)
			raycast->perp_wall_dist
				= (raycast->side_dist_x - raycast->delta_dist_x);
		else
			raycast->perp_wall_dist
				= (raycast->side_dist_y - raycast->delta_dist_y);
		if (raycast->perp_wall_dist == 0)
			raycast->perp_wall_dist = 1;
		ft_draw_line(cub3d, x);
		x++;
	}
}

// Function to compute the position of the ray and direction
// based on screen coordinates
void	ft_compute_ray_and_dir_position(t_raycast *raycast, int x)
{
	raycast->camera_x = 2 * x / (double)W_WIDTH - 1;
	raycast->ray_x = raycast->dir_x + raycast->plane_x * raycast->camera_x;
	raycast->ray_y = raycast->dir_y + raycast->plane_y * raycast->camera_x;
}

// Function to compute delta distances in the x and y directions
void	ft_compute_delta_dist(t_raycast *raycast)
{
	if (raycast->ray_x == 0)
		raycast->delta_dist_x = 1e30;
	else
		raycast->delta_dist_x = fabs(1 / raycast->ray_x);
	if (raycast->ray_y == 0)
		raycast->delta_dist_y = 1e30;
	else
		raycast->delta_dist_y = fabs(1 / raycast->ray_y);
}

// Function to get step direction and side distances based on ray direction
// so step size is in which direction are we gonna step (in x and y axis)
void	ft_compute_step_and_side_dist(t_raycast *raycast)
{
	if (raycast->ray_x < 0)
	{
		raycast->step_x = -1;
		raycast->side_dist_x
			= (raycast->player_x - raycast->map_x) * raycast->delta_dist_x;
	}
	else
	{
		raycast->step_x = 1;
		raycast->side_dist_x = (raycast->map_x + 1.0
				- raycast->player_x) * raycast->delta_dist_x;
	}
	if (raycast->ray_y < 0)
	{
		raycast->step_y = -1;
		raycast->side_dist_y
			= (raycast->player_y - raycast->map_y) * raycast->delta_dist_y;
	}
	else
	{
		raycast->step_y = 1;
		raycast->side_dist_y = (raycast->map_y + 1.0
				- raycast->player_y) * raycast->delta_dist_y;
	}
}

// Function to launch the Digital Differential Analyzer (DDA) algorithm
void	ft_launch_dda(t_raycast *raycast)
{
	raycast->hit = 0;
	while (raycast->hit == 0)
	{
		if (raycast->side_dist_x < raycast->side_dist_y)
		{
			raycast->side_dist_x += raycast->delta_dist_x;
			raycast->map_x += raycast->step_x;
			raycast->side = 0;
		}
		else
		{
			raycast->side_dist_y += raycast->delta_dist_y;
			raycast->map_y += raycast->step_y;
			raycast->side = 1;
		}
		if (raycast->map[raycast->map_x][raycast->map_y] > 0)
			raycast->hit = 1;
	}
}
