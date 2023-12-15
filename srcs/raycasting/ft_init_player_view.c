/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player_view.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafy <orazafy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 19:53:05 by orazafy           #+#    #+#             */
/*   Updated: 2023/12/04 22:21:28 by orazafy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Function to initialize player's view facing north
void	ft_init_player_view_north(t_cub3d *cub3d)
{
	cub3d->raycast.dir_x = -1;
	cub3d->raycast.dir_y = 0;
	cub3d->raycast.plane_x = 0;
	cub3d->raycast.plane_y = 0.66;
}

// Function to initialize player's view facing south
void	ft_init_player_view_south(t_cub3d *cub3d)
{
	cub3d->raycast.dir_x = 1;
	cub3d->raycast.dir_y = 0;
	cub3d->raycast.plane_x = 0;
	cub3d->raycast.plane_y = -0.66;
}

// Function to initialize player's view facing east
void	ft_init_player_view_east(t_cub3d *cub3d)
{
	cub3d->raycast.dir_x = 0;
	cub3d->raycast.dir_y = 1;
	cub3d->raycast.plane_x = 0.66;
	cub3d->raycast.plane_y = 0;
}

// Function to initialize player's view facing west
void	ft_init_player_view_west(t_cub3d *cub3d)
{
	cub3d->raycast.dir_x = 0;
	cub3d->raycast.dir_y = -1;
	cub3d->raycast.plane_x = -0.66;
	cub3d->raycast.plane_y = 0;
}
